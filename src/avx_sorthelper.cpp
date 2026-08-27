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

#include <Vc/avx/vector.h>
#include <Vc/avx/debug.h>
#include <Vc/avx/macros.h>

namespace Vc_VERSIONED_NAMESPACE
{
namespace Detail
{
#ifdef Vc_IMPL_AVX2
template <>
Vc_CONST AVX2::short_v sorted<CurrentImplementation::current()>(AVX2::short_v x_)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
Vc_CONST AVX2::ushort_v sorted<CurrentImplementation::current()>(AVX2::ushort_v x_)
{ __builtin_trap() /* STUB: not implemented */; }

template <> Vc_CONST AVX2::int_v sorted<CurrentImplementation::current()>(AVX2::int_v x_)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
Vc_CONST AVX2::uint_v sorted<CurrentImplementation::current()>(AVX2::uint_v x_)
{ __builtin_trap() /* STUB: not implemented */; }
#endif  // AVX2

template <>
Vc_CONST AVX2::float_v sorted<CurrentImplementation::current()>(AVX2::float_v x_)
{ __builtin_trap() /* STUB: not implemented */; }

#if 0
template<> void SortHelper<double>::sort(__m256d &Vc_RESTRICT x, __m256d &Vc_RESTRICT y)
{
    __m256d l = _mm256_min_pd(x, y); // ↓x3y3 ↓x2y2 ↓x1y1 ↓x0y0
    __m256d h = _mm256_max_pd(x, y); // ↑x3y3 ↑x2y2 ↑x1y1 ↑x0y0
    x = _mm256_unpacklo_pd(l, h); // ↑x2y2 ↓x2y2 ↑x0y0 ↓x0y0
    y = _mm256_unpackhi_pd(l, h); // ↑x3y3 ↓x3y3 ↑x1y1 ↓x1y1
    l = _mm256_min_pd(x, y); // ↓(↑x2y2,↑x3y3) ↓x3x2y3y2 ↓(↑x0y0,↑x1y1) ↓x1x0y1y0
    h = _mm256_max_pd(x, y); // ↑x3x2y3y2 ↑(↓x2y2,↓x3y3) ↑x1x0y1y0 ↑(↓x0y0,↓x1y1)
    x = _mm256_unpacklo_pd(l, h); // ↑(↓x2y2,↓x3y3) ↓x3x2y3y2 ↑(↓x0y0,↓x1y1) ↓x1x0y1y0
    y = _mm256_unpackhi_pd(h, l); // ↓(↑x2y2,↑x3y3) ↑x3x2y3y2 ↓(↑x0y0,↑x1y1) ↑x1x0y1y0
    l = _mm256_min_pd(x, y); // ↓(↑(↓x2y2,↓x3y3) ↓(↑x2y2,↑x3y3)) ↓x3x2y3y2 ↓(↑(↓x0y0,↓x1y1) ↓(↑x0y0,↑x1y1)) ↓x1x0y1y0
    h = _mm256_max_pd(x, y); // ↑(↑(↓x2y2,↓x3y3) ↓(↑x2y2,↑x3y3)) ↑x3x2y3y2 ↑(↑(↓x0y0,↓x1y1) ↓(↑x0y0,↑x1y1)) ↑x1x0y1y0
    __m256d a = Reg::permute<X2, X3, X1, X0>(Reg::permute128<X0, X1>(h, h)); // h0 h1 h3 h2
    __m256d b = Reg::permute<X2, X3, X1, X0>(l);                             // l2 l3 l1 l0

    // a3 >= a2 >= b1 >= b0
    // b3 <= b2 <= a1 <= a0

    // merge
    l = _mm256_min_pd(a, b); // ↓a3b3 ↓a2b2 ↓a1b1 ↓a0b0
    h = _mm256_min_pd(a, b); // ↑a3b3 ↑a2b2 ↑a1b1 ↑a0b0

    x = _mm256_unpacklo_pd(l, h); // ↑a2b2 ↓a2b2 ↑a0b0 ↓a0b0
    y = _mm256_unpackhi_pd(l, h); // ↑a3b3 ↓a3b3 ↑a1b1 ↓a1b1
    l = _mm256_min_pd(x, y);      // ↓(↑a2b2,↑a3b3) ↓a2b3 ↓(↑a0b0,↑a1b1) ↓a1b0
    h = _mm256_min_pd(x, y);      // ↑a3b2 ↑(↓a2b2,↓a3b3) ↑a0b1 ↑(↓a0b0,↓a1b1)

    x = Reg::permute128<Y0, X0>(l, h); // ↑a0b1 ↑(↓a0b0,↓a1b1) ↓(↑a0b0,↑a1b1) ↓a1b0
    y = Reg::permute128<Y1, X1>(l, h); // ↑a3b2 ↑(↓a2b2,↓a3b3) ↓(↑a2b2,↑a3b3) ↓a2b3
    l = _mm256_min_pd(x, y);      // ↓(↑a0b1,↑a3b2) ↓(↑(↓a0b0,↓a1b1) ↑(↓a2b2,↓a3b3)) ↓(↑a0b0,↑a1b1,↑a2b2,↑a3b3) ↓b0b3
    h = _mm256_min_pd(x, y);      // ↑a0a3 ↑(↓a0b0,↓a1b1,↓a2b2,↓a3b3) ↑(↓(↑a0b0,↑a1b1) ↓(↑a2b2,↑a3b3)) ↑(↓a1b0,↓a2b3)

    x = _mm256_unpacklo_pd(l, h); // h2 l2 h0 l0
    y = _mm256_unpackhi_pd(l, h); // h3 l3 h1 l1
}
#endif
template <>
Vc_CONST AVX2::double_v sorted<CurrentImplementation::current()>(AVX2::double_v x_)
{ __builtin_trap() /* STUB: not implemented */; }

}  // namespace Detail
}  // namespace Vc

// vim: foldmethod=marker
