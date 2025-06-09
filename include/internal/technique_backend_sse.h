/**
 * @file technique_backend_sse.h
 * @brief Header file for the `technique_backend_sse` class.
 * 
 * This file defines the `technique_backend_sse` class, which provides sse-based 
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
#ifndef ADAPTIVE_BACKEND_SSE3_H
#define ADAPTIVE_BACKEND_SSE3_H

#include "technique_backend_type.h"


#ifdef __SSE2__
#include "emmintrin.h"
#include "smmintrin.h"

namespace adaptive {
    /**
     * @class technique_backend_sse
     * @brief A class that provides SSE-based backend operations for arithmetic computations.
     * 
     * This class is designed to perform arithmetic operations (addition, subtraction, 
     * multiplication, and division) using SSE intrinsics for optimized performance. 
     * It supports different integer types based on the size of the template parameter `TINT`.
     * 
     * @tparam TINT The integer type used for computations.
     */
    template <typename TINT>
    class technique_backend_sse  {
    public:
        using this_type = technique_backend_sse<TINT>;
        using value_type = TINT;
        using size_type = size_t;
        using pointer = technique_backend_sse<TINT>*;
        using reference = technique_backend_sse<TINT>&;
        using const_pointer = const technique_backend_sse<TINT>*;
        using const_refernce = const technique_backend_sse<TINT>&;
        using const_type = const technique_backend_sse<TINT>;


        static value_type add(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m128i va = _mm_set1_epi8(a);
                __m128i vb = _mm_set1_epi8(b);
                __m128i vc = _mm_add_epi8(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi8(vc, 0));
            } else if(sizeof(TINT) == 2) {
                __m128i va = _mm_set1_epi16(a);
                __m128i vb = _mm_set1_epi16(b);
                __m128i vc = _mm_add_epi16(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 4) {
                __m128i va = _mm_set1_epi32(a);
                __m128i vb = _mm_set1_epi32(b);
                __m128i vc = _mm_add_epi32(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi32(vc, 0));
            } else if(sizeof(TINT) == 8) {
                __m128i va = _mm_set1_epi64x(a);
                __m128i vb = _mm_set1_epi64x(b);
                __m128i vc = _mm_add_epi64(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi64(vc, 0));
            } 

            return _result;
        }
        static value_type sub(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m128i va = _mm_set1_epi8(a);
                __m128i vb = _mm_set1_epi8(b);
                __m128i vc = _mm_sub_epi8(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi8(vc, 0));
            } else if(sizeof(TINT) == 2) {
                __m128i va = _mm_set1_epi16(a);
                __m128i vb = _mm_set1_epi16(b);
                __m128i vc = _mm_sub_epi16(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 4) {
                __m128i va = _mm_set1_epi32(a);
                __m128i vb = _mm_set1_epi32(b);
                __m128i vc = _mm_sub_epi32(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi32(vc, 0));
            } else if(sizeof(TINT) == 8) {
                __m128i va = _mm_set1_epi64x(a);
                __m128i vb = _mm_set1_epi64x(b);
                __m128i vc = _mm_sub_epi64(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi64(vc, 0));
            } 

            return _result;
        }
        static value_type mul(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m128i va = _mm_set1_epi16(a);
                __m128i vb = _mm_set1_epi16(b);
                __m128i vc = _mm_mullo_epi16(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 2) {
                __m128i va = _mm_set1_epi16(a);
                __m128i vb = _mm_set1_epi16(b);
                __m128i vc = _mm_mullo_epi16(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi16(vc, 0));
            } else if(sizeof(TINT) == 4) {
                __m128i va = _mm_set1_epi32(a);
                __m128i vb = _mm_set1_epi32(b);
                __m128i vc = _mm_mullo_epi32(va, vb);
                _result = static_cast<value_type>(_mm_extract_epi32(vc, 0));
            } else {
                _result = a * b;
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
