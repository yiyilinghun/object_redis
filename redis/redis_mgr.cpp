#include "PCH.h"
#include "redis_mgr.h"

msRedisMgr::msRedisMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout, const Char *xPassword)
    : m_Host(xHost), m_Port(xPort)
{
    // 创建链接
    m_Redis = credis_connect(xHost, xPort, xTimeout);
    if (m_Redis)
    {
        msAssertLog("连接Redis[%s:%d]成功!", xHost, xPort);
    }
    else
    {
        msAssertLog("连接Redis[%s:%d(%d)]失败!", m_Host.c_str(), m_Port, m_DBIndex);
        throw "Redis错误";
        return;
    }

    // 检查密码
    if (xPassword)
    {
        if (this->LoginAuth(xPassword))
        {
            msAssertLog("认证Redis[%s:%d]通过!", m_Host.c_str(), m_Port);
        }
        else
        {
            msAssertLog("认证Redis[%s:%d]失败!", m_Host.c_str(), m_Port);
            throw "Redis错误";
            return;
        }
    }

    // 读取服务信息
    m_RedisCode = credis_info(m_Redis, &m_RedisInfo);

    // 选择默认数据库
    if (this->SelectDB(xDBIndex))
    {
    }
    else
    {
        msAssertLog("更换[%d]号数据库失败Redis[%s:%d]!", m_DBIndex, m_Host.c_str(), m_Port);
        throw "Redis错误";
        return;
    }
}

msRedisMgr::~msRedisMgr()
{
    credis_close(m_Redis);
    m_Redis = nullptr;
}

Boolean msRedisMgr::LoginAuth(const char *password)
{
    m_RedisCode = credis_auth(m_Redis, password);
    return m_RedisCode == 0;
}

Boolean msRedisMgr::SelectDB(Int32 xDBIndex)
{
    if (m_DBIndex == xDBIndex)
    {
        msAssertLog("正在使用Redis[%d]号数据库[%s:%d]!", m_DBIndex, m_Host.c_str(), m_Port);
        return True;
    }
    else
    {
        m_RedisCode = credis_select(m_Redis, xDBIndex);
        if (m_RedisCode == 0)
        {
            m_DBIndex = xDBIndex;
            msAssertLog("开始使用Redis[%d]号数据库[%s:%d]!", m_DBIndex, m_Host.c_str(), m_Port);
            return True;
        }
        else
        {
            msAssertLog("切换到Redis[%d]号数据库失败[%s:%d][%d]!", xDBIndex, m_Host.c_str(), m_Port, m_RedisCode);
            return False;
        }
    }

    //if ()
    //{
    //    m_DBIndex = xDBIndex;
    //}
    //
    //SET db_number 0
}

Int32 msRedisMgr::GetSize(mstr xKey)
{
    return credis_llen(m_Redis, xKey.c_str());
}

Int32 msRedisMgr::HashSetList(mstr xHashName, msRedisMulKV& xKVs)
{
    return HashSetList(xHashName, xKVs.m_Keys, xKVs.m_Values);
}

Int32 msRedisMgr::HashSetList(mstr xHashName, std::vector<mstr>& xKeys, std::vector<mstr>& xValues)
{
    mstr xBuff = msStrAssist::format("HMSET %s", xHashName.c_str());
    if (xKeys.size() != xValues.size())
    {
        msAssertLog("xKeys.size() != xValues.size()");
        return -1;
    }
    for (TSIZE i = 0; i < xKeys.size(); i++)
    {
        xBuff += " " + xKeys[i];
        xBuff += R"( ")" + xValues[i] + R"(")";
    }

    xBuff += "\r\n";
    return credis_send(m_Redis, CR_INLINE, xBuff.c_str());

}

Int32 msRedisMgr::HashSet(mstr xHashName, mstr xKey, mstr xValue)
{
    return credis_hset(m_Redis, xHashName.c_str(), xKey.c_str(), xValue.c_str());
}

Boolean msRedisMgr::HashGet(mstr xHashName, mstr xKey, mstr &xValue)
{
    char* pValue;
    if (credis_hget(m_Redis, xHashName.c_str(), xKey.c_str(), &pValue) >= 0)
    {
        xValue = pValue;
        return True;
    }
    else
    {
        return False;
    }
}
