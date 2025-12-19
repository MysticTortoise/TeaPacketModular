#pragma once

#include <cstdint>

#if __cplusplus >= 202002L
#include <bit>
#include <type_traits>
#endif

namespace TeaPacket::Endianness
{
    template<typename T> T Swap(T val) = delete;

    template<>
    inline uint16_t Swap(const uint16_t val)
    {
#if __cplusplus >= 202302L
        return std::byteswap(val);
#elif defined(__GNUC__)
        return __builtin_bswap16(val);
#else
        return (val>>8) | (val<<8);
#endif
    }

    template<>
    inline int16_t Swap(const int16_t val)
    {
#if __cplusplus >= 202302L
        return std::byteswap(val);
#else
        return (val>>8) | (val<<8);
#endif
    }

    template<>
    inline uint32_t Swap(const uint32_t val)
    {
#if __cplusplus >= 202302L
            return std::byteswap(val);
#elif defined(__GNUC__)
            return __builtin_bswap32(val);
#else
        return ((val>>24)&0xff) | ((val<<8)&0xff0000) | ((val>>8)&0xff00) | ((val<<24)&0xff000000);
#endif
    }

        template<>
    inline int32_t Swap(const int32_t val)
    {
#if __cplusplus >= 202302L
            return std::byteswap(val);
#else
        return ((val>>24)&0xff) | ((val<<8)&0xff0000) | ((val>>8)&0xff00) | ((val<<24)&0xff000000);
#endif
    }

    template<>
    inline uint64_t Swap(const uint64_t val)
    {
#if __cplusplus >= 202302L
        return std::byteswap(val);
#elif defined(__GNUC__)
        return __builtin_bswap64(val);
#else
        return Swap(static_cast<uint32_t>(val & 0xFFFFFFFF)) | Swap(static_cast<uint32_t>(val>>32&0xFFFFFFFF));
#endif
    }

    template<>
    inline int64_t Swap(const int64_t val)
    {
#if __cplusplus >= 202302L
        return std::byteswap(val);
#else
        return Swap(static_cast<uint32_t>(val & 0xFFFFFFFF)) | Swap(static_cast<uint32_t>(val>>32&0xFFFFFFFF));
#endif
    }

    template<>
    inline float Swap(float val)
    {
#if __cplusplus >= 202002L
        return std::bit_cast<float>(Swap<uint32_t>(std::bit_cast<uint32_t>(val)));
#else
        static_assert(sizeof(float) == sizeof(uint32_t), "FLOAT NOT 32 BIT, PLEASE FIX THIS FUNCTION");
        uint32_t r;
        memcpy(&r, &val, sizeof(float));
        r = Swap(r);
        memcpy(&val, &r, sizeof(float));
        return val;
#endif
    }


    constexpr bool IsBigEndian()
    {
#if __cplusplus >= 202002L
        return std::endian::native == std::endian::big;
#else
        constexpr union {
            uint32_t i;
            char c[4];
        } val = {0x01020304};
        return val.c[0] == 1;
#endif
    }
}
