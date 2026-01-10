#pragma once
#include <cstdint>

#include "TeaPacket/Input/InputAxis.hpp"

namespace TeaPacket::Input
{
    constexpr bool IsGamepadAxis(const InputAxisType button)
    {
        return button > InputAxisType::START_PAD && button < InputAxisType::END_PAD;
    }
}
