#include "guild_mgr.h"

msGuildMgr::msGuildMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout, const Char *xPassword)
    : msRedisMgr(xHost, xPort, xDBIndex, xTimeout, xPassword), m_TaskThread(&msGuildMgr::TaskThreadCB, this), m_CreateGuild(this), m_DisbandGuild(this), m_JoinGuild(this), m_InviteGuild(this), m_GetGuildBaseInfo(this), m_GetGuildLeaguerList(this), m_GetGuildNotice(this), m_SetGuildNotice(this), m_SaveGuild(this)
{
    m_GuildId = 100;
    m_GuildName = U8("测试公会");
    var x = msStrAssist::u82m(m_GuildName);
    m_CreateTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

msGuildMgr::~msGuildMgr()
{
    ;
}

void msGuildMgr::Shutdown()
{
    m_StopTaskThread = True;
    m_TaskThread.join();
}

void msGuildMgr::AddTask(msLPL *xLPL)
{
    std::vector<mstr> xVec;
    if (xLPL->m_Params.Peek(xVec))
    {
        msAssertLog("%s->Put", xVec[0].c_str());
        m_TaskQueue.Put(xLPL);
    }
}

//Boolean msGuildMgr::SaveGuild()
Boolean msGuildMgr::CreateGuildLPL::Do(msGuildMgr *xGuildMgr)
{
    msRedisMulKV xKVs;

    msTimer xTimer;

    xKVs.PushKV(U8("GuildName"), xGuildMgr->m_GuildName);
    xKVs.PushKV(U8("CreateTime"), std::to_string(xGuildMgr->m_CreateTime));
    for (int i = 0; i < 10; i++)
    {
        xKVs.PushKV(std::to_string(i), std::to_string(i * i));
    }
    xGuildMgr->HashSetList(U8("Guild:KV") + xGuildMgr->m_GuildName, xKVs);
    msAssertLog("耗时%lld毫秒,%lld微妙", xTimer.elapsed(), xTimer.elapsed_micro());

    xGuildMgr->HashSet(U8("Guild:") + xGuildMgr->m_GuildName, U8("GuildName"), xGuildMgr->m_GuildName);
    xGuildMgr->HashSet(U8("Guild:") + xGuildMgr->m_GuildName, U8("CreateTime"), std::to_string(xGuildMgr->m_CreateTime));

    return True;
}

Boolean msGuildMgr::DisbandGuild::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::JoinGuild::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::InviteGuild::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::GetGuildBaseInfo::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::GetGuildLeaguerList::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::GetGuildNotice::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::SetGuildNotice::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

Boolean msGuildMgr::SaveGuild::Do(msGuildMgr *xGuildMgr)
{
    return False;
}

// 逻辑线程处理
void msGuildMgr::LogicCheckTick(Int32 xExeNum)
{
    std::function<void(void)> xFun;
    for (Int32 i = 0; i < xExeNum; i++)
    {
        if (m_CompleteTaskQueue.Take(xFun))
        {
            xFun();
        }
        else
        {
            break;
        }
    }
}

// 逻辑线程回调
void msGuildMgr::TaskThreadCB()
{
    while (!m_StopTaskThread)
    {
        if (m_TaskQueue.Take(m_DoingLPL))
        {
            if (m_DoingLPL)
            {
                if (m_DoingLPL->_Do())
                {
                    std::vector<mstr> xVec;
                    if (m_DoingLPL->m_Params.Peek(xVec))
                    {
                        msAssertLog("%s->m_CompleteTaskQueuePut_OnSucceed", xVec[0].c_str());
                        std::function<void(void)> xFun;
                        if (m_DoingLPL->m_OnSucceed.Peek(xFun))
                        {
                            m_CompleteTaskQueue.Put(xFun);
                        }
                    }
                }
                else
                {
                    std::vector<mstr> xVec;
                    if (m_DoingLPL->m_Params.Peek(xVec))
                    {
                        msAssertLog("%s->m_CompleteTaskQueuePut_Onfailed", xVec[0].c_str());
                        std::function<void(void)> xFun;
                        if (m_DoingLPL->m_Onfailed.Peek(xFun))
                        {
                            m_CompleteTaskQueue.Put(xFun);
                        }
                    }
                }
                m_DoingLPL->m_OnSucceed.Take();
                m_DoingLPL->m_Onfailed.Take();
                m_DoingLPL->m_Params.Take();
                m_DoingLPL = nullptr;
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

Boolean msGuildMgr::IsBusy()
{
    return m_DoingLPL || m_TaskQueue.Count() > 0 || m_CompleteTaskQueue.Count() > 0;
}
