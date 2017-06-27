#include "logic_test_mgr.h"

msLogicTestMgr::msLogicTestMgr(const Char *xHost, Int32 xPort, Int32 xDBIndex, Int32 xTimeout, const Char *xPassword)
    : msRedisMgr(xHost, xPort, xDBIndex, xTimeout, xPassword)
{
    ;
}

msLogicTestMgr::~msLogicTestMgr()
{
    ;
}

