#pragma once
#include <memory>

#include "TeaPacket/Types/Memory/FixedArray.hpp"
#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"

namespace TeaPacket::Graphics
{
    struct VertexDataInfo;
    struct ShaderParameters;
    struct PlatformShader;

    class Shader
    {
    public:

        std::unique_ptr<PlatformShader> platformShader;
        const bool hasIndex : 1 = false;
        //FixedArray<ShaderVariable> uniformVariables;

    public:
        static inline Shader* activeShader = nullptr;

    private:
        
    public:
        explicit Shader(const ShaderParameters& parameters);
        ~Shader();

        void SetActive();
    };
}