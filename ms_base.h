#include <iostream>

typedef char                Char;
typedef unsigned char       Byte;

typedef signed short        Int16;
typedef unsigned short      Unt16;

typedef signed int          Int32;
typedef unsigned int        Unt32;

typedef signed __int64      Int64;
typedef unsigned __int64    Unt64;

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
