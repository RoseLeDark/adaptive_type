/**
 * @file adaptive_integer.h
 * @brief Header file for adaptive integer types with customizable techniques.
 * 
 * This file defines the `adaptive_number` class template and related types for adaptive integers.
 * It includes support for various backend techniques such as scalar, MMX, SSE, AVX, and AVX512.
 * 
 * @author Amber-Sophia Schröck 
 * @date 2025-06-09
 * @version 1.0
 * 
 * @copyright SPDX-License-Identifier: LGPL-2.1-or-later 
 */ 

#ifndef __ADAPTIVE_INTEGER__
#define __ADAPTIVE_INTEGER__ 1


#include <cstdint>
#include <string>

#include <adaptive_techniq.h>

#include <internal/technique_backend_scalar.h>
#include <internal/technique_backend_mmx.h>
#include <internal/technique_backend_sse.h>
#include <internal/technique_backend_avx.h>

/**
 * @namespace adaptive
 * @brief The adaptive namespace provides a framework for implementing adaptive numbers with customizable integer types and backend techniques.
 * 
 * The namespace includes:
 * - A technique selector to choose the appropriate backend implementation based on the integer type and technique.
 * - A template class `adaptive_number` that wraps numeric types and delegates operations to the selected backend.
 * - Type aliases for commonly used adaptive numbers with predefined integer types and techniques.
 * 
 * Features:
 * - Supports multiple backend implementations such as scalar, MMX, SSE, AVX, and AVX512.
 * - Provides arithmetic, comparison, and assignment operators for adaptive numbers.
 * - Allows customization of backend techniques for different integer types.
 * 
 * Example usage:
 * @code
 * adaptive::int32s_t num(42);
 * num += 10;
 * auto result = num * 2;
 * @endcode
 */
namespace adaptive {
    /**
     * @brief A template struct that selects the appropriate technique backend based on the integer type and technique
     * 
     * This struct uses template specialization to determine the correct backend implementation for a given integer type and technique.
     * It provides a `type` member that is the selected backend class.
     * 
     * @tparam TINT The base integer type
     * @tparam TTECH The technique type for numerical operations
     */
    template <typename TINT, techn_t TTECH>
    struct technique_selector {
        using type = technique_backend_scalar<TINT>;
    };
    /**
     * @brief Specializations of technique_selector for different integer types and techniques
     * 
     * These specializations define the appropriate backend implementation for various combinations of integer types and techniques.
     * They ensure that the correct backend is used based on the specified integer type and technique.
     */
    template <typename TINT>
    struct technique_selector<TINT, techn_type::Scalar> {
        using type = technique_backend_scalar<TINT>;
    };

    /**
     * @brief Specialization for internal technique  
     */   
    template <typename TINT>
    struct technique_selector<TINT, techn_type::internal> {
        using type = technique_backend_scalar<TINT>;
    };
#ifdef __MMX__
    /**
     * @brief Specialization for MMX technique
     */
    template <typename TINT>
    struct technique_selector<TINT, techn_type::MMX> {
        using type = technique_backend_mmx<TINT>;
    };
#endif

#ifdef __SSE2__
    /**
     * @brief Specialization for SSE technique
     */
    template <typename TINT>
    struct technique_selector<TINT, techn_type::SSE> {
        using type = technique_backend_sse<TINT>;
    };
#endif

#ifdef __AVX2__
    /**
     * @brief Specialization for AVX technique
     */
    template <typename TINT>
    struct technique_selector<TINT, techn_type::AVX> {
        using type = technique_backend_avx<TINT>;
    };
#endif

#ifdef __AVX512__
    /**
     * @brief Specialization for AVX512 technique
     */
    template <typename TINT>
    struct technique_selector<TINT, techn_type::AVX512> {
        using type = technique_backend_avx<TINT>;
    };
#endif
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (uint8_t, uint16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<uint8_t, techn_t::Scalar> {
        using type = technique_backend_scalar<uint8_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (uint8_t, uint16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<uint16_t, techn_t::Scalar> {
        using type = technique_backend_scalar<uint16_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (uint8_t, uint16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<uint32_t, techn_t::Scalar> {
        using type = technique_backend_scalar<uint32_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (uint8_t, uint16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<uint64_t, techn_t::SSE> {
        using type = technique_backend_sse<uint64_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (int8_t, int16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<int8_t, techn_t::Scalar> {
        using type = technique_backend_scalar<int8_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (int8_t, int16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */  
    template <>
    struct technique_selector<int16_t, techn_t::Scalar> {
        using type = technique_backend_scalar<int16_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (int8_t, int16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<int32_t, techn_t::Scalar> {
        using type = technique_backend_scalar<int32_t>;
    };
    /**
     * @brief Specializations for specific integer types and techniques
     * 
     * These specializations define the backend implementations for common integer types (int8_t, int16_t, etc.) with specific techniques.
     * They ensure that the correct backend is used based on the integer type and technique.
     */
    template <>
    struct technique_selector<int64_t, techn_t::SSE> {
        using type = technique_backend_sse<int64_t>;
    };
  
    /**
     * @brief A template class that implements an adaptive number with customizable integer type and technique
     * 
     * @tparam TINT The base integer type
     * @tparam TTECH The technique type for numerical operations
     * 
     * This class provides a wrapper for numeric types with customizable backend operations.
     * It supports basic arithmetic operations (+, -, *, /), compound assignments (+=, -=, *=, /=),
     * increment/decrement operators, and comparison operations.
     * 
     * Type definitions:
     * - backend_type: The underlying implementation type based on TINT and TTECH
     * - value_type: The type of the stored value
     * - size_type: The size type used by the backend
     * - pointer: Pointer to this adaptive number type
     * - reference: Reference to this adaptive number type
     * 
     * @note All arithmetic operations are delegated to the backend_type implementation
     * @note Most operations are implemented as noexcept for exception safety
     * 
     * Example usage:
     * @code
     * int32s_t num(42);
     * num += 10;
     * auto result = num * 2;
     * @endcode
     */
    template <typename TINT, techn_t TTECH = ADAPTIVE_BASE_TECHNIQ_USE >
    class adaptive_number  {
    public:
        using backend_type = typename technique_selector<TINT, TTECH>::type;
        using this_type = adaptive_number<TINT, TTECH>;
        using value_type = typename backend_type::value_type;
        using size_type = typename backend_type::size_type;
        using pointer = this_type*;
        using reference = this_type&;
        using const_pointer = const this_type*;
        using const_refernce = const this_type&;
        using const_type = const this_type;

        /**
         * @brief Default constructor for adaptive_number
         * 
         * This constructor initializes an adaptive_number instance with a default value of 0.
         * It creates a new instance with the value set to zero.
         */
        adaptive_number() noexcept
            : m_tiValue (0) { }
        /**
         * @brief Constructor for adaptive_number with a specific value
         * 
         * This constructor initializes an adaptive_number instance with a given value.
         * It creates a new instance with the specified value.
         * 
         * @param value The initial value to set for this adaptive number
         */
        explicit adaptive_number(value_type value = 0) noexcept
            : m_tiValue (value) { }
        /**
         * @brief Copy constructor for adaptive_number
         * 
         * This constructor initializes a new adaptive_number instance by copying the value from another instance.
         * It creates a new instance with the same value as the source instance.
         * 
         * @param other The adaptive_number instance to copy from
         */
        adaptive_number(const_refernce other) noexcept 
            : m_tiValue(other.m_tiValue) { }
        
        /**
         * @brief Move constructor for adaptive_number
         * 
         * This constructor initializes a new adaptive_number instance by moving the value from another instance.
         * It transfers ownership of the value and leaves the moved-from instance in a valid but unspecified state.
         * 
         * @param other The adaptive_number instance to move from
         */
        adaptive_number(adaptive_number<TINT, TTECH>&& other) noexcept
            : m_tiValue(std::move(other).m_tiValue) { }

        /**
         * @brief Destructor for adaptive_number
         * 
         * This destructor cleans up the adaptive_number instance.
         * It is virtual to allow derived classes to override it if necessary.
         */
        virtual ~adaptive_number() = default;

        /**
         * @brief Get the value of this adaptive number
         * 
         * This method returns the current value stored in this adaptive number.
         * 
         * @return The value of this adaptive number
         */
        value_type value() const           { return m_tiValue; }
        /**
         * @brief Get the technique used by this adaptive number
         * 
         * This method returns the technique used for numerical operations in this adaptive number.
         * 
         * @return The technique type used by this adaptive number
         */
        techn_t get_techniq() const        { return TTECH; }
        /**
         * @brief Set the value of this adaptive number
         * 
         * This method allows setting the value of this adaptive number to a new value.
         * 
         * @param v The new value to set
         */
        void set(const value_type v) const { m_tiValue = v; }

        /**
         * @brief Addition operator
         * 
         * This operator adds the value of another adaptive number to the value of this adaptive number.
         * 
         * @param other The adaptive_number instance to add
         * @return A new adaptive_number instance containing the result of the addition
         */
        this_type operator + (const_refernce other) const {
            this_type result ( backend_type::add(m_tiValue, other.m_tiValue ) );
            return result;
        }
        /**
         * @brief Subtraction operator
         * 
         * This operator subtracts the value of another adaptive number from the value of this adaptive number.
         * 
         * @param other The adaptive_number instance to subtract
         * @return A new adaptive_number instance containing the result of the subtraction
         */
        this_type operator - (const_refernce other) const {
            this_type result ( backend_type::sub(m_tiValue, other.m_tiValue ) );
            return result;
        }
        /**
         * @brief Multiplication operator
         * 
         * This operator multiplies the value of this adaptive number by the value of another adaptive number.
         * 
         * @param other The adaptive_number instance to multiply with
         * @return A new adaptive_number instance containing the result of the multiplication
         */
        this_type operator * (const_refernce other) const {
            this_type result ( backend_type::mul(m_tiValue, other.m_tiValue ) );
            return result;
        }
        /**
         * @brief Division operator
         * 
         * This operator divides the value of this adaptive number by the value of another adaptive number.
         * 
         * @param other The adaptive_number instance to divide by
         * @return A new adaptive_number instance containing the result of the division
         */
        this_type operator / (const_refernce other) const {
            this_type result ( backend_type::div(m_tiValue, other.m_tiValue ) );
            return result;
        }

        /**
         * @brief Pre-increment operator
         * 
         * This operator increments the value of this adaptive number by 1 and returns the updated instance.
         * 
         * @return Reference to this instance after the increment
         */
        this_type operator ++ (int) {
            m_tiValue = backend_type::add(m_tiValue, 1 );
            return *this;
        }

        /**
         * @brief Post-decrement operator
         * 
         * This operator decrements the value of this adaptive number by 1 and returns the previous value.
         * 
         * @return The adaptive_number instance before the decrement
         */
        this_type operator -- (int) {
            m_tiValue = backend_type::sub(m_tiValue, 1 );
            return *this;
        }
        
        /**
         * @brief Addition assignment operator
         * 
         * This operator adds the value of another adaptive number to the value of this adaptive number.
         * 
         * @param other The adaptive_number instance to add
         * @return Reference to this instance after the addition assignment
         */
        this_type& operator += (const_refernce other)  {
            m_tiValue = backend_type::add(m_tiValue, other.m_tiValue );
            return *this;
        }
        /**
         * @brief Subtraction assignment operator
         * 
         * This operator subtracts the value of another adaptive number from the value of this adaptive number.
         * 
         * @param other The adaptive_number instance to subtract
         * @return Reference to this instance after the subtraction assignment
         */
        this_type& operator -= (const_refernce other)  {
            m_tiValue = backend_type::sub(m_tiValue, other.m_tiValue );
            return *this;
        }
        /**
         * @brief Multiplication assignment operator
         * 
         * This operator multiplies the value of this adaptive number by the value of another adaptive number.
         * 
         * @param other The adaptive_number instance to multiply with
         * @return Reference to this instance after the multiplication assignment
         */
        this_type& operator *= (const_refernce other) {
            m_tiValue = backend_type::mul(m_tiValue, other.m_tiValue );
            return *this;
        }
        /**
         * @brief Division assignment operator
         * 
         * This operator divides the value of this adaptive number by the value of another adaptive number.
         * 
         * @param other The adaptive_number instance to divide by
         * @return Reference to this instance after the division assignment
         */
        this_type& operator /= (const_refernce other) {
            m_tiValue = backend_type::div(m_tiValue, other.m_tiValue );
            return *this;
        }

        /**
         * @brief Equality operator
         * 
         * This operator checks if the value of this adaptive number is equal to the value of another adaptive number.
         * 
         * @param o The adaptive_number instance to compare with
         * @return true if this instance's value is equal to o's value, false otherwise
         */
        inline bool operator == (const this_type o) noexcept { 
            return (m_tiValue == o.m_tiValue);  
        }
        /**
         * @brief Not equal operator
         * 
         * This operator checks if the value of this adaptive number is not equal to the value of another adaptive number.
         * 
         * @param o The adaptive_number instance to compare with
         * @return true if this instance's value is not equal to o's value, false otherwise
         */
        inline bool operator != (const this_type o) noexcept { 
            return !(m_tiValue == o.m_tiValue);  
        }
        /**
         * @brief Less than operator
         * 
         * This operator checks if the value of this adaptive number is less than the value of another adaptive number.
         * 
         * @param o The adaptive_number instance to compare with
         * @return true if this instance's value is less than o's value, false otherwise
         */
        inline bool operator < (const this_type o) noexcept { 
            return (m_tiValue < o.m_tiValue);   
        }
        /**
         * @brief Greater than operator
         * 
         * This operator checks if the value of this adaptive number is greater than the value of another adaptive number.
         * 
         * @param o The adaptive_number instance to compare with
         * @return true if this instance's value is greater than o's value, false otherwise
         */
        inline bool operator > (const this_type o) noexcept { 
            return (m_tiValue > o.m_tiValue);  
        }
        /**
         * @brief Less than or equal to operator
         * 
         * This operator checks if the value of this adaptive number is less than or equal to the value of another adaptive number.
         * 
         * @param a The adaptive_number instance to compare with
         * @return true if this instance's value is less than or equal to a's value, false otherwise
         */
        inline bool operator <= (this_type a) noexcept { 
            return (m_tiValue <= a.m_tiValue);  
        }
        /**
         * @brief Greater than or equal to operator
         * 
         * This operator checks if the value of this adaptive number is greater than or equal to the value of another adaptive number.
         * 
         * @param a The adaptive_number instance to compare with
         * @return true if this instance's value is greater than or equal to a's value, false otherwise
         */
        inline bool operator >= (this_type a) noexcept { 
            return (m_tiValue >= a.m_tiValue);  
        }
        /**
         * @brief Copy assignment operator
         * 
         * This operator allows copying the value from another adaptive_number instance.
         * It assigns the value from the source instance to this instance.
         * 
         * @param o The adaptive_number instance to copy from
         * @return Reference to this instance after the copy assignment
         */
        inline this_type& operator = (this_type& o) noexcept {
            m_tiValue = o.m_tiValue; return *this;
        }
        /**
         * @brief Move assignment operator
         * 
         * This operator allows moving the value from another adaptive_number instance.
         * It transfers ownership of the value and leaves the moved-from instance in a valid but unspecified state.
         * 
         * @param o The adaptive_number instance to move from
         * @return Reference to this instance after the move assignment
         */
        inline this_type& operator = (this_type&& o) noexcept {
            m_tiValue = std::move(o).m_tiValue; return *this;
        }

    protected:
        /**
         * @brief The value stored in this adaptive number
         * 
         * This member variable holds the actual numeric value of the adaptive number.
         * It is of type `value_type`, which is defined based on the backend implementation.
         */
        value_type m_tiValue;
    };
    
    /**
     * @typedef uint8s_t
     * @brief A type alias for an adaptive number based on an 8-bit unsigned integer.
     * @see adaptive_number
     */
    using int8s_t = adaptive_number<int8_t>;
    /**
     * @typedef int16s_t
     * @brief A type alias for an adaptive number based on an 16-bit unsigned integer.
     * @see adaptive_number
     */
    using int16s_t = adaptive_number<int16_t>;
    /**
     * @typedef int32s_t
     * @brief A type alias for an adaptive number based on an 32-bit unsigned integer.
     * @see adaptive_number
     */
    using int32s_t = adaptive_number<int32_t>;
    /**
     * @typedef int64s_t
     * @brief A type alias for an adaptive number based on an 64-bit unsigned integer.
     * @see adaptive_number
     */
    using int64s_t = adaptive_number<int64_t>;

    /**
     * @typedef uint8s_t
     * @brief A type alias for an adaptive number based on an 8-bit unsigned integer.
     * @see adaptive_number
     */
    using uint8s_t = adaptive_number<uint8_t>;
    /**
     * @typedef uint16s_t
     * @brief A type alias for an adaptive number based on an 16-bit unsigned integer.
     * @see adaptive_number
     */
    using uint16s_t = adaptive_number<uint16_t>;
    /**
     * @typedef uint16s_t
     * @brief A type alias for an adaptive number based on an 32-bit unsigned integer.
     * @see adaptive_number
     */
    using uint32s_t = adaptive_number<uint32_t>;
    /**
     * @typedef uint64s_t
     * @brief A type alias for an adaptive number based on an 64-bit unsigned integer.
     * @see adaptive_number
     */
    using uint64s_t = adaptive_number<uint64_t>;


    
    /**
     * @brief Type alias for an adaptive number based on an 8-bit unsigned integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with uint8_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for uint8_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<uint8_t>() >
    using uint8ts_t = adaptive_number<uint8_t, TTECH>;
     /**
     * @brief Type alias for an adaptive number based on an 16-bit unsigned integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with uint16_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for uint16_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<uint16_t>() >
    using uint16ts_t = adaptive_number<uint16_t, TTECH>;
    /**
     * @brief Type alias for an adaptive number based on an 32-bit unsigned integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with uint32_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for uint32_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<uint32_t>() >
    using uint32ts_t = adaptive_number<uint32_t, TTECH>;
    /**
     * @brief Type alias for an adaptive number based on an 64-bit unsigned integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with uint64_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for uint64_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<uint64_t>() >
    using uint64ts_t = adaptive_number<uint64_t, TTECH>;

    /**
     * @brief Type alias for an adaptive number based on an 8-bit signed integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with int8_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for int8_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<int8_t>() >
    using int8ts_t = adaptive_number<int8_t, TTECH>;
    /**
     * @brief Type alias for an adaptive number based on an 16-bit signed integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with int16_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for int16_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<int16_t>() >
    using int16ts_t = adaptive_number<int16_t, TTECH>;
    /**
     * @brief Type alias for an adaptive number based on an 32-bit signed integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with int32_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for int32_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<int32_t>() >
    using int32ts_t = adaptive_number<int32_t, TTECH>;
    /**
     * @brief Type alias for an adaptive number based on an 64-bit signed integer with a specific technique
     * 
     * This type alias uses the adaptive_number template with int64_t as the base type and the specified technique.
     * 
     * @see adaptive_number
     * @tparam TTECH The technique type for numerical operations, defaults to the detected technique for int64_t
     */
    template <techn_t TTECH = internal::detected_techniq_used<int64_t>() >
    using int64ts_t = adaptive_number<int64_t, TTECH>;

} // namespace adapt

#endif
