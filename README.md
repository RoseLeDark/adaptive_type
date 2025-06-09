# adaptive_type

`adaptive_type` is a C++ library that provides adaptive numeric types capable of automatically selecting the optimal backend implementation for numerical operations. It supports a wide range of techniques, from scalar to SIMD (MMX, SSE, AVX, AVX512) and GPU-based computations.

## Features

- **Adaptive Backend Selection**: Automatically chooses the best backend (scalar, SIMD, or GPU) based on the platform and data type.
- **Customizable Techniques**: Allows users to specify the desired technique for numerical operations.
- **Type Safety**: Provides strong type safety with template-based adaptive types.
- **Performance Optimization**: Leverages SIMD and GPU capabilities for high-performance computations.
- **Ease of Use**: Simple API for arithmetic, comparison, and assignment operations.

## Supported Techniques

- Scalar
- MMX
- SSE
- AVX
- AVX512
- Internal (custom techniques)

## Installation

To use `adaptive_type` in your project, include the library in your PlatformIO project:

1. Clone the repository:
   ```bash
   git clone https://github.com/RoseLeDark/adaptive_type.git
   ```
2. Add the library to your PlatformIO project:
   ```json
   "lib_deps": [
       "adaptive_type"
   ]
   ```

## Usage

### Example

```cpp
#include <adaptive_integer.h>

int main() {
    adaptive::int32s_t num1(42);
    adaptive::int32s_t num2(10);

    auto result = num1 + num2;
    result += 5;

    if (result > num1) {
        std::cout << "Result is greater than num1: " << result.value() << std::endl;
    }

    return 0;
}
```

### Type Aliases

The library provides predefined type aliases for common integer types:

- `adaptive::int8s_t`, `adaptive::int16s_t`, `adaptive::int32s_t`, `adaptive::int64s_t`
- `adaptive::uint8s_t`, `adaptive::uint16s_t`, `adaptive::uint32s_t`, `adaptive::uint64s_t`

### Custom Techniques

You can specify a custom technique for adaptive numbers:

```cpp
adaptive::int32ts_t<adaptive::techn_type::SSE> sse_num(100);
```

## Documentation

For detailed documentation, visit the [GitHub repository](https://github.com/RoseLeDark/adaptive_type).

## License

This project is licensed under the LGPL-2.1-or-later license. See the [LICENSE](https://github.com/RoseLeDark/adaptive_type/blob/main/LICENSE) file for details.

## Author

Developed by Amber-Sophia Schröck. For inquiries, contact [pba3h11aso@schattenfeld.de](mailto:pba3h11aso@schattenfeld.de).

