#ifndef __LOGIC_PRODUCTION_LINE_H__
#define __LOGIC_PRODUCTION_LINE_H__
#include "ms_base.h"

class msRedisMgr;
typedef class msLogicProductionLine
{
public:
    virtual bool _Do() = 0;
    virtual void OnInvoke() = 0;
    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed)
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        m_Params.push(xParams);
        this->OnInvoke();
    }


    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        m_Params.push(xParams);
        this->OnInvoke();
    }


    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9, mstr p10
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        xParams.push_back(p10);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9, mstr p10, mstr p11
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        xParams.push_back(p10);
        xParams.push_back(p11);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9, mstr p10, mstr p11, mstr p12
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        xParams.push_back(p10);
        xParams.push_back(p11);
        xParams.push_back(p12);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9, mstr p10, mstr p11, mstr p12, mstr p13
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        xParams.push_back(p10);
        xParams.push_back(p11);
        xParams.push_back(p12);
        xParams.push_back(p13);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    void Invoke(std::function<void(void)> xOnSucceed, std::function<void(void)> xOnfailed,
        mstr p1, mstr p2, mstr p3, mstr p4, mstr p5, mstr p6, mstr p7, mstr p8, mstr p9, mstr p10, mstr p11, mstr p12, mstr p13, mstr p14
    )
    {
        m_OnSucceed.push(xOnSucceed);
        m_Onfailed.push(xOnfailed);
        std::vector<mstr> xParams;
        xParams.push_back(p1);
        xParams.push_back(p2);
        xParams.push_back(p3);
        xParams.push_back(p4);
        xParams.push_back(p5);
        xParams.push_back(p6);
        xParams.push_back(p7);
        xParams.push_back(p8);
        xParams.push_back(p9);
        xParams.push_back(p10);
        xParams.push_back(p11);
        xParams.push_back(p12);
        xParams.push_back(p13);
        xParams.push_back(p14);
        m_Params.push(xParams);
        this->OnInvoke();
    }

    std::queue<std::function<void(void)>> m_OnSucceed;  // 任务成功
    std::queue<std::function<void(void)>> m_Onfailed;   // 任务失败
    std::queue<std::vector<mstr>> m_Params;
} msLPL;

#endif

