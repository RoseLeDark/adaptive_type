/**
 * @file technique_backend_avx.h
 * @brief Header file for the `technique_backend_avx` class.
 * 
 * This file defines the `technique_backend_avx` class, which provides avx2-based 
 * backend operations for arithmetic computations. The class supports addition, subtraction, 
 * multiplication, and division using standard scalar operations. It is templated to work 
 * with different integer types.
 * 
 * @author Amber-Sophia Schröck 
 * @date 2025-06-09
 * @version 1.0
 * 
 * @copyright SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef ADAPTIVE_BACKEND_AVX_H
#define ADAPTIVE_BACKEND_AVX_H


#include "technique_backend_type.h"

#ifdef __AVX2__
#include "immintrin.h"
#include "avxintrin.h"

 
namespace adaptive {
     
    
    /**
     * @class technique_backend_avx
     * @brief A class that provides AVX-based backend operations for arithmetic computations.
     * 
     * This class is designed to perform arithmetic operations (addition, subtraction, 
     * multiplication, and division) using AVX intrinsics for optimized performance. 
     * It supports different integer types based on the size of the template parameter `TINT`.
     * 
     * @tparam TINT The integer type used for computations.
     * 
     * @note The class assumes that AVX2 instructions are available on the target platform.
     */
    template <typename TINT>
    class technique_backend_avx  {
    public:
        using this_type = technique_backend_avx<TINT>;
        using value_type = TINT;
        using size_type = size_t;
        using pointer = technique_backend_avx<TINT>*;
        using reference = technique_backend_avx<TINT>&;
        using const_pointer = const technique_backend_avx<TINT>*;
        using const_refernce = const technique_backend_avx<TINT>&;
        using const_type = const technique_backend_avx<TINT>;


        /**
         * @brief Performs an AVX-based addition of two values of type `value_type`.
         *
         * This function uses AVX intrinsics to add two values of type `value_type`,
         * which is determined by the size of the underlying type `TINT`. The addition
         * is performed using the appropriate AVX intrinsic based on the size of `TINT`.
         *
         * @tparam TINT The underlying integer type used for the operation.
         * @param a The first value to be added.
         * @param b The second value to be added.
         * @return The result of the addition as a `value_type`.
         *
         * @note The function handles different sizes of `TINT` (1, 2, 4, or 8 bytes)
         *       and uses the corresponding AVX intrinsic for the operation.
         *       If `TINT` does not match any of these sizes, the behavior is undefined.
         */
        static value_type add(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m256i va = _mm256_set1_epi8(a);
                __m256i vb = _mm256_set1_epi8(b);
                __m256i vc = _mm256_add_epi8(va, vb);
                _result = (_mm256_extract_epi8(vc, 0) );
            } else if(sizeof(TINT) == 2) {
                __m256i va = _mm256_set1_epi16(a);
                __m256i vb = _mm256_set1_epi16(b);
                __m256i vc = _mm256_add_epi16(va, vb);
                _result = (_mm256_extract_epi16(vc, 0) );
            } else if(sizeof(TINT) == 4) {
                __m256i va = _mm256_set1_epi32(a);
                __m256i vb = _mm256_set1_epi32(b);
                __m256i vc = _mm256_add_epi32(va, vb);
                _result = (_mm256_extract_epi32(vc, 0));
            } else if(sizeof(TINT) == 8) {
                __m256i va = _mm256_set1_epi64x(a);
                __m256i vb = _mm256_set1_epi64x(b);
                __m256i vc = _mm256_add_epi64(va, vb);
                _result = (_mm256_extract_epi64(vc, 0 ));
            } 

            return _result;
        }
        static value_type sub(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m256i va = _mm256_set1_epi8(a);
                __m256i vb = _mm256_set1_epi8(b);
                __m256i vc = _mm256_sub_epi8(va, vb);
                _result = (_mm256_extract_epi8(vc, 0));
            } else if(sizeof(TINT) == 2) {
                __m256i va = _mm256_set1_epi16(a);
                __m256i vb = _mm256_set1_epi16(b);
                __m256i vc = _mm256_sub_epi16(va, vb);
                _result = (_mm256_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 4) {
                __m256i va = _mm256_set1_epi32(a);
                __m256i vb = _mm256_set1_epi32(b);
                __m256i vc = _mm256_sub_epi32(va, vb);
                _result = (_mm256_extract_epi32(vc, 0));
            } else if(sizeof(TINT) == 8) {
                __m256i va = _mm256_set1_epi64x(a);
                __m256i vb = _mm256_set1_epi64x(b);
                __m256i vc = _mm256_sub_epi64(va, vb);
                _result = (_mm256_extract_epi64(vc, 0));
            } else if(sizeof(TINT) == 16) {
                __m256i va = _mm256_set_epi64x(a.low, a.hight, 0, 0);
                __m256i vb = _mm256_set_epi64x(b.low, b.hight, 0, 0);
                __m256i vc = _mm256_sub_epi64(va, vb);
                _result.low = (_mm256_extract_epi64(vc, 0));
                _result.hight = (_mm256_extract_epi64(vc, 1));
            } 

            return _result;
        }
        static value_type mul(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m256i va = _mm256_set1_epi16(a);
                __m256i vb = _mm256_set1_epi16(b);
                __m256i vc = _mm256_mullo_epi16(va, vb);
                _result = (_mm256_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 2) {
                __m256i va = _mm256_set1_epi16(a);
                __m256i vb = _mm256_set1_epi16(b);
                __m256i vc = _mm256_mullo_epi16(va, vb);
                _result = (_mm256_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 4) {
                __m256i va = _mm256_set1_epi32(a);
                __m256i vb = _mm256_set1_epi32(b);
                __m256i vc = _mm256_mullo_epi32(va, vb);
                _result = (_mm256_extract_epi32(vc, 0));
            } else if(sizeof(TINT) == 8) {
                __m256i va = _mm256_set1_epi64x(a);
                __m256i vb = _mm256_set1_epi64x(b);
                __m256i vc = _mm256_mullo_epi64(va, vb);
                _result = (_mm256_extract_epi64(vc, 0));
            } 

            return _result;
        }
        static value_type div(const value_type& a, const value_type& b)  {
            return a / b;
        }
    };
}
#endif 

#endif
