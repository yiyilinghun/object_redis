#include "redis_mgr.h"

msRedisMgr::msRedisMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout)
    : m_Host(xHost), m_Port(xPort), m_Redis(credis_connect(xHost, xPort, xTimeout))
{
    if (m_Redis)
    {
        m_RedisCode = credis_info(m_Redis, &m_RedisInfo);
        msAssertLog("连接Redis[%s:%d]成功!", xHost, xPort);
        this->SelectDB(xDBIndex);
    }
    else
    {
        Char *szBuff = ALLOCA_CH(200);
        msAssertLog(szBuff, "连接Redis[%s:%d(%d)]失败!", m_Host.c_str(), m_Port, m_DBIndex);
        throw szBuff;
    }
}

msRedisMgr::~msRedisMgr()
{
    credis_close(m_Redis);
    m_Redis = nullptr;
}

Boolean msRedisMgr::SelectDB(Int32 xDBIndex)
{
    if (m_DBIndex == xDBIndex)
    {
        msAssertLog("正在使用Redis[%d]号数据库[%s:%d]!", m_DBIndex, m_Host.c_str(), m_Port);
    }
    else
    {
        m_RedisCode = credis_select(m_Redis, xDBIndex);
        if (m_RedisCode == 0)
        {
            m_DBIndex = xDBIndex;
            msAssertLog("开始使用Redis[%d]号数据库[%s:%d]!", m_DBIndex, m_Host.c_str(), m_Port);
        }
        else
        {
            msAssertLog("切换到Redis[%d]号数据库失败[%s:%d][%d]!", xDBIndex, m_Host.c_str(), m_Port, m_RedisCode);
        }
    }

    return True;
    //if ()
    //{
    //    m_DBIndex = xDBIndex;
    //}
    //
    //SET db_number 0
}
