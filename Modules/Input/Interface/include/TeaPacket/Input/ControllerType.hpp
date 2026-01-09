#pragma once
#include <cstdint>

namespace TeaPacket::Input
{
    /// Describes a general type of controller. Most consoles will only have Gamepad.
    enum class ControllerType : uint8_t{
        None, ///< None. Not a valid controller.
        Keyboard, ///< Represents a keyboard.
        Mouse, ///< Represents a mouse.
        Gamepad, ///< Represents a gamepad/controller of any kind.
        Misc, ///< Unknown controller type that doesn't fit into previous categories.
        Any = UINT8_MAX, ///< Any type. Not used by controllers, but can be used as a filter.
    };
}
