// checking for wint_t in <wchar.h> and <wctype.h>

#if defined (_RWSTD_USE_CONFIG)
#  include "config.h"
#endif   // _RWSTD_USE_CONFIG

#ifndef _RWSTD_NO_WCHAR_H
#  include <wchar.h>
#endif   // _RWSTD_NO_WCHAR_H

#ifndef _RWSTD_NO_WCTYPE_H
#  include <wctype.h>
#endif

#include <stdio.h>


const char* foo (char)               { return "char"; }
const char* foo (signed char)        { return "signed char"; }
const char* foo (unsigned char)      { return "unsigned char"; }
const char* foo (short)              { return "short"; }
const char* foo (unsigned short)     { return "unsigned short"; }
const char* foo (int)                { return "int"; }
const char* foo (unsigned int)       { return "unsigned int"; }
const char* foo (long)               { return "long"; }
const char* foo (unsigned long)      { return "unsigned long"; }

#ifndef _RWSTD_NO_LONG_LONG

const char* foo (long long)          { return "long long"; }
const char* foo (unsigned long long) { return "unsigned long long"; }

#endif   // _RWSTD_NO_LONG_LONG


int main ()
{
#if !defined (_RWSTD_USE_CONFIG)

    printf ("#undef _RWSTD_WINT_T\n");

#endif   // _RWSTD_USE_CONFIG

    wint_t wi = 0;

    printf ("#define _RWSTD_WINT_T %s\n", foo (wi));

    return 0;
}
