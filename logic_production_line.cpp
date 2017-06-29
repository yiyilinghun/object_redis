#include "logic_production_line.h"


msLogicProductionLine::msLogicProductionLine(
    std::function<void(void)>& xOnBefore,
    std::function<bool(void)>& xOnCheck,
    std::function<void(void)>& xOnSucceed,
    std::function<void(void)>& xOnfailed,
    std::function<void(void)>& xOnAfter)
    : m_OnBefore(xOnBefore)
    , m_OnCheck(xOnCheck)
    , m_OnSucceed(xOnAfter)
    , m_Onfailed(xOnAfter)
    , m_OnAfter(xOnAfter)
{

}

msLogicProductionLine::~msLogicProductionLine()
{

}
