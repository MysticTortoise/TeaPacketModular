#pragma once

#include <d3d11.h>
#include <wrl/client.h>

namespace TeaPacket::Graphics
{

    struct PlatformMesh
    {
        Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
        Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;

        UINT vertexSize;
        UINT indexCount;
    };
}