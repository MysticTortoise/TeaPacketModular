#pragma once
#include <memory>

#include "TeaPacket/Types/Memory/FixedArray.hpp"

namespace TeaPacket::Graphics
{
    struct VertexDataInfo;
    struct MeshParameters;
    struct PlatformMesh;

    class Mesh
    {
    public:

        std::unique_ptr<PlatformMesh> platformMesh;
        const bool hasIndex : 1 = false;

    public:
        static inline Mesh* activeMesh = nullptr;

    private:
        FixedArray<VertexDataInfo> vertexDataInfo;
        
    public:
        explicit Mesh(const MeshParameters& parameters);
        ~Mesh();

        void SetActive();
    };
}