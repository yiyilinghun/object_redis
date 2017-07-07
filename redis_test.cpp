#include "redis_mgr.h"
#include "guild_mgr.h"

int main(int argc, char **argv)
{
    try
    {
        //int a = 0xF0F0F0F0;
        //int b = 0x0F0F0F0F;
        //int c = a^b;
        //msRedisMgr xRedisMgr("192.168.4.161", 6379, 0, 10000, "redis_pass");
        msGuildMgr xGuildMgr("192.168.4.161", 6379, 0, 10000, nullptr);

        //xRedisMgr.SelectDB(0);
        //xRedisMgr.SelectDB(1);
        //xRedisMgr.SelectDB(2);
        //xRedisMgr.SelectDB(3);
        //xRedisMgr.SelectDB(4);
        //xRedisMgr.SelectDB(100);

        //xRedisMgr.SelectDB(1);
        //msAssertLog("查询Redis[%s]长度为[%d]!", "tk_list_8", xRedisMgr.GetSize("tk_list_8"));
        while (true)
        {
            if (xGuildMgr.m_CreateGuild.m_Onfailed.Count() < 1000)
            {
                for (Int32 i = 0; i < 1000; i++)
                {
                    msAssertLog("%d->Ask", i);
                    xGuildMgr.m_CreateGuild.Invoke(
                        [=]() {msAssertLog("%d->OnSucceed", i); }, // OnSucceed
                        [=]() {msAssertLog("%d->Onfailed", i); },  // Onfailed
                        std::to_string(i)
                    );
                }
            }
            else
            {
                msAssertLog("%d->Wait", xGuildMgr.m_CreateGuild.m_Onfailed.Count());
                xGuildMgr.LogicCheckTick();
                //std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
        }

        //while (xGuildMgr.IsBusy())
        //{
        //    xGuildMgr.LogicCheckTick();
        //}

        msTimer xTimer;

        //xGuildMgr.SaveGuild();

        xGuildMgr.Shutdown();
        //for (Int32 i = 0; i < 1000000; i++)
        //{
        //    xRedisMgr.HashSet("abc", std::to_string(i), std::to_string(i + 100000));
        //}
        //msAssertLog("插入10000耗时%lld秒,%lld微妙", xTimer.elapsed_seconds(), xTimer.elapsed_micro());

        //xTimer.reset();
        //for (Int32 i = 0; i < 1000000; i++)
        //{
        //    mstr xValue;
        //    xRedisMgr.HashGet("abc", std::to_string(i), xValue);
        //    //msAssertLog("测试RedisHash[%s]!", xValue.c_str());
        //}
        //msAssertLog("读取10000耗时%lld秒,%lld微妙", xTimer.elapsed_seconds(), xTimer.elapsed_micro());

        //say_hello();

        //auto f1 = std::async(std::launch::async, []() {
        //    say_hello();
        //    //return pthread_self();
        //    return 1;
        //});

        //printf("%d\n", f1.get());

        char x;
        int xRet = scanf("%c", &x);
        return 1;
    }
    catch (...)
    {
        char x;
        int xRet = scanf("%c", &x);
        return -1;
    }
}
