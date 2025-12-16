#pragma once

namespace TeaPacket
{
    /// @brief A wrapper around a pointer to an array with information about how large the array is.
    /// @details BorrowedFixedArray does not own the data it represents.
    /// It cannot resize the data, but it is allowed to modify it.
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

        [[nodiscard]] size_t SizeOf() const
        {
            return sizeof(T) * size;
        }

        // ITERATORS
        T* begin() { return data; }
        T* end() { return &data[size]; }
        T const* begin() const { return data; }
        T const* end() const { return &data[size]; }
    };

    /// @brief Template override for a void BorrowedFixedArray.
    /// @details Data cannot be modified directly via this BorrowedFixedArray, but it is still useful in some cases.
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