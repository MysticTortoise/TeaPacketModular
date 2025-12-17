#pragma once

#include "d3d11.h"
#include "wrl/client.h"

namespace TeaPacket::Graphics
{
    inline Microsoft::WRL::ComPtr<ID3D11Device> device = nullptr;
    inline Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext = nullptr;
    inline Microsoft::WRL::ComPtr<ID3D11RasterizerState> defaultRasterizerState = nullptr;
}