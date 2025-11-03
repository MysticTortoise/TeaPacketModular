#include "TeaPacket/Types/Memory/FixedArray.hpp"

#include <iostream>

TeaPacket::FixedArray<unsigned char> GetArr()
{
    TeaPacket::FixedArray<unsigned char> array(200);
    array[0] = 24;
    array[1] = 25;
    array[2] = 26;
    return array;
}

[[noreturn]] int main()
{
    std::cout << "START";
    TeaPacket::FixedArray<unsigned char> array = GetArr();
    std::cout << static_cast<int>(array[1]);
    std::cout << "FIN";
}