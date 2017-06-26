#include <iostream>
#include <future>

#include "redis_mgr.h"

int main(int argc, char **argv)
{
    try
    {
        msRedisMgr xRedisMgr("192.168.4.161", 6379, 0, 10000, "redis_pass");

        xRedisMgr.SelectDB(0);
        xRedisMgr.SelectDB(1);
        xRedisMgr.SelectDB(2);
        xRedisMgr.SelectDB(3);
        xRedisMgr.SelectDB(4);
        xRedisMgr.SelectDB(100);

        xRedisMgr.SelectDB(0);
        msAssertLog("查询Redis[%s]长度为[%d]!", "tk_list_8", xRedisMgr.GetSize("tk_list_8"));


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
