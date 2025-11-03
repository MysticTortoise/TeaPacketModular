#pragma once

#include <string>

namespace TeaPacket
{
    namespace Graphics
    {
        class Display;
    }

    namespace Window
    {
        /// @brief Contains parameters for a Window on creation.
        struct WindowParameters
        {
            /// X position of the left side of the Window, in pixels, from the left side of the desktop.
            unsigned short x;
            /// Y position of the top of the Window, in pixels, from the top of the desktop.
            unsigned short y;
            /// Width of the Window, in pixels.
            unsigned short width;
            /// Height of the Window, in pixels.
            unsigned short height;

            /// The Window's title, typically displayed on the top bar above the window.
            std::string title;

            /// The Graphics::Display that this Window is linked to.
            Graphics::Display* display;
        };
    }
}
