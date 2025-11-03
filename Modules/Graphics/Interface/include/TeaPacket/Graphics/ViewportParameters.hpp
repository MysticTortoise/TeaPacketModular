#pragma once

#include <cstdint>

namespace TeaPacket::Graphics
{
    class Display;
    struct ViewportFlags{
        bool shaderUsable : 1 = false;
    };
    struct ViewportParameters
    {
        uint16_t width;
        uint16_t height;
        ViewportFlags flags;
        Display* ownedDisplay = nullptr;
    };
}
