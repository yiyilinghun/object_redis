#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"
#include "redis_mgr.h"

class msGuildMgr : msRedisMgr
{
public:
    msGuildMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msGuildMgr();

    // 公会基础功能
    Boolean asyn_CreateGuild();             // 创建公会
    Boolean asyn_DisbandGuild();            // 解散公会
    Boolean asyn_JoinGuild();               // 申请加入公会
    Boolean asyn_InviteGuild();             // 邀请加入公会
    Boolean asyn_GetGuildBaseInfo();        // 获取公会基础信息
    Boolean asyn_GetGuildLeaguerList();     // 获取公会成员列表
    Boolean asyn_GetGuildNotice();          // 获取公会公告
    Boolean asyn_SetGuildNotice();          // 设置公会公告

    Boolean CreateGuild();                  // 创建公会
    Boolean DisbandGuild();                 // 解散公会
    Boolean JoinGuild();                    // 申请加入公会
    Boolean InviteGuild();                  // 邀请加入公会
    Boolean GetGuildBaseInfo();             // 获取公会基础信息
    Boolean GetGuildLeaguerList();          // 获取公会成员列表
    Boolean GetGuildNotice();               // 获取公会公告
    Boolean SetGuildNotice();               // 设置公会公告




    Boolean SaveGuild();                    // 申请公会存盘
protected:
private:
    Int64   m_GuildId;
    mstr    m_GuildName;
    Int64   m_CreateTime;
};

