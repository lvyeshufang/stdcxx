/************************************************************************
 *
 * rwthread.h - declarations for testsuite thread helpers
 *
 * $Id$
 *
 ************************************************************************
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

#ifndef RW_RWTHREAD_H_INCLUDED
#define RW_RWTHREAD_H_INCLUDED

#include <testdefs.h>


extern "C" {

struct rw_thread_attr_t;

struct rw_thread_t
{
    long  threadno;
    long  id;
    void* handle;
};


_TEST_EXPORT int
rw_thread_create (rw_thread_t*,
                  rw_thread_attr_t*,
                  void* (*)(void*),
                  void*);


_TEST_EXPORT int
rw_thread_join (rw_thread_t, void**);


_TEST_EXPORT int
rw_thread_pool (rw_thread_t*, _RWSTD_SIZE_T,
                rw_thread_attr_t*,
                void* (*)(void*),
                void**);

}   // extern "C"

#endif   // RW_RWTHREAD_H_INCLUDED
