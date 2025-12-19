#pragma once

#include <gx2/sampler.h>
#include <gx2/texture.h>

namespace TeaPacket::Graphics
{
    
    struct PlatformTexture
    {
        GX2Texture gx2Texture;
        GX2Sampler gx2Sampler;

        bool isPartOfViewport : 1 = false;
    };
}
