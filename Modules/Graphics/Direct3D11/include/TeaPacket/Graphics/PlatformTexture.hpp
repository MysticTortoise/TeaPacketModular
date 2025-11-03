#pragma once

#include "wrl/client.h"
#include <d3d11.h>

namespace TeaPacket::Graphics
{


    struct PlatformTexture
    {
        Microsoft::WRL::ComPtr<ID3D11Texture2D> texture2D = nullptr;
        Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> shaderResourceView = nullptr;
        Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState = nullptr;
    };
}
