#include <algorithm>

#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/Graphics/DisplayParameters.hpp"
#include "TeaPacket/Graphics/Mesh/Mesh.hpp"
#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Core/Core.hpp"
#include "TeaPacket/Input/Input.hpp"
#include "TeaPacket/Input/InputAxis.hpp"
#include "TeaPacket/Input/InputButtons.hpp"
#include "TeaPacket/Input/InputDevice.hpp"
#include "TeaPacket/Logging/Logging.hpp"
#include "TeaPacket/Window/Window.hpp"

using namespace TeaPacket;
using namespace TeaPacket::Graphics;
//using namespace TeaPacket::Input;

int main()
{
    TeaPacket::Initialize();
    auto dispParams = DisplayParameters{.width = 1280, .height = 720};
    Display::InitializeDefaultDisplays({dispParams});
    
    while (System::ShouldRun())
    {
        System::ProcessSystem();
        Display::BeginRender(0);
        
        Input::InputDevice::PollAllDevices();
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        if (Input::InputDevice::AnyDeviceHasButtonPressed(Input::InputButtonType::KEY_ENTER))
        {
            b = 255;
        }
        for (const auto& device : Input::InputDevice::GetDevices())
        {
            if (const float val = device->GetAxis(Input::InputAxisType::POINTER_X);
                val != std::numeric_limits<float>::infinity() && val != 0.0f)
            {
                r = static_cast<uint8_t>(std::clamp<float>(val * 255, 0, 255));
            }
            if (const float val = device->GetAxis(Input::InputAxisType::POINTER_Y);
                val != std::numeric_limits<float>::infinity() && val != 0.0f)
            {
                g = static_cast<uint8_t>(std::clamp<float>(val * 255, 0, 255));
            }
            
        }
        
        Viewport::ClearColor(r,g,b);
        Display::FinishRender(0);
        Display::PresentAll();
        
    }
    TeaPacket::DeInitialize();
}