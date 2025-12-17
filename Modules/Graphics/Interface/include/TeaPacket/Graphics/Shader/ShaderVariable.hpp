#pragma once


#include <cstddef>

namespace TeaPacket::Graphics
{
    class Texture;

    /// A GPU-based PrimitiveType
    enum class ShaderVariableBaseType : unsigned char
    {
        Float,  ///< Single-precision float
        Int,    ///< Signed Integer
        UInt,    ///< Unsigned Integer
    };

    /// A GPU based variable type.
    struct ShaderVariableType
    {
        /// The primitive type this type uses.
        ShaderVariableBaseType baseType;
        /// The vector size of this type.
        unsigned char amount;

        /// Default constructor.
        constexpr ShaderVariableType():baseType(static_cast<ShaderVariableBaseType>(0)), amount(0) {}
        /// Parameterized Constructor
        constexpr ShaderVariableType(const ShaderVariableBaseType type, const unsigned char amount) : baseType(type), amount(amount){}

        /// Gets the GPU size of this ShaderVariableType.
        [[nodiscard]] size_t GetSize() const;
    };
    
}