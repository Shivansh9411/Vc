#include <stdexcept>
#include <cstdlib>
/*  This file is part of the Vc library. {{{
Copyright © 2011-2015 Matthias Kretz <kretz@kde.org>

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#include <Vc/cpuid.h>
#include <Vc/global.h>

namespace Vc_VERSIONED_NAMESPACE
{

CpuId::uint   CpuId::s_ecx0 = 0;
CpuId::uint   CpuId::s_logicalProcessors = 0;
CpuId::uint   CpuId::s_processorFeaturesC = 0;
CpuId::uint   CpuId::s_processorFeaturesD = 0;
CpuId::uint   CpuId::s_processorFeatures7B = 0;
CpuId::uint   CpuId::s_processorFeatures7C = 0;
CpuId::uint   CpuId::s_processorFeatures8C = 0;
CpuId::uint   CpuId::s_processorFeatures8D = 0;
CpuId::uint   CpuId::s_L1Instruction = 0;
CpuId::uint   CpuId::s_L1Data = 0;
CpuId::uint   CpuId::s_L2Data = 0;
CpuId::uint   CpuId::s_L3Data = 0;
CpuId::ushort CpuId::s_L1InstructionLineSize = 0;
CpuId::ushort CpuId::s_L1DataLineSize = 0;
CpuId::ushort CpuId::s_L2DataLineSize = 0;
CpuId::ushort CpuId::s_L3DataLineSize = 0;
CpuId::uint   CpuId::s_L1Associativity = 0;
CpuId::uint   CpuId::s_L2Associativity = 0;
CpuId::uint   CpuId::s_L3Associativity = 0;
CpuId::ushort CpuId::s_prefetch = 32; // The Intel ORM says that if Vc_CPUID(2) doesn't set the prefetch size it is 32
CpuId::uchar  CpuId::s_brandIndex = 0;
CpuId::uchar  CpuId::s_cacheLineSize = 0;
CpuId::uchar  CpuId::s_processorModel = 0;
CpuId::uchar  CpuId::s_processorFamily = 0;
CpuId::ProcessorType CpuId::s_processorType = CpuId::IntelReserved;
bool   CpuId::s_noL2orL3 = false;

#ifdef _WIN32

}
// better not include intrin.h inside the Vc namespace :)
#include <intrin.h>
namespace Vc_VERSIONED_NAMESPACE
{

#define Vc_CPUID(leaf) \
    do { \
        int out[4]; \
        __cpuid(out, leaf); \
        eax = out[0]; \
        ebx = out[1]; \
        ecx = out[2]; \
        edx = out[3]; \
    } while (false)
#define Vc_CPUID_C(leaf, ecx_)                                                           \
    do {                                                                                 \
        int out[4];                                                                      \
        __cpuidex(out, leaf, ecx_);                                                      \
        eax = out[0];                                                                    \
        ebx = out[1];                                                                    \
        ecx = out[2];                                                                    \
        edx = out[3];                                                                    \
    } while (false)
#elif defined(__i386__) && defined(__PIC__)
// %ebx may be the PIC register.
static inline void _Vc_cpuid(int leaf, unsigned int &eax, unsigned int &ebx, unsigned int &ecx, unsigned int &edx)
{
    int tmpb;
    asm("mov %%ebx, %[tmpb]\n\t"
        "cpuid\n\t"
        "mov %%ebx, %[ebx]\n\t"
        "mov %[tmpb], %%ebx\n\t"
        : [tmpb]"=m"(tmpb), "=a"(eax), [ebx] "=m"(ebx), "+c"(ecx), "=d"(edx)
        : [leaf] "a"(leaf)
      );
}
#define Vc_CPUID(leaf) \
    ecx = 0; \
    _Vc_cpuid(leaf, eax, ebx, ecx, edx)
#define Vc_CPUID_C(leaf, ecx_)                                                           \
    ecx = ecx_;                                                                          \
    _Vc_cpuid(leaf, eax, ebx, ecx, edx)
#else
#define Vc_CPUID(leaf) \
    __asm__("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(leaf))
#define Vc_CPUID_C(leaf, ecx_)                                                           \
    __asm__("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(leaf), "c"(ecx_))
#endif
static unsigned int CpuIdAmdAssociativityTable(int bits)
{
    __builtin_trap() /* STUB: not implemented */;
}

void CpuId::init()
{
    __builtin_trap() /* STUB: not implemented */;
}

void CpuId::interpret(uchar byte, bool *checkLeaf4)
{
    __builtin_trap() /* STUB: not implemented */;
}

}

// vim: sw=4 sts=4 et tw=100
