#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"
#include "redis_mgr.h"

class msGuildMgr : msRedisMgr
{
public:
    msGuildMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msGuildMgr();

    Boolean SaveGuild();
protected:
private:
    Int64   m_GuildId;
    mstr    m_GuildName;
    Int64   m_CreateTime;


};

