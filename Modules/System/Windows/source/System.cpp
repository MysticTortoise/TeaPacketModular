#include "TeaPacket/System/System.hpp"

#include "TeaPacket/Window/PlatformWindow.hpp"

using namespace TeaPacket;

#include "TeaPacket/Window/Window.hpp"
using namespace TeaPacket::Window;

void System::Initialize()
{

}

void System::DeInitialize()
{

}

void System::ProcessSystem()
{
    const size_t windowCount = Window::Window::GetWindowCount();
    for (size_t i = 0; i < windowCount; i++)
    {
        Window::Window* window = Window::Window::GetWindow(i);
        window->ProcessEvents();
    }
}

bool System::ShouldRun()
{
    return !PlatformWindow::shouldQuit;
}

