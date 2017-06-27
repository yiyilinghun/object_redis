#ifndef __MS_BASE_H__
#define __MS_BASE_H__

#include <codecvt>
#include <string>
#include <iostream>
#include <future>
#include <ratio>
#include <chrono>
#include <iomanip>

#include <stdarg.h>

typedef char Char;
typedef unsigned char Byte;

typedef signed short Int16;
typedef unsigned short Unt16;

typedef signed int Int32;
typedef unsigned int Unt32;

#ifdef WIN
typedef signed __int64 Int64;
typedef unsigned __int64 Unt64;
#else
typedef signed long long Int64;
typedef unsigned long long Unt64;
#endif

typedef Int32 Boolean;
#define True 1
#define False 0

typedef float Single;
typedef double Double;

typedef Unt16 WORD;
typedef Unt32 DWORD;
typedef Unt64 QWORD;

typedef void *IntPtr;

typedef std::wstring wstr;
typedef std::string mstr;
typedef std::string u8str;

#define ALLOCA_CH(size) (Char *)alloca(size)

//无效的ID值
#define INVALID_LID         (Int64)(-1)
#define INVALID_QID         (QWORD)(-1)
#define INVALID_NID         (-1)
#define INVALID_UID         (DWORD)(-1)
#define INVALID_WID         (WORD)(-1)
#define INVALID_BID         (Byte)(-1)
#define INVALID_KEY         (LPVOID)(-1)
#define INVALID_VALUE       (-1)
#define INVALID_DVALUE      (DWORD)(-1)
#define INVALID_PTR         (IntPtr)(-1)

#define msAssertLog(str, ...) ((_AssertLog(__FILE__, __LINE__, __FUNCTION__, "", str, __VA_ARGS__)))
void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...);

class msStrAssist
{
public:
    static mstr format(const char *xFormat, ...)
    {
        mstr xBuff;
        xBuff.resize(1024 * 10);
        va_list ap;
        va_start(ap, xFormat);
        int xRealLen = vsprintf((char*)xBuff.data(), xFormat, ap);
        xBuff.resize(xRealLen);
        va_end(ap);
        return xBuff;
    }

    static mstr m2u8(mstr& xMstr)
    {
        //if (std::codecvt_base::ok == res)
        //{
        //    std::wstring_convert<std::codecvt_utf8<char>> cutf8;
        //    return cutf8.to_bytes(std::wstring(buff.data(), pwszNext));
        //}
        //std::codecvt_utf8
        //mstr xBuff;
        //xBuff.resize(sizeof(xT));
        //*((T*)(xBuff.data())) = xT;
        return xMstr;
    }

    static mstr u82m(mstr& xU8str)
    {
        //mstr xBuff;
        //xBuff.resize(sizeof(xT));
        //*((T*)(xBuff.data())) = xT;
        return xU8str;
    }

    template <typename T>
    static mstr CreateStringByType(T& xT)
    {
        mstr xBuff;
        xBuff.resize(sizeof(xT));
        *((T*)(xBuff.data())) = xT;
        return xBuff;
    }

    template <typename T>
    static void CreateStringByType(mstr& xStr, T& xT)
    {
        xStr.resize(sizeof(xT));
        *((T*)(xStr.data())) = xT;
    }

    template <typename T>
    static T CreateTypeByString(mstr& xStr)
    {
        T xT;
        if (xStr.size() == sizeof(xT))
        {
            xT = *((T*)(xBuff.data()));
        }
        return xT;
    }

    template <typename T>
    static void CreateTypeByString(T& xT, mstr& xStr)
    {
        if (xStr.size() == sizeof(xT))
        {
            xT = *((T*)(xBuff.data()));
        }
    }
};

class msTimer
{
public:
    msTimer() { reset(); }

    void reset() { m_Begin = std::chrono::high_resolution_clock::now(); }

    // 默认输出毫秒
    template<typename Duration = std::chrono::milliseconds>
    Int64 elapsed()const { return std::chrono::duration_cast<Duration>(std::chrono::high_resolution_clock::now() - m_Begin).count(); }

    // 微妙
    Int64 elapsed_micro()const { return elapsed<std::chrono::microseconds>(); }

    // 纳秒
    Int64 elapsed_nano()const { return elapsed<std::chrono::nanoseconds>(); }

    // 秒
    Int64 elapsed_seconds()const { return elapsed<std::chrono::seconds>(); }

    // 分
    Int64 elapsed_minutes()const { return elapsed<std::chrono::minutes>(); }

    // 时
    Int64 elapsed_hours()const { return elapsed<std::chrono::hours>(); }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_Begin;
};

#endif  // __MS_BASE_H__
