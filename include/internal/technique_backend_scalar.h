
/**
 * @file technique_backend_scalar.h
 * @brief Header file for the `technique_backend_scalar` class.
 * 
 * This file defines the `technique_backend_scalar` class, which provides scalar-based 
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
#ifndef ADAPTIVE_BACKEND_SCALAR_H
#define ADAPTIVE_BACKEND_SCALAR_H

#include "technique_backend_type.h"

/**
 * @brief 
 */
namespace adaptive {
    /**
     * @class technique_backend_scalar
     * @brief A class that provides scalar-based backend operations for arithmetic computations.
     * 
     * This class is designed to perform arithmetic operations (addition, subtraction, 
     * multiplication, and division) using standard scalar operations. It supports 
     * different integer types based on the size of the template parameter `TINT`.
     * 
     * @tparam TINT The integer type used for computations.
     */
    template <typename TINT>
    class technique_backend_scalar  {
    public:
        using this_type = technique_backend_scalar<TINT>;
        using value_type = TINT;
        using size_type = size_t;
        using pointer = technique_backend_scalar<TINT>*;
        using reference = technique_backend_scalar<TINT>&;
        using const_pointer = const technique_backend_scalar<TINT>*;
        using const_refernce = const technique_backend_scalar<TINT>&;
        using const_type = const technique_backend_scalar<TINT>;

        /**
         * @brief Performs a scalar addition of two values of type `value_type`.
         *
         * This function adds two values of type `value_type` using standard scalar addition.
         *
         * @param a The first value to be added.
         * @param b The second value to be added.
         * @return The result of the addition as a `value_type`.
         */
        static value_type add(const value_type& a, const value_type& b)  {
            return a + b;
        }
        /**
         * @brief Performs a scalar subtraction of two values of type `value_type`.
         *
         * This function subtracts the second value from the first using standard scalar subtraction.
         *
         * @param a The value from which to subtract.
         * @param b The value to be subtracted.
         * @return The result of the subtraction as a `value_type`.
         */
        static value_type sub(const value_type& a, const value_type& b)  {
            return a - b;
        }
        /**
         * @brief Performs a scalar multiplication of two values of type `value_type`.
         *
         * This function multiplies two values of type `value_type` using standard scalar multiplication.
         *
         * @param a The first value to be multiplied.
         * @param b The second value to be multiplied.
         * @return The result of the multiplication as a `value_type`.
         */
        static value_type mul(const value_type& a, const value_type& b)  {
            return a * b;
        }
        /**
         * @brief Performs a scalar division of two values of type `value_type`.
         *
         * This function divides the first value by the second using standard scalar division.
         *
         * @param a The value to be divided.
         * @param b The value by which to divide.
         * @return The result of the division as a `value_type`.
         */
        static value_type div(const value_type& a, const value_type& b)  {
            return a / b;
        }
    };
}

#endif
