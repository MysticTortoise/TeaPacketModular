#pragma once
#include <cstdint>
#include <optional>
#include <string>

#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"
#include "TeaPacket/Types/Memory/FixedArray.hpp"
#include "TeaPacket/Types/Memory/BorrowedFixedArray.hpp"

namespace TeaPacket
{
    enum class PrimitiveType : unsigned char;
    
}

namespace TeaPacket::Graphics
{


    
    struct ShaderFlags
    {
        
    };

    struct ShaderParameters
    {
        ShaderFlags flags;
        const std::string& vertexShaderCode, fragmentShaderCode;
        FixedArray<ShaderVariableType>& inputAttributes;
        std::optional<FixedArray<ShaderVariableType>*> uniforms;
    };
}