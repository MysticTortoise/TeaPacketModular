#pragma once

#include <assert.h>
#include <unordered_map>
#include <vector>

namespace TeaPacket
{
    template<typename T>
    class FixedArray
    {
    public:
        T* data = nullptr;
        const size_t size;

        explicit FixedArray(const size_t size):
        data(new T[size]),
        size(size)
        {}

        ~FixedArray()
        {
            delete[] data;
        }

        T& operator [](size_t x)
        {
            return data[x];
        }

        T operator [](size_t x) const
        {
            return data[x];
        }

        // Copy Constructor
        FixedArray(const FixedArray& other):
        size(other.size),
        data(new T[other.size])
        {
            memcpy(data, other.data, size);
        }
        // Copy Assignment
        void operator=(const FixedArray& other)
        {
            assert(this != other);

            this->size = other.size;
            delete[] data;
            data = new T[other.size];
            memcpy(data, other.data, other.size);
        }

        // Move Constructor
        FixedArray(FixedArray&& src) noexcept :
        size(src.size)
        {
            std::swap(src.data, data);
        }
        // Move Assignment
        FixedArray& operator=(FixedArray&& src) noexcept
        {
            this->size = src.size;
            std::swap(src.data, data);
            return *this;
        }
    };
}