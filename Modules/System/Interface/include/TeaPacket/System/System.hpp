#pragma once
#include <atomic>

namespace TeaPacket::System
{
    void Initialize();
    void DeInitialize();
    void ProcessSystem();

    inline std::atomic_bool isRunning = true;
}
