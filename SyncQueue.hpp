#ifndef __SYNCQUEUE_H__
#define __SYNCQUEUE_H__

#include "ms_base.h"

template<typename T>
class SyncQueue
{
public:
    SyncQueue(Int32 maxSize = 81920)
        : m_maxSize(maxSize)
        // , m_needStop(False)
    {
        ;
    }

    void Put(const T&x)
    {
        Add(x);
    }

    void Put(T&& x)
    {
        Add(std::forward<T>(x));
    }

    Boolean Take()
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        if (m_queue.size() > 0)
        {
            m_queue.pop_front();
            return True;
        }
        else
        {
            return False;
        }
    }

    void Take(std::list<T>& list)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //m_notEmpty.wait(locker, [this] {return m_needStop || NotEmpty(); });
        // if (m_needStop) { return; }

        list = std::move(m_queue);
        //m_notFull.notify_one();
    }

    Boolean Take(T& t)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });
        // if (m_needStop) { return False; }
        if (m_queue.size() > 0)
        {
            t = m_queue.front();
            m_queue.pop_front();
            //m_notFull.notify_one();
            return True;
        }
        else
        {
            return False;
        }
    }

    Boolean Peek(T& t)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });
        // if (m_needStop) { return False; }
        if (m_queue.size() > 0)
        {
            t = m_queue.front();
            //m_notFull.notify_one();
            return True;
        }
        else
        {
            return False;
        }
    }

    void Stop()
    {
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            // m_needStop = True;
        }
        //m_notFull.notify_all();
        //m_notEmpty.notify_all();
    }

    Boolean Empty()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    Boolean Full()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    Int32 Count()
    {
        return (Int32)m_queue.size();
    }

private:
    Boolean NotFull()const
    {
        Boolean full = m_queue.size() >= m_maxSize;
        return !full;
    }

    Boolean NotEmpty()const
    {
        Boolean empty = m_queue.empty();
        return !empty;
    }

    template<typename F>
    void Add(F&& x)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //m_notFull.wait(locker, [this] {return m_needStop || NotFull(); });
        // if (m_needStop) { return; }

        m_queue.push_back(std::forward<F>(x));
        //m_notEmpty.notify_one();
    }


private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    //std::condition_variable m_notEmpty;
    //std::condition_variable m_notFull;

    Int32 m_maxSize;
    // Boolean m_needStop;
};






#endif // __SYNCQUEUE_H__
