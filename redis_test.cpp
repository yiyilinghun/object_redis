#include <iostream>
#include <future>

#include "redis_mgr.h"

int main(int argc, char **argv)
{
    msRedisMgr xRedisMgr("192.168.4.161", 6379, 10000);
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
