#include "redis_mgr.h"

msRedisMgr::msRedisMgr(const Char *host, Int32 port, Int32 timeout)
    : m_Redis(credis_connect(host, port, timeout))
{
    if (m_Redis)
    {
        m_RedisCode = credis_info(m_Redis, &m_RedisInfo);
    }

}

msRedisMgr::~msRedisMgr()
{
    credis_close(m_Redis);
    m_Redis = nullptr;
}