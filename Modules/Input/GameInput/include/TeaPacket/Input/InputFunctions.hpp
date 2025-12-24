#pragma once

#include <cstdint>
#include <string_view>

namespace TeaPacket::Input
{
    class InputDevice;
    enum class InputButtonType : uint32_t;

    std::string_view GenericInputDeviceGetName(const InputDevice* device);

    InputDevice* CreateKeyboardDevice();
    
}
