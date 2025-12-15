#include "TeaPacket/Graphics/Graphics.hpp"

#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/Graphics/DisplayParameters.hpp"
#include "TeaPacket/Logging/Logging.hpp"

using namespace TeaPacket;
using namespace TeaPacket::Graphics;

int main()
{
    TeaPacket::Initialize();

    auto dispParams = DisplayParameters{.width = 1280, .height = 720};
    Display::InitializeDefaultDisplays({dispParams});

    while (System::ShouldRun())
    {
        System::ProcessSystem();
        Display::WaitForVSync();
        static uint16_t number = 0;
        number = (number + 1) % 255;
        
        Display::BeginRender(0);
        Display::FinishRender(0);
        Display::BeginRender(1);
        Viewport::ClearColor(number, 0, 0);
        Display::FinishRender(1);
        Display::PresentAll();
    }
    
    TeaPacket::DeInitialize();
}