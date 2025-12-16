#pragma once

#include <windows.h>

namespace TeaPacket::Window
{
    struct PlatformWindow
    {
        /// The Win32 HWND this Window uses.
        HWND windowHandle;

        // Ugly Hack
        static inline bool shouldQuit = false;
    };
}