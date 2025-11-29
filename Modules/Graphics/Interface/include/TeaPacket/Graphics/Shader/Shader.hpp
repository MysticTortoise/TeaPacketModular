#pragma once
#include <vector>
#include <memory>


namespace TeaPacket::Graphics
{
    struct VertexDataInfo;
    struct ShaderParameters;
    struct PlatformShader;

    /// Represents a combined vertex and fragment shader on the GPU.
    class Shader
    {
    public: // Member Variables

        /// A pointer to the implementation-specific data this shader uses.
        std::unique_ptr<PlatformShader> platformShader;
    private:
        /// A list of the sizes of each Uniform Buffer this shader supports.
        std::vector<size_t> uniformBufferSizes{};
        
    public: // Static Variables
        /// The currently active shader that will be used when DrawMesh() is called.
        static inline Shader* activeShader = nullptr;
    
        
    public: // Member Functions
        /// Creates a shader via parameters
        explicit Shader(const ShaderParameters& parameters);
        ~Shader();

        /// Updates a Uniform Buffer on the GPU using this shader's uniform buffer size info.
        void SendUniformBuffer(const unsigned char* data, size_t bufferIndex);

        /// Sets this shader to be the currently active shader to be used in future DrawMesh() calls.
        void SetActive();

    public: // Static Functions
    };
}