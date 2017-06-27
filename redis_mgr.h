#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"

class msRedisMgr
{
public:
    msRedisMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msRedisMgr();

    Boolean SelectDB(Int32 xDBIndex = 0);
    Int32 GetSize(mstr xKey);
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

