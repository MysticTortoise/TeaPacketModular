#include "TeaPacket/Graphics/Graphics.hpp"
#include "TeaPacket/Graphics/WindowsGraphics.hpp"

#include <d3d11.h>

#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

using namespace TeaPacket;

static constexpr D3D_FEATURE_LEVEL d3dFeatureLevels[] = {
    D3D_FEATURE_LEVEL_11_1,
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
    D3D_FEATURE_LEVEL_9_3,
    D3D_FEATURE_LEVEL_9_2,
    D3D_FEATURE_LEVEL_9_1,
};

void Graphics::Initialize()
{
    UINT deviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if TP_DEBUG > 0
    deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif


    CheckErrorWinCom(
        D3D11CreateDevice(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            0,
            deviceFlags,
            d3dFeatureLevels,
            ARRAYSIZE(d3dFeatureLevels),
            D3D11_SDK_VERSION,
            device.ReleaseAndGetAddressOf(),
            NULL,
            deviceContext.ReleaseAndGetAddressOf()
        )
    );
}

void Graphics::DeInitialize()
{
    device.Reset();
    deviceContext.Reset();
    Display::DeInitialize();
}
