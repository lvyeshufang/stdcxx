// -*- C++ -*-
/***************************************************************************
 *
 * _forward - forward/move helpers for <utility> header
 *
 * This is an internal header file used to implement the C++ Standard
 * Library. It should never be #included directly by a program.
 *
 * $Id$
 *
 ***************************************************************************
 *
 * Licensed to the Apache Software  Foundation (ASF) under one or more
 * contributor  license agreements.  See  the NOTICE  file distributed
 * with  this  work  for  additional information  regarding  copyright
 * ownership.   The ASF  licenses this  file to  you under  the Apache
 * License, Version  2.0 (the  "License"); you may  not use  this file
 * except in  compliance with the License.   You may obtain  a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the  License is distributed on an  "AS IS" BASIS,
 * WITHOUT  WARRANTIES OR CONDITIONS  OF ANY  KIND, either  express or
 * implied.   See  the License  for  the  specific language  governing
 * permissions and limitations under the License.
 *
 * Copyright 2008 Rogue Wave Software, Inc.
 * 
 **************************************************************************/

#ifndef _RWSTD_RW_FORWARD_INCLUDED
#  define _RWSTD_RW_FORWARD_INCLUDED

#  include <rw/_defs.h>

#  if !defined _RWSTD_NO_EXT_CXX_0X

#    include <rw/_meta_ref.h>   // for __rw_remove_reference


_RWSTD_NAMESPACE (std) {


// 20.2.2, forward/move helpers:

template <class _Type>
struct identity
{
    typedef _Type type;

    const _Type& operator() (const _Type& __x) const {
        return __x;
    }
};

#    define _RWSTD_IDENTITY(_Type)          _STD::identity<_Type>::type


#    if !defined _RWSTD_NO_RVALUE_REFERENCES

template <class _Type>
inline _Type&&
forward (_TYPENAME identity<_Type>::type&& __x)
{
    return __x;
}


template <class _Type>
inline _TYPENAME _RWSTD_REMOVE_REFERENCE(_Type)&&
move (_Type&& __x)
{
    return __x;
}

#      define _RWSTD_FORWARD(_Type, __x)    _STD::forward<_Type> (__x)
#      define _RWSTD_MOVE(__x)              _STD::move (__x)

#    else   // no rvalue references

#      define _RWSTD_FORWARD(_Type, __x)    (__x)
#      define _RWSTD_MOVE(__x)              (__x)

#    endif   // !defined _RWSTD_NO_RVALUE_REFERENCES


}   // namespace std


#  endif   // !defined _RWSTD_NO_EXT_CXX_0X

#endif   // _RWSTD_RW_FORWARD_INCLUDED