#pragma once
#include "TeaPacket/Graphics/Texture/Texture.hpp"

#include <string>

namespace TeaPacket::Extensions::STBImageLoader
{
    Graphics::Texture LoadImage(const std::string& assetPath, const Graphics::TextureParameters& wantParams);
}
