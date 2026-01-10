#include <iostream>

#include "TeaPacket/Assets/ReadAsset.hpp"
#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Logging/Logging.hpp"

using namespace TeaPacket;

int main()
{
    System::Initialize();
    Logging::Initialize();
    

    LogString(Assets::ReadTextFile("test.txt"));
    LogString(Assets::ReadTextFile("dir/test2.txt"));
    const std::vector<unsigned char> data = Assets::ReadBinaryFile("test.byt");
    for (const unsigned char character : data)
    {
        Log(static_cast<int>(character));
        Log(static_cast<char>(character));
    }
    LogString("HEYA");
    while (System::ShouldRun())
    {
        System::ProcessSystem();
    }

    Logging::DeInitialize();
    System::DeInitialize();
}