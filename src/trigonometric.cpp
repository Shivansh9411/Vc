/*  This file is part of the Vc library. {{{
Copyright © 2012-2015 Matthias Kretz <kretz@kde.org>

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

// enable bit operators for easier portable bit manipulation on floats
#define Vc_ENABLE_FLOAT_BIT_OPERATORS 1

#include <Vc/vector.h>
#if defined(Vc_IMPL_SSE) || defined(Vc_IMPL_AVX)
#include <Vc/common/macros.h>
//#include <Vc/IO>

namespace Vc_VERSIONED_NAMESPACE
{
namespace Common
{
namespace
{
using Vc::Vector;
template <typename T, typename Abi>
using Const = typename std::conditional<std::is_same<Abi, VectorAbi::Avx>::value,
                                        AVX::Const<T>, SSE::Const<T>>::type;

template <typename V>
using best_int_v_for =
    typename std::conditional<(V::size() <= Vector<int, VectorAbi::Best<int>>::size()),
                              Vector<int, VectorAbi::Best<int>>,
                              SimdArray<int, V::size()>>::type;
template <typename Abi> using float_int_v = best_int_v_for<Vector<float, Abi>>;
template <typename Abi> using double_int_v = best_int_v_for<Vector<double, Abi>>;

template <typename Abi>
static Vc_ALWAYS_INLINE Vector<float, Abi> cosSeries(const Vector<float, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <typename Abi>
static Vc_ALWAYS_INLINE Vector<double, Abi> cosSeries(const Vector<double, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <typename Abi>
static Vc_ALWAYS_INLINE Vector<float, Abi> sinSeries(const Vector<float, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <typename Abi>
static Vc_ALWAYS_INLINE Vector<double, Abi> sinSeries(const Vector<double, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

/**\internal
 * Fold \p x into [-¼π, ¼π] and remember the quadrant it came from:
 * quadrant 0: [-¼π,  ¼π]
 * quadrant 1: [ ¼π,  ¾π]
 * quadrant 2: [ ¾π, 1¼π]
 * quadrant 3: [1¼π, 1¾π]
 *
 * The algorithm determines `y` as the multiple `x - y * ¼π = [-¼π, ¼π]`. Using a bitmask,
 * `y` is reduced to `quadrant`. `y` can be calculated as
 * ```
 * y = trunc(x / ¼π);
 * y += fmod(y, 2);
 * ```
 * This can be simplified by moving the (implicit) division by 2 into the truncation
 * expression. The `+= fmod` effect can the be achieved by using rounding instead of
 * truncation:
 * `y = round(x / ½π) * 2`.
 * If precision allows, `2/π * x` is better (faster).
 */
template <class T, class Abi> struct folded {
    Vector<T, Abi> x, quadrant;
};

template <typename Abi>
static Vc_ALWAYS_INLINE folded<float, Abi> foldInput(const Vector<float, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <typename Abi>
static Vc_ALWAYS_INLINE folded<double, Abi> foldInput(const Vector<double, Abi> &x)
{ __builtin_trap() /* STUB: not implemented */; }

constexpr double signmask = -0.;
constexpr float signmaskf = -0.f;
} // anonymous namespace

/*
 * algorithm for sine and cosine:
 *
 * The result can be calculated with sine or cosine depending on the π/4 section the input is
 * in.
 * sine   ≈ x + x³
 * cosine ≈ 1 - x²
 *
 * sine:
 * Map -x to x and invert the output
 * Extend precision of x - n * π/4 by calculating
 * ((x - n * p1) - n * p2) - n * p3 (p1 + p2 + p3 = π/4)
 *
 * Calculate Taylor series with tuned coefficients.
 * Fix sign.
 */
template <>
template <>
Vc::double_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::sin(const Vc::double_v &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
Vc::float_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::sin(const Vc::float_v &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
Vc::double_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::cos(const Vc::double_v &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
Vc::float_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::cos(const Vc::float_v &x)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
void Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::sincos(const Vc::double_v &x, Vc::double_v *s,
                                                   Vc::double_v *c)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
void Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::sincos(const Vc::float_v &x, Vc::float_v *s,
                                                   Vc::float_v *c)
{ __builtin_trap() /* STUB: not implemented */; }

template <>
template <>
Vc::float_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::asin(const Vc::float_v &_x)
{ __builtin_trap() /* STUB: not implemented */; }
template<> template<> Vc::double_v Trigonometric<Vc::Detail::TrigonometricImplementation<Vc::CurrentImplementation::current()>>::asin (const Vc::double_v &_x) { __builtin_trap() /* STUB: not implemented */; }
template <>
template <>
Vc::float_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::atan(const Vc::float_v &_x)
{ __builtin_trap() /* STUB: not implemented */; }
template<> template<> Vc::double_v Trigonometric<Vc::Detail::TrigonometricImplementation<Vc::CurrentImplementation::current()>>::atan (const Vc::double_v &_x) { __builtin_trap() /* STUB: not implemented */; }
template <>
template <>
Vc::float_v Trigonometric<Vc::Detail::TrigonometricImplementation<
    Vc::CurrentImplementation::current()>>::atan2(const Vc::float_v &y,
                                                  const Vc::float_v &x)
{ __builtin_trap() /* STUB: not implemented */; }
template<> template<> Vc::double_v Trigonometric<Vc::Detail::TrigonometricImplementation<Vc::CurrentImplementation::current()>>::atan2 (const Vc::double_v &y, const Vc::double_v &x) { __builtin_trap() /* STUB: not implemented */; }

}
}

#endif
