#include "ms_base.h"

void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...)
{
    std::time_t xNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm *tmTime = std::localtime(&xNow);

    mstr xLogBaseBuff;
    xLogBaseBuff.resize(1024);
    sprintf((Char*)xLogBaseBuff.data(),
        "\n"
        "time:[%04d-%02d-%02d %02d:%02d:%02d]file:[%s(%d)] func:[%s(%s)+]"
        "\n"
        "info:[%s]"
        "\n",
        1900 + tmTime->tm_year, tmTime->tm_mon + 1, tmTime->tm_mday, tmTime->tm_hour, tmTime->tm_min, tmTime->tm_sec,
        file, line, func, expr, info);

    va_list ap;
    va_start(ap, info);
    mstr xLogBuff;
    xLogBuff.resize(4096);
    vsprintf((Char*)xLogBuff.data(), (Char*)xLogBaseBuff.data(), ap);
    va_end(ap);
    std::cout << xLogBuff.data();

    //Char* szBuff = ALLOCA_CH(200);
    //sprintf(szBuff, "连接Redis[%s:%d(%d)]失败!\n", xHost, xPort, m_DBIndex);

    //SYSTEMTIME st;
    //CURRENT_LOCALTIME(st);
    //CHAR szBaseFormat[ASSERTX_STR_MAX_LEN] = { 0 };
    //CHAR szAsserMessage[ASSERTX_STR_MAX_LEN] = { 0 };
    //_snprintf_s(szBaseFormat, sizeof(szBaseFormat),
    //    "\n"
    //    "time:[%02d-%02d-%02d %02d:%02d:%02d.%03d]file:[%s(%d)] func:[%s(%s)]"
    //    "\n"
    //    "info:[%s]"
    //    "\n",
    //    st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
    //    file, line, func, expr, info);

    //va_list ap;
    //va_start(ap, info);
    //vsprintf_s(szAsserMessage, szBaseFormat, ap);
    //va_end(ap);
    //AsserMessage(eLevel, szAsserMessage);
    //if (eLevel > AL_SHOWMSG)
    //{
    //    try
    //    {
    //        throw(expr);
    //    }
    //    catch (...)
    //    {

    //    }
    //}
}