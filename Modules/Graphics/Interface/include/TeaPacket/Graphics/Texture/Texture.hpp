#pragma once
#include <memory>

namespace TeaPacket::Graphics
{
    struct PlatformTexture;
    struct TextureParameters;
    class TextureData;
    enum class TextureFormat : unsigned short;

    /// Represents a texture on the GPU.
    class Texture
    {
    public:
        /// Gets the width of the texture.
        [[nodiscard]] uint16_t GetWidth() const { return width; }
        /// Gets the height of the texture.
        [[nodiscard]] uint16_t GetHeight() const { return height; }

        /// A pointer to the implementation-defined data this texture uses.
        std::unique_ptr<PlatformTexture> platformTexture;

        /// Creates a texture using parameters.
        explicit Texture(const TextureParameters& parameters);
        Texture(Texture&& source) noexcept;
        ~Texture();

        /// Get the pixel data of this texture. Only works if cpuReadable is set when this texture is created.
        [[nodiscard]] TextureData GetData() const;
        /// Binds this texture to the specified texture slot, to be used whenever DrawMesh() is called.
        void SetActive(uint8_t index);
    private:

        uint16_t width, height;
        TextureFormat format;

    public:
        
    };
}
