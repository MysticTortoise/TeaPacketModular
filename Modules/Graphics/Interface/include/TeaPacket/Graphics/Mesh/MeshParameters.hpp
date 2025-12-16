#pragma once
#include <cstdint>
#include <optional>

#include "TeaPacket/Types/Enums/PrimitiveTypes.hpp"
#include "TeaPacket/Types/Memory/BorrowedFixedArray.hpp"

namespace TeaPacket::Graphics
{
    /// Represents an attribute on the GPU that a vertex can have.
    struct VertexDataInfo
    {
        /// The primitive type that this attribute uses.
        PrimitiveType type;
        /// @brief The size of the vector this attribute is.
        /// @details As an example, a type of PrimitiveType::Float with a size of 4 would represent a vec4/float4.
        uint16_t size;


        [[nodiscard]] constexpr size_t SizeOf() const
        {
            return SizeOfPrimitiveType(type) * size;
        }
    };

    /// All the flags a mesh uses, grouped for packing purposes.
    struct MeshFlags
    {
        /// @brief Whether this mesh uses indices or not.
        /// @todo Do we need to keep this? Can this be replaced by just checking if indices is given?
        bool useIndices;
    };

    /// The parameters a mesh requires on creation.
    struct MeshParameters
    {
        /// The flags of the mesh.
        MeshFlags flags;
        /// A pointer to the vertex data this mesh uses.
        BorrowedFixedArray<void> vertexData;
        /// A list of VertexDataInfos that describe each vertex of the mesh.
        std::vector<VertexDataInfo> vertexInfo;
        /// An optional pointer to the face data this mesh uses.
        std::optional<BorrowedFixedArray<unsigned long>> indices;
    };
}