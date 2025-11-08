#pragma once

#include <assert.h>
#include <unordered_map>
#include <vector>

namespace TeaPacket
{
    /// Like a FixedArray, but it does not own the data it contains.
    /// BorrowedFixedArray will not delete its data! Be sure to free this yourself.
    template<typename T>
    class BorrowedFixedArray
    {
    public:
        T* data = nullptr;
        const size_t size;

        explicit BorrowedFixedArray(T* data, const size_t size):
        data(data),
        size(size)
        {}

        T& operator [](size_t x)
        {
            return data[x];
        }

        T operator [](size_t x) const
        {
            return data[x];
        }

        size_t SizeOf() const
        {
            return sizeof(T) * size;
        }

        // ITERATORS
        T* begin() { return data; }
        T* end() { return &data[size-1]; }
        T const* begin() const { return data; }
        T const* end() const { return &data[size-1]; }
    };

    template<>
    class BorrowedFixedArray<void>
    {
    public:
        void* data = nullptr;
        const size_t size;

        explicit BorrowedFixedArray(void* data, const size_t size):
        data(data),
        size(size)
        {}
        
    };
}