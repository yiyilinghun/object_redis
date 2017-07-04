#ifndef __REDIS_MGR_H__
#define __REDIS_MGR_H__

#include "ms_base.h"
#include "credis.h"

struct msRedisMulKV
{
    Int32 PushKV(mstr xKey, mstr xValue)
    {
        if (m_Keys.size() == m_Values.size())
        {
            m_Keys.push_back(xKey);
            m_Values.push_back(xValue);
        }
        else
        {
            msAssertLog("m_Keys.size() != m_Values.size()");
        }
        return (Int32)m_Keys.size();
    }
    std::vector<mstr> m_Keys;
    std::vector<mstr> m_Values;
};

class msRedisMgr
{
public:
    msRedisMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msRedisMgr();

    Boolean SelectDB(Int32 xDBIndex = 0);
    Int32 GetSize(mstr xKey);

    Int32 HashSetList(mstr xHashName, msRedisMulKV& xKVs);
    Int32 HashSetList(mstr xHashName, std::vector<mstr>& xKeys, std::vector<mstr>& xValues);
    Int32 HashSet(mstr xHashName, mstr xKey, mstr xValue);
    Boolean HashGet(mstr xHashName, mstr xKey, mstr &xValue);

protected:
private:
    Boolean LoginAuth(const Char *password);

    // Redis 连接
    REDIS m_Redis = nullptr;

    // Redis 信息
    REDIS_INFO m_RedisInfo;

    // Redis 返回码
    Int32 m_RedisCode;

    // Redis Host
    mstr m_Host;

    // Redis Port
    Int32 m_Port;

    // Redis DBIndex
    Int32 m_DBIndex = INVALID_NID;
};

#endif  // __REDIS_MGR_H__
