#pragma once


namespace TeaPacket::Graphics
{

    struct UniformBufferParameters
    {
        /// The starting data this buffer should be filled with. If this is nullptr, then the data will be initialized to all 0.
        void* data;
        /// The size of this buffer, in bytes.
        size_t size;
    };
}
