#pragma once

#include <string_view>

namespace TeaPacket::Input
{
    class InputDevice;

    std::string_view GenericInputDeviceGetName(const InputDevice* device);
    InputDevice* CreateKeyboardDevice();
    InputDevice* CreateMouseDevice();
    
}
