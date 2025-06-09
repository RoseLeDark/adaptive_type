/**
 * @file technique_backend_mmx.h
 * @brief Header file for the `technique_backend_mmx` class.
 * 
 * This file defines the `technique_backend_mmx` class, which provides mmx-based 
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
#ifndef ADAPTIVE_BACKEND_MMX_H
#define ADAPTIVE_BACKEND_MMX_H

#include "technique_backend_type.h"

#ifdef __MMX__

#include "mmintrin.h"


namespace adaptive {
    /**
     * @class technique_backend_mmx
     * @brief A class that provides MMX-based backend operations for arithmetic computations.
     * 
     * This class is designed to perform arithmetic operations (addition, subtraction, 
     * multiplication, and division) using MMX intrinsics for optimized performance. 
     * It supports different integer types based on the size of the template parameter `TINT`.
     * 
     * @tparam TINT The integer type used for computations.
     */
    template <typename TINT>
    class technique_backend_mmx  {
    public:
        using this_type = technique_backend_mmx<TINT>;
        using value_type = TINT;
        using size_type = size_t;
        using pointer = technique_backend_mmx<TINT>*;
        using reference = technique_backend_mmx<TINT>&;
        using const_pointer = const technique_backend_mmx<TINT>*;
        using const_refernce = const technique_backend_mmx<TINT>&;
        using const_type = const technique_backend_mmx<TINT>;


        static value_type add(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m64 va = _mm_set1_pi8(a);
                __m64 vb = _mm_set1_pi8(b);
                __m64 vc = _mm_add_pi8(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 2) {
                __m64 va = _mm_set1_pi16(a);
                __m64 vb = _mm_set1_pi16(b);
                __m64 vc = _mm_add_pi16(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 4) {
                __m64 va = _mm_set1_pi32(a);
                __m64 vb = _mm_set1_pi32(b);
                __m64 vc = _mm_add_pi32(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 8) {
                __m64 va = _m_from_int64(a);
                __m64 vb = _m_from_int64(b);
                __m64 vc = _mm_add_si64(va, vb);
                _result = static_cast<value_type>(_mm_cvtm64_si64(vc));
                _mm_empty();
            } else {
                _result = a + b;
            }
            
            return _result;
        }
        static value_type sub(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m64 va = _mm_set1_pi8(a);
                __m64 vb = _mm_set1_pi8(b);
                __m64 vc = _mm_sub_pi8(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 2) {
                __m64 va = _mm_set1_pi16(a);
                __m64 vb = _mm_set1_pi16(b);
                __m64 vc = _mm_sub_pi16(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 4) {
                __m64 va = _mm_set1_pi32(a);
                __m64 vb = _mm_set1_pi32(b);
                __m64 vc = _mm_sub_pi32(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 8) {
                __m64 va = _m_from_int64(a);
                __m64 vb = _m_from_int64(b);
                __m64 vc = _mm_sub_si64(va, vb);
                _result = static_cast<value_type>(_mm_cvtm64_si64(vc));
                _mm_empty();
            } else {
                _result = a - b;
            }
            
            return _result;
        }
        static value_type mul(const value_type& a, const value_type& b)  {
            value_type _result = 0;

            if(sizeof(TINT) == 1) {
                __m64 va = _mm_set1_pi16(a);
                __m64 vb = _mm_set1_pi16(b);
                __m64 vc = _mm_mullo_pi16(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
            } else if(sizeof(TINT) == 2) {
                __m64 va = _mm_set1_pi16(a);
                __m64 vb = _mm_set1_pi16(b);
                __m64 vc = _mm_mullo_pi16(va, vb);
                _result = static_cast<value_type>(_mm_cvtsi64_si32(vc));
                _mm_empty();
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
