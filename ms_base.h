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
#define INVALID_LID         (Int64)(-1)
#define INVALID_QID         (QWORD)(-1)
#define INVALID_NID         (-1)
#define INVALID_UID         (DWORD)(-1)
#define INVALID_WID         (WORD)(-1)
#define INVALID_BID         (Byte)(-1)
#define INVALID_KEY         (LPVOID)(-1)
#define INVALID_VALUE       (-1)
#define INVALID_DVALUE      (DWORD)(-1)
#define INVALID_PTR         (IntPtr)(-1)

#define msAssertLog(str, ...) ((_AssertLog(__FILE__, __LINE__, __FUNCTION__, "", str, __VA_ARGS__)))
void _AssertLog(const Char *file, DWORD line, const Char *func, const Char *expr, const Char *info, ...);
