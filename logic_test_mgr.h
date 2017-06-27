#include <iostream>
#include "redis/credis.h"
#include "ms_base.h"
#include "redis_mgr.h"

class msLogicTestMgr : msRedisMgr
{
public:
    msLogicTestMgr(const Char *xHost = "127.0.0.1", Int32 xPort = 6379, Int32 xDBIndex = 0, Int32 xTimeout = 10000, const Char *xPassword = nullptr);
    ~msLogicTestMgr();

protected:
private:
};

