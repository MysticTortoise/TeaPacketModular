#pragma once

#include <wrl/client.h>
#include <d3d11.h>

namespace TeaPacket::Graphics
{


    struct PlatformUniformBuffer
    {
        Microsoft::WRL::ComPtr<ID3D11Buffer> cbuffer;
    };
}
