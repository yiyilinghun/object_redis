#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"

class msRedisMgr
{
public:
    msRedisMgr(const Char *host = "127.0.0.1", Int32 port = 6379, Int32 timeout = 10000);
    ~msRedisMgr();

protected:
private:

    // Redis ����
    REDIS m_Redis = nullptr;

    // Redis ��Ϣ
    REDIS_INFO m_RedisInfo;

    // Redis ������
    Int32 m_RedisCode;

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
