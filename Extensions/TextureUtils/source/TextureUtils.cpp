#include "TeaPacket/TextureUtils/TextureUtils.hpp"

template <>
Color TeaPacket::TextureUtils::GetPixel<TeaPacket::Graphics::TextureFormat::RGBA8>(TP_TexUtilsParams)
{
    const unsigned char* r = &texData[y * pitch * 4 + x * 4];
    return Color{*r, r[1], r[2], r[3]};
}

template <>
Color TeaPacket::TextureUtils::GetPixel<TeaPacket::Graphics::TextureFormat::BGRA8>(TP_TexUtilsParams)
{
    const unsigned char* r = &texData[y * pitch * 4 + x * 4];
    return Color{*r, r[3], r[2], r[1]};
}