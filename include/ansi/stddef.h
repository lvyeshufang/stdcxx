/***************************************************************************
 *
 * stddef.h
 *
 * $Id: //stdlib/dev/include/ansi/stddef.h#11 $
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-2005 Quovadx,  Inc., acting through its  Rogue Wave
 * Software division. Licensed under the Apache License, Version 2.0 (the
 * "License");  you may  not use this file except  in compliance with the
 * License.    You    may   obtain   a   copy   of    the   License    at
 * http://www.apache.org/licenses/LICENSE-2.0.    Unless   required    by
 * applicable law  or agreed to  in writing,  software  distributed under
 * the License is distributed on an "AS IS" BASIS,  WITHOUT WARRANTIES OR
 * CONDITIONS OF  ANY KIND, either  express or implied.  See  the License
 * for the specific language governing permissions  and limitations under
 * the License.
 * 
 **************************************************************************/

#include <rw/_defs.h>

#ifndef _RWSTD_NO_DEPRECATED_C_HEADERS
#  ifndef _RWSTD_STDDEF_H_INCLUDED
#    define _RWSTD_STDDEF_H_INCLUDED

#    include <cstddef>

#    ifndef _RWSTD_NO_NAMESPACE

using std::ptrdiff_t;
using std::size_t;

#    endif   // _RWSTD_NO_NAMESPACE
#  endif   // _RWSTD_STDDEF_H_INCLUDED
#else
#  include _RWSTD_ANSI_C_STDDEF_H
#endif   // _RWSTD_STDDEF_H_INCLUDED
