#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"

#include <stdexcept>

using namespace TeaPacket::Graphics;

[[nodiscard]] size_t ShaderVariableType::GetSize() const
{
    switch (this->baseType)
    {
        using enum ShaderVariableBaseType;
    case Float:
        return sizeof(float) * this->amount;
    case Int:
        return sizeof(int) * this->amount;
    case UInt:
        return sizeof(unsigned int) * this->amount;
    }
    throw std::runtime_error("BAD VALUE");
}
