#include <iostream>
#include "credis.h"
#include "ms_base.h"
#include "redis_mgr.h"
#include "logic_production_line.h"
#include "SyncQueue.hpp"

//class CreateGuildLPL : msLPL
//{
//    virtual void Do()
//    {
//
//    }
//};
//
//
//class CreateGuildLPL : msLPL
//{
//    virtual void Do()
//    {
//
//    }
//};

#define FASE_DEF_TASK_LPL(__class_name__) friend class __class_name__; \
class __class_name__ : public msLPL\
{\
public:\
    __class_name__(msGuildMgr* xGuildMgr):m_GuildMgr(xGuildMgr)\
    {\
    }\
    virtual bool _Do()\
    {\
        return (bool)Do(m_GuildMgr);\
    }\
    virtual void OnInvoke()\
    {\
        m_GuildMgr->AddTask(this);\
    }\
    Boolean Do(msGuildMgr* xGuildMgr);\
private:\
msGuildMgr* m_GuildMgr;\
}

class msGuildMgr : msRedisMgr
{
public:
    msGuildMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msGuildMgr();
    void Shutdown();

    // 公会基础功能
    FASE_DEF_TASK_LPL(CreateGuildLPL)       m_CreateGuild;          // 创建公会
    FASE_DEF_TASK_LPL(DisbandGuild)         m_DisbandGuild;         // 解散公会
    FASE_DEF_TASK_LPL(JoinGuild)            m_JoinGuild;            // 申请加入公会
    FASE_DEF_TASK_LPL(InviteGuild)          m_InviteGuild;          // 邀请加入公会
    FASE_DEF_TASK_LPL(GetGuildBaseInfo)     m_GetGuildBaseInfo;     // 获取公会基础信息
    FASE_DEF_TASK_LPL(GetGuildLeaguerList)  m_GetGuildLeaguerList;  // 获取公会成员列表
    FASE_DEF_TASK_LPL(GetGuildNotice)       m_GetGuildNotice;       // 获取公会公告
    FASE_DEF_TASK_LPL(SetGuildNotice)       m_SetGuildNotice;       // 设置公会公告
    FASE_DEF_TASK_LPL(SaveGuild)            m_SaveGuild;            // 申请公会存盘

    void LogicCheckTick(Int32 xExeNum = 100);  // 逻辑线程处理
    Boolean IsBusy();
    // 任务相关
private:
    void AddTask(msLPL*);
    msLPL* m_DoingLPL = nullptr;
    SyncQueue<msLPL*> m_TaskQueue;
    SyncQueue<std::function<void(void)>> m_CompleteTaskQueue;
protected:
private:
    Int64   m_GuildId;
    mstr    m_GuildName;
    Int64   m_CreateTime;

    // 线程相关
private:
    Boolean m_StopTaskThread = False;
    std::thread m_TaskThread;
    void TaskThreadCB();   // 任务线程回调
};

