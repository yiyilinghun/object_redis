#include <iostream>

typedef char                Char;
typedef unsigned char       Byte;

typedef signed short        Int16;
typedef unsigned short      Unt16;

typedef signed int          Int32;
typedef unsigned int        Unt32;

#ifdef WIN
typedef signed __int64      Int64;
typedef unsigned __int64    Unt64;
#else
typedef signed long long    Int64;  
typedef unsigned long long  Unt64;
#endif

typedef Int32               Boolean;
#define True                1
#define False               0

typedef float               Single;
typedef double              Double;

typedef Unt16               WORD;
typedef Unt32               DWORD;
typedef Unt64               QWORD;

typedef void*               IntPtr;

typedef std::wstring    wstr;
typedef std::string     mstr;
typedef std::string     u8str;

#define ALLOCA_CH(size) (Char*)alloca(size)
