#include "PCH.h"
#include "ms_base.h"

void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...)
{
    std::time_t xNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm *tmTime = std::localtime(&xNow);

    mstr xLogBaseBuff;
    xLogBaseBuff.resize(1024);
    sprintf((Char*)xLogBaseBuff.data(),
        "\n"
        "time:[%04d-%02d-%02d %02d:%02d:%02d]file:[%s(%lu)] func:[%s(%s)+]"
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

    //std::cout << xLogBuff.data();
}