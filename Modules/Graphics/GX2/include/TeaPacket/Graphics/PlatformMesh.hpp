#pragma once

#include <gx2r/buffer.h>

#include <vector>



namespace TeaPacket::Graphics
{
    struct PlatformMesh
    {
        std::vector<GX2RBuffer> buffers;
        std::vector<uint32_t> indexBuffer;

        size_t indexCount = 0;
    };
}
