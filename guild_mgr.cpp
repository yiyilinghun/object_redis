#include "guild_mgr.h"

msGuildMgr::msGuildMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout, const Char *xPassword)
    : msRedisMgr(xHost, xPort, xDBIndex, xTimeout, xPassword)
{
    m_GuildId = 100;
    m_GuildName = u8"测试公会";
    m_CreateTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

msGuildMgr::~msGuildMgr()
{
    ;
}


Boolean msGuildMgr::SaveGuild()
{
    msRedisMulKV xKVs;

    msTimer xTimer;

    xKVs.PushKV(u8"GuildName", m_GuildName);
    xKVs.PushKV(u8"CreateTime", std::to_string(m_CreateTime));
    for (int i = 0; i < 1000; i++)
    {
        xKVs.PushKV(std::to_string(i), std::to_string(i*i));
    }
    this->HashSetList(u8"Guild:KV" + m_GuildName, xKVs);
    msAssertLog("耗时%lld毫秒,%lld微妙", xTimer.elapsed(), xTimer.elapsed_micro());


    this->HashSet(u8"Guild:" + m_GuildName, u8"GuildName", m_GuildName);
    this->HashSet(u8"Guild:" + m_GuildName, u8"CreateTime", std::to_string(m_CreateTime));

    return True;
}
