#pragma once

#include <mutex>

namespace TeaPacket
{
    /// A simple container for a mutex and a value. Does not enforce anything, so make sure to lock the mutex before accessing the value.
    template<typename T>
    class MutexPair
    {
    public:
        T v;
        std::mutex m;
    };
}