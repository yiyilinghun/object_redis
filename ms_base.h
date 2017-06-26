#include <iostream>
#include <ratio>
#include <chrono>
#include <iomanip>

#include <stdarg.h>

typedef char Char;
typedef unsigned char Byte;

typedef signed short Int16;
typedef unsigned short Unt16;

typedef signed int Int32;
typedef unsigned int Unt32;

#ifdef WIN
typedef signed __int64 Int64;
typedef unsigned __int64 Unt64;
#else
typedef signed long long Int64;
typedef unsigned long long Unt64;
#endif

typedef Int32 Boolean;
#define True 1
#define False 0

typedef float Single;
typedef double Double;

typedef Unt16 WORD;
typedef Unt32 DWORD;
typedef Unt64 QWORD;

typedef void *IntPtr;

typedef std::wstring wstr;
typedef std::string mstr;
typedef std::string u8str;

#define ALLOCA_CH(size) (Char *)alloca(size)

//无效的ID值
#define INVALID_LID (Int64) - 1
#define INVALID_QID (QWORD) - 1
#define INVALID_NID -1
#define INVALID_UID (DWORD) - 1
#define INVALID_WID (WORD) - 1
#define INVALID_BID (Byte) - 1
#define INVALID_KEY (LPVOID) - 1
#define INVALID_VALUE (-1)
#define INVALID_DVALUE (DWORD)(-1)
#define INVALID_PTR (IntPtr)(-1)

#define msAssertLog(str, ...) ((_AssertLog(__FILE__, __LINE__, __FUNCTION__, "", str, __VA_ARGS__)))
inline void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...)
{
    std::time_t xNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm *tmTime = std::localtime(&xNow);
    //std::cout << std::put_time(std::localtime(&xNow), "%F %R") << std::endl;
    //struct tm *tmTime = gmtime(&xNow);

    Char szBuff[1024];
    sprintf(szBuff,
            "\n"
            "time:[%02d-%02d-%02d %02d:%02d:%02d]file:[%s(%d)] func:[%s(%s)]"
            "\n"
            "info:[%s]"
            "\n",
            1900 + tmTime->tm_year, tmTime->tm_mon + 1, tmTime->tm_mday, tmTime->tm_hour, tmTime->tm_min, tmTime->tm_sec,
            file, line, func, expr, info);

    va_list ap;
    va_start(ap, info);
    mstr xLogBuff;
    xLogBuff.resize(4096);
    vsprintf((Char *)xLogBuff.data(), szBuff, ap);
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