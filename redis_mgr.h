#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"

class msRedisMgr
{
public:
    msRedisMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000);
    ~msRedisMgr();

protected:
private:

    // Redis 连接
    REDIS m_Redis = nullptr;

    // Redis 信息
    REDIS_INFO m_RedisInfo;

    // Redis 返回码
    Int32 m_RedisCode;

    // Redis DBIndex
    Int32 m_DBIndex;

    //char *val, **valv, lstr[50000];
    //const char *keyv[] = { "kalle", "adam", "unknown", "bertil", "none" };
    //int rc, keyc = 5, i;
    //double score1, score2;

    //redis = credis_connect("192.168.4.161", 6379, 10000);
    //if (redis == NULL) {
    //    printf("Error connecting to Redis server. Please start server to run tests.\n");
    //    exit(1);
    //}
};
