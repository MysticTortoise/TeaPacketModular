#pragma once
#include <string>

/// @brief Functions related to reading data from the disk.
/// @details Assets available through the Assets module are read-only and should not be modified.
namespace TeaPacket::Assets
{

    /// @brief Reads an entire text file into a string.
    /// @param assetPath The path of the asset. Where this asset is stored is implementation-defined.
    std::string ReadTextFile(const std::string& assetPath);
}
