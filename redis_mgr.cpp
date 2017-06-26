#include "redis_mgr.h"

msRedisMgr::msRedisMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout)
    : m_Redis(credis_connect(xHost, xPort, xTimeout))
    , m_DBIndex(xDBIndex)
{
    if (m_Redis)
    {
        m_RedisCode = credis_info(m_Redis, &m_RedisInfo);
        printf("连接Redis[%s:%d(%d)]成功!", xHost, xPort, m_DBIndex);
    }
    else
    {
        Char* szBuff = ALLOCA_CH(200);
        sprintf(szBuff, "连接Redis[%s:%d(%d)]失败!", xHost, xPort, m_DBIndex);
        printf(szBuff);
        throw szBuff;
    }
}

msRedisMgr::~msRedisMgr()
{
    credis_close(m_Redis);
    m_Redis = nullptr;
}
