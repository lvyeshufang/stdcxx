////////////////////////////////////////////////////////////////////////////
//
// atomic-ia64-32.s
//
// $Id: atomic-ia64.s 225375 2005-07-26 19:04:10Z sebor $
//
////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1994-2005 Quovadx,  Inc., acting through its  Rogue Wave
// Software division. Licensed under the Apache License, Version 2.0 (the
// "License");  you may  not use this file except  in compliance with the
// License.    You    may   obtain   a   copy   of    the   License    at
// http://www.apache.org/licenses/LICENSE-2.0.    Unless   required    by
// applicable law  or agreed to  in writing,  software  distributed under
// the License is distributed on an "AS IS" BASIS,  WITHOUT WARRANTIES OR
// CONDITIONS OF  ANY KIND, either  express or implied.  See  the License
// for the specific language governing permissions  and limitations under
// the License.
//
////////////////////////////////////////////////////////////////////////////

        .text
        //.pred.safe_across_calls p1-p5,p16-p63
	.psr abi32 
        .psr msb

////////////////////////////////////////////////////////////////////////////
// extern "C" char __rw_atomic_xchg8 (char *x, char y);
//
// Atomically assigns the 8-bit value y to *x and returns
// the original (before assignment) 8-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_xchg8#
        .proc   __rw_atomic_xchg8#

__rw_atomic_xchg8:

        .prologue
        .body
        // .mfb
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        xchg1 r8 = [r9], r33
        nop 0
        br.ret.sptk.many b0

        .endp __rw_atomic_xchg8#

////////////////////////////////////////////////////////////////////////////
// extern "C" char __rw_atomic_add8 (char *x, int y);
//
// Atomically increments the 8-bit value *x by y and returns
// the new (after increment) 8-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_add8#
        .proc   __rw_atomic_add8#

__rw_atomic_add8:

        .prologue
        .body
         // .mmb
        mf
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        ld1.acq r15 = [r9]
        nop 0
        ;;
.add8_busywait:
         // .mmi
        mov ar.ccv = r15
        add r8 = r15, r33
        mov r2 = r15
        ;;
         // .mmb
        nop 0
        cmpxchg1.acq r15 = [r9], r8, ar.ccv
        nop 0
        ;;
         // .mbb
        cmp.ne p8, p9 = r2, r15
        (p9) br.ret.dpnt.many rp
        br .add8_busywait

        .endp __rw_atomic_add8#

////////////////////////////////////////////////////////////////////////////
// extern "C" short __rw_atomic_xchg16 (short *x, short y);
//
// Atomically assigns the 16-bit value y to *x and returns
// the original (before assignment) 16-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_xchg16#
        .proc   __rw_atomic_xchg16#

__rw_atomic_xchg16:

        .prologue
        .body
        // .mfb
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        xchg2 r8 = [r9], r33
        nop 0
        br.ret.sptk.many b0

        .endp __rw_atomic_xchg16#

////////////////////////////////////////////////////////////////////////////
// extern "C" short __rw_atomic_add16 (short *x, short y);
//
// Atomically increments the 16-bit value *x by y and returns
// the new (after increment) 16-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_add16#
        .proc   __rw_atomic_add16#

__rw_atomic_add16:

        .prologue
        .body
         // .mmb
        mf
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        ld2.acq r15 = [r9]
        nop 0
        ;;
.add16_busywait:
         // .mmi
        mov ar.ccv = r15
        add r8 = r15, r33
        mov r2 = r15
        ;;
         // .mmb
        nop 0
        cmpxchg2.acq r15 = [r9], r8, ar.ccv
        nop 0
        ;;
         // .mbb
        cmp.ne p8, p9 = r2, r15
        (p9) br.ret.dpnt.many rp
        br .add16_busywait

        .endp __rw_atomic_add16#

////////////////////////////////////////////////////////////////////////////
// extern "C" int __rw_atomic_xchg32 (int *x, int y);
//
// Atomically assigns the 32-bit value y to *x and returns
// the original (before assignment) 32-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_xchg32#
        .proc   __rw_atomic_xchg32#

__rw_atomic_xchg32:

        .prologue
        .body
        // .mfb

	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        xchg4 r8 = [r9], r33
        nop 0
        br.ret.sptk.many b0

        .endp __rw_atomic_xchg32#

////////////////////////////////////////////////////////////////////////////
// extern "C" int __rw_atomic_add32 (int *x, int y);
//
// Atomically increments the 32-bit value *x by y and returns
// the new (after increment) 32-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_add32#
        .proc   __rw_atomic_add32#

__rw_atomic_add32:

        .prologue
        .body
         // .mmb
        mf
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
	;;
        ld4.acq r15 = [r9]
        nop 0
        ;;
.add32_busywait:
         // .mmi
        mov ar.ccv = r15
        add r8 = r15, r33
        mov r2 = r15
        ;;
         // .mmb
        nop 0
        cmpxchg4.acq r15 = [r9], r8, ar.ccv
        nop 0
        ;;
         // .mbb
        cmp4.ne p8, p9 = r2, r15
        (p9) br.ret.dpnt.many rp
        br .add32_busywait

        .endp __rw_atomic_add32#

////////////////////////////////////////////////////////////////////////////
// extern "C" int64_t __rw_atomic_xchg64 (int64_t *x, int64_t y);
//
// Atomically assigns the 64-bit value y to *x and returns
// the original (before assignment) 64-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_xchg64#
        .proc   __rw_atomic_xchg64#

__rw_atomic_xchg64:

        .prologue
        .body
        // .mfb

	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
        ;;
        xchg8 r8 = [r9], r33
        nop 0
        br.ret.sptk.many b0

        .endp __rw_atomic_xchg64#

////////////////////////////////////////////////////////////////////////////
// extern "C" int64_t __rw_atomic_add64 (int64_t *x, int64_t y);
//
// Atomically increments the 16-bit value *x by y and returns
// the new (after increment) 16-bit value of *x.
////////////////////////////////////////////////////////////////////////////

        .global __rw_atomic_add64#
        .proc   __rw_atomic_add64#

__rw_atomic_add64:

        .prologue
        .body
         // .mmb
        mf
	addp4 r9 = 0, r32 // Needed to be able to dereference a 32 bit pointer
        ;;
        ld8.acq r15 = [r9]
        nop 0
        ;;
.add64_busywait:
         // .mmi
        mov ar.ccv = r15
        add r8 = r15, r33
        mov r2 = r15
        ;;
         // .mmb
        nop 0
        cmpxchg8.acq r15 = [r9], r8, ar.ccv
        nop 0
        ;;
         // .mbb
        cmp.ne p8, p9 = r2, r15
        (p9) br.ret.dpnt.many rp
        br .add64_busywait

        .endp __rw_atomic_add64#
