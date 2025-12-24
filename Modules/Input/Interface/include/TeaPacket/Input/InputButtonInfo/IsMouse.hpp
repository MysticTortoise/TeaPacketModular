#pragma once

#include <cstdint>

#include "TeaPacket/Input/InputButtons.hpp"

namespace TeaPacket::Input
{
    
    constexpr bool IsMouseButton(const InputButtonType button)
    {
        switch (button)
        {
            using enum InputButtonType;
        case MOUSE_LEFT:
        case MOUSE_RIGHT:
        case MOUSE_MIDDLE:
            return true;
        default:
            return false;
        }
    }
}
