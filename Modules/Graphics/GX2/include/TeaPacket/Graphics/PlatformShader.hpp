#pragma once

#include "GraphicsHeap/MEM2Resource.hpp"

namespace TeaPacket::Graphics
{
    struct PlatformShader
    {
        std::unique_ptr<GX2VertexShader> vertexShader;
        std::unique_ptr<GX2PixelShader> pixelShader;

        GX2FetchShader fetchShader;
        GX2::MEM2Resource<void> fetchShaderMemory;
    };
}
