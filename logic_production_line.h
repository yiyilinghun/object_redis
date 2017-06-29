#ifndef __LOGIC_PRODUCTION_LINE_H__
#define __LOGIC_PRODUCTION_LINE_H__
#include <functional>

class msLogicProductionLine
{
public:
    msLogicProductionLine(
        std::function<void(void)>& xOnBefore,
        std::function<bool(void)>& xOnCheck,
        std::function<void(void)>& xOnSucceed,
        std::function<void(void)>& xOnfailed,
        std::function<void(void)>& xOnAfter
    );
    ~msLogicProductionLine();

private:
    std::function<void(void)> m_OnBefore;       // 执行之前的事件处理
    std::function<bool(void)> m_OnCheck;        // 检查继续条件的回调
    std::function<void(void)> m_OnSucceed;      // 执行成功的回调处理
    std::function<void(void)> m_Onfailed;       // 执行失败的回调处理
    std::function<void(void)> m_OnAfter;        // 执行结束的事件处理
};

#endif
