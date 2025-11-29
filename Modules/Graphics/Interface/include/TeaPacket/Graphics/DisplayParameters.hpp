#pragma once

#include <cstdint>

namespace TeaPacket::Graphics
{
    /// Parameters used for creating a Display.
    struct DisplayParameters
    {
        /// The width of the display.
        uint16_t width;
        /// The height of the display.
        uint16_t height;
    };
}
