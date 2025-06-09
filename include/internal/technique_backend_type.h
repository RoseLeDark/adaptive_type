/**
 * @file technique_backend_type.h
 * @brief This file defines the technique_backend_type class, which serves as a base for different backend types in adaptive techniques.
 * @details It provides type definitions and a structure for creating adaptive techniques with various integer types.
 * @see adaptive_integer.h for the main adaptive number implementation
 * @see adaptive_number.h for the adaptive number template class
 *
 * @see technique_backend_scalar.h for the scalar backend implementation
 * @see technique_backend_sse.h for the SSE backend implementation
 * @see technique_backend_avx.h for the AVX backend implementation
 * @see technique_backend_mmx.h for the MMX backend implementation
 * @see technique_backend_avx512.h for the AVX512 backend implementation
 * @see adaptive_integer.h for the adaptive number template class  
 * 
 * @author Amber-Sophia Schröck 
 * @date 2025-06-09
 * @version 1.0
 * 
 * @copyright SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef ADAPTIVE_BACKEND_BASE_H
#define ADAPTIVE_BACKEND_BASE_H
                     
namespace adaptive {
    /**
     * @class technique_backend_type
     * @brief A template class representing a backend type for a technique.
     * 
     * @tparam TINT The type parameter used to define the backend type.
     */
    template <typename TINT>
    class technique_backend_type {
    public:
        /**
         * @typedef this_type
         * @brief Alias for the current template instantiation of technique_backend_type.
         */
        using this_type = technique_backend_type<TINT>;
        /**
         * @typedef value_type
         * @brief Alias for the type parameter TINT.
         */
        using value_type = TINT;
        /**
         * @typedef size_type
         * @brief Alias for size_t, representing the size type.
         */
        using size_type = size_t;
        /**
         * @typedef pointer
         * @brief Alias for a pointer to technique_backend_type<TINT>.
         */
        using pointer = technique_backend_type<TINT>*;
        /**
         * @typedef reference
         * @brief Alias for a reference to technique_backend_type<TINT>.
         */
        using reference = technique_backend_type<TINT>&;
        /**
         * @typedef const_pointer
         * @brief Alias for a constant pointer to technique_backend_type<TINT>.
         */
        using const_pointer = const technique_backend_type<TINT>*;
        /**
         * @typedef const_reference
         * @brief Alias for a constant reference to technique_backend_type<TINT>.
         */
        using const_refernce = const technique_backend_type<TINT>&;
        /**
         * @typedef const_type
         * @brief Alias for a constant technique_backend_type<TINT>.
         */
        using const_type = const technique_backend_type<TINT>;
    };
}
#endif

