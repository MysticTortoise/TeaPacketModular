#pragma once
#include <gx2r/buffer.h>


namespace TeaPacket::Graphics
{

    struct PlatformUniformBuffer
    {
        GX2::MEM2Resource<void> data;
    };
}
