#ifndef ADAPTIVE_ENUM_TECH_H
#define ADAPTIVE_ENUM_TECH_H

#ifndef ADAPTIVE_BASE_TECHNIQ_USE 
#define ADAPTIVE_BASE_TECHNIQ_USE internal::detected_techniq_used<TINT>()
#endif

/**
 * @file adaptive_techniq.h
 * @brief Header file for adaptive techniques enumeration and utility functions.
 *
 * This file defines the `techn_type` enumeration, which represents various
 * adaptive techniques based on hardware capabilities, and provides utility
 * functions for converting enum values to strings and detecting the appropriate
 * technique based on type size.
 *
 * The adaptive techniques include scalar processing, SIMD instructions (MMX, SSE, AVX, AVX512, NEON),
 * and GPU-based techniques (OpenCL, Vulkan). The file also includes an internal namespace
 * for helper functions.
 *
 * @namespace adaptive
 * The primary namespace containing all adaptive technique-related definitions and utilities.
 *
 * @enum adaptive::techn_type
 * Enumeration of adaptive techniques. The values are conditionally compiled based on
 * hardware support macros such as `__MMX__`, `__SSE2__`, `__AVX2__`, `__AVX512__`, `__NEON__`, and `__GPU__`.
 *
 * @typedef adaptive::techn_t
 * Alias for the `techn_type` enumeration.
 *
 * @function adaptive::technt2string
 * Converts a `techn_t` enum value into its corresponding string representation.
 * Useful for debugging or logging purposes.
 *
 * @namespace adaptive::internal
 * Internal namespace containing helper functions for adaptive technique detection.
 *
 * @function adaptive::internal::detected_techniq_used
 * Template function to detect the appropriate adaptive technique based on the size
 * of the type `TINT`. Returns a value from the `techn_type` enumeration.
 */
namespace adaptive {

    /**
     * @brief 
     */
    enum class techn_type {
        Scalar = 0,
    #ifdef __MMX__
        MMX = 1,
    #endif
    #ifdef __SSE2__
        SSE = 2,
    #endif
    #ifdef __AVX2__
        AVX = 4,
    #endif
    #ifdef __AVX512__
        AVX512 = 8,
    #endif
    #ifdef __NEON__
        AVX512 = 16,
    #endif

    #ifdef __GPU__
        OpenCL = 200,
        Vulkan = 201,
    #endif
        internal = 255,
    };
    using techn_t = techn_type;

    /**
     * @brief Converts a `techn_t` enum value into its corresponding string representation.
     *
     * This utility function takes an input of type `techn_t` and returns a string
     * that represents the enum value. It is useful for debugging or logging purposes
     * where a human-readable representation of the enum is required.
     *
     * @param techn The `techn_t` enum value to be converted.
     * @return A `std::string` containing the name of the enum value.
     */
    inline std::string technt2string(const techn_t tech) {
        std::string _res = "Scalar";
        switch (tech)  {
        #ifdef __MMX__
        case techn_t::MMX: _res = "MMX"; break;
        #endif
        #ifdef __SSE2__
        case techn_t::SSE: _res = "SSE";break;
        #endif
        #ifdef __AVX2__
        case techn_t::AVX: _res = "AVX";break;
        #endif
        #ifdef __AVX512__
        case techn_t::AVX512: _res = "AVX512";break;
        #endif
        #ifdef __NEON__
        case techn_t::NEON: _res = "NEON";break;
        #endif

        #ifdef __GPU__
        case techn_t::OpenCL: _res = "OpenCL";break;
        case techn_t::Vulkan: _res = "Vulkan";break;
        #endif       
        default: _res = "Scalar";
        }
        return _res;
    }

namespace internal {
        /**
         * @brief Detects the appropriate adaptive technique based on the type size.
         * 
         * This function determines the adaptive technique to be used based on the size
         * of the type `TINT`. It returns a value from the `techn_type` enum that indicates
         * the most suitable technique for the given type size.
         *
         * @tparam TINT The type for which the adaptive technique is being determined.
         * @return techn_type The detected adaptive technique.
         */
        template <typename TINT>
        constexpr techn_type detected_techniq_used() {
            techn_type _result = techn_type::internal;
            if(_result == techn_type::internal) {
                if(sizeof(TINT) <= 4) _result = techn_type::Scalar;
                else if(sizeof(TINT) <= 8) _result = techn_type::SSE;
                else _result = techn_type::AVX;
            }


            return _result;
        }
    }
}

#endif
