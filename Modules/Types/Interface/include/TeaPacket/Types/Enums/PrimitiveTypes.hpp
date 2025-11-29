#pragma once
#include <exception>

namespace TeaPacket
{
    /// Represents a primitive type.
    enum class PrimitiveType : unsigned char
    {
        Bool,
        Char,
        Float,
        Integer,
        Short,
        Long,
        UChar,
        UInt,
        UShort,
        ULong
    };

    /// Gets the memory size of a primitive type.
    [[nodiscard]] constexpr size_t SizeOfPrimitiveType(const PrimitiveType type)
    {
        switch (type)
        {
            using enum PrimitiveType;
        case Bool: return sizeof(bool);
        case Char : return sizeof(char);
        case Float: return sizeof(float);
        case Integer: return sizeof(int);
        case Short: return sizeof(short);
        case Long: return sizeof(long);
        case UChar: return sizeof(unsigned char);
        case UInt: return sizeof(unsigned int);
        case UShort: return sizeof(unsigned short);
        case ULong: return sizeof(unsigned long);
        }
        throw std::exception();
    }
}
