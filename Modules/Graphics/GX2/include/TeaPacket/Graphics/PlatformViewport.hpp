#pragma once

#include <GraphicsHeap/DisposableForegroundResource.hpp>
#include <gx2/surface.h>

namespace TeaPacket::Graphics
{
    struct PlatformViewport
    {
        GX2ColorBuffer colorBuffer;
        GX2::DisposableForegroundMemResource colorBufferImage;
        
        GX2DepthBuffer depthBuffer;
        GX2::DisposableForegroundMemResource depthBufferImage;
    };
}
