#pragma once
#include <memory>


namespace TeaPacket::Graphics
{
    struct UniformBufferParameters;
    struct PlatformUniformBuffer;

    class UniformBuffer
    {
    private:
        size_t size;
    public:

        std::unique_ptr<PlatformUniformBuffer> platformBuffer;

        [[nodiscard]] constexpr decltype(size) GetSize() const { return size; }

        explicit UniformBuffer(const UniformBufferParameters& parameters);
        ~UniformBuffer();
        
        void SendData(const void* data);
        void SetActive(size_t index);
    };
}
