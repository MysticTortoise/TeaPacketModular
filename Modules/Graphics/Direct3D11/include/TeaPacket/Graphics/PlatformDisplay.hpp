#pragma once

#include <dxgi.h>

#include "wrl/client.h"

namespace TeaPacket::Window
{
    class Window;
}

namespace TeaPacket::Graphics
{
    struct PlatformDisplay
    {
        std::unique_ptr<Window::Window> window;

        Microsoft::WRL::ComPtr<IDXGISwapChain> swapchain;
    };
}
