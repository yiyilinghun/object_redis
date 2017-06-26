#include "redis_mgr.h"

msRedisMgr::msRedisMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout)
    : m_Host(xHost)
    , m_Port(xPort)
    , m_Redis(credis_connect(xHost, xPort, xTimeout))
{
    if (m_Redis)
    {
        m_RedisCode = credis_info(m_Redis, &m_RedisInfo);
        msAssertLog("连接Redis[%s:%d]成功!", xHost, xPort);
        this->SelectDB(xDBIndex);
    }
    else
    {
        Char* szBuff = ALLOCA_CH(200);
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
        msAssertLog("Redis数据库已经在[%s:%d(%d)]!", m_Host.c_str(), m_Port, m_DBIndex);
    }
    else
    {
        m_RedisCode = credis_select(m_Redis, xDBIndex);
        if (m_RedisCode == 0)
        {
            m_DBIndex = xDBIndex;
            msAssertLog("使用Redis[%s:%d(%d)]数据库!", m_Host.c_str(), m_Port, m_DBIndex);
        }
        else
        {
            msAssertLog("切换到Redis数据库[%s:%d(%d)]失败[%d]!", m_Host.c_str(), m_Port, m_DBIndex, m_RedisCode);
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
