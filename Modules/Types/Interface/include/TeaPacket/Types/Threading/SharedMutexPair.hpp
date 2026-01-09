#pragma once

#include <shared_mutex>

namespace TeaPacket
{
    /// Like MutexPair, but for a shared_mutex. Preferable for when data will be written to by some threads and read from by other threads.
    template<typename T>
    class SharedMutexPair
    {
    public:
        T v;
        std::shared_mutex m;
    };
}