#pragma once

#include <cstdint>

namespace TeaPacket::Graphics
{
    enum class TextureFormat : unsigned short;

    /// Defines where a texture is available.
    enum class TextureAvailableMode : unsigned char{
        None,
        GPU,
        CPU,
    };

    /// The flags a texture is created with, in a struct for packing purposes.
    struct TextureUseFlags
    {
        /// Whether this texture can be used as input for a shader.
        bool shaderResource : 1 = true;
        /// Whether this texture is a render target for color.
        bool renderTargetColor : 1 = false;
        /// Whether this texture is a render target for depth.
        bool renderTargetDepth : 1 = false;
        /// Determines which device is allowed to write to a texture.
        TextureAvailableMode writeMode : 2 = TextureAvailableMode::None;
        /// Determines whether the CPU can read from a texture.
        bool cpuReadable : 1 = false;
    };

    /// Determines the filter-mode of a texture.
    enum class TextureFilterMode : unsigned char{
        Nearest, ///< No filtering is applied. The texture appears pixelated.
        Linear ///< A linear filter is applied. The pixels are blended together linearly.
    };

    /// Determines how a texture is used when UV coordinates fall outside the 0-1 range.
    enum class TextureWrapMode : unsigned char {
        Wrap, ///< This texture wraps around starting from 0 after passing 1. Also known as Repeat.
        Clamp, ///< This texture uses the closest value from the 0-1 range after passing 0 or 1, causing stretching when past the 0-1 range.
        Mirror ///< This texture is mirrored and repeats every time a 0-1 border is passed. 
    };

    /// The parameters a Texture takes on creation.
    struct TextureParameters
    {
        /// A pointer to the raw data this texture uses.
        void* data;
        /// The width of the texture.
        uint16_t width;
        /// The height of the texture.
        uint16_t height;
        /// The format of the texture.
        TextureFormat format;
        /// The flags this texture uses.
        TextureUseFlags useFlags;
        /// The filter this texture uses.
        TextureFilterMode filterMode;
        /// The wrapping mode this texture uses.
        TextureWrapMode wrapMode;
    };
}
