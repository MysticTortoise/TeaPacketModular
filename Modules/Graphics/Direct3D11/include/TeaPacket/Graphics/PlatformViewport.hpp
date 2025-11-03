#pragma once

#pragma once

#include <d3d11.h>

#include "wrl/client.h"


namespace TeaPacket::Graphics
{
    struct PlatformViewport
    {
        Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView = nullptr;
        Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView = nullptr;
        Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilState = nullptr;

        D3D11_VIEWPORT d3dViewport;
    };
}
