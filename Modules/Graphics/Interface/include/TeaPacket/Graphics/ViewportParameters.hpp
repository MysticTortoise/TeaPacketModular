#pragma once

#include <cstdint>

namespace TeaPacket::Graphics
{
    class Display;

    /// The flags used by a viewport on creation, packed into a single struct.
    struct ViewportFlags{
        /// Whether the textures in this viewport can be used by shaders.
        bool shaderUsable : 1 = false;
    };

    /// The parameters a viewport takes on creation.
    struct ViewportParameters
    {
        /// The width of the viewport.
        uint16_t width;
        /// The height of the viewport.
        uint16_t height;
        /// The flags used by this viewport.
        ViewportFlags flags;
        /// @brief The display that owns this viewport, if applicable.
        /// @details If nullptr, this Viewport does not belong to a display.
        Display* ownedDisplay = nullptr;
    };
}
