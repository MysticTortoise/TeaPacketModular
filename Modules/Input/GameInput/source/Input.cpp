#include "TeaPacket/Input/Input.hpp"

#include <GameInput.h>

#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

#include "TeaPacket/Input/GameInputGlobal.hpp"
#include "TeaPacket/Input/InputDevice.hpp"
#include "TeaPacket/Input/InputFunctions.hpp"
#include "TeaPacket/Input/PlatformInputDevice.hpp"
#include "TeaPacket/Logging/Logging.hpp"

using namespace TeaPacket;
using namespace TeaPacket::Input;

enum class ControllerType : uint8_t
{
    Keyboard = 0
};
constexpr ControllerType controllerTypes[] = {
    ControllerType::Keyboard
};

static void CALLBACK OnGameInputDeviceConnectedDisconnected(
    [[maybe_unused]] _In_ const GameInputCallbackToken callbackToken,
    [[maybe_unused]] _In_ void * context,
    [[maybe_unused]] _In_ IGameInputDevice * device,
    [[maybe_unused]] _In_ const uint64_t timestamp,
    [[maybe_unused]] _In_ const GameInputDeviceStatus currentStatus,
    [[maybe_unused]] _In_ const GameInputDeviceStatus previousStatus)
{
    const GameInputDeviceInfo* info = nullptr;
    CheckErrorWinCom(device->GetDeviceInfo(&info));
    
    if (currentStatus == GameInputDeviceConnected && previousStatus == GameInputDeviceNoStatus)
    {
        
        InputDevice* inputDevice = nullptr;
        switch (*static_cast<ControllerType*>(context))
        {
            using enum ControllerType;
        case Keyboard:
            inputDevice = CreateKeyboardDevice();
            break;
        default: throw std::exception("NOT VALID CONTEXT");
        }
        
        inputDevice->platformDevice = std::make_unique<PlatformInputDevice>(PlatformInputDevice{
            .inputDevice = device,
            .reading = nullptr,
        });
        
    } else if (currentStatus == GameInputDeviceNoStatus)
    {
        for (auto i = inputDevices.begin(); i != inputDevices.end(); ++i)
        {
            if (i->platformDevice->inputDevice == device)
            {
                inputDevices.erase(i);
                return;
            }
        }
    }
}


static GameInputCallbackToken callbackToken;

void Input::Initialize()
{
    CheckErrorWinCom(
        GameInputCreate(gameInput.GetAddressOf())
    );
    
    CheckErrorWinCom(gameInput->RegisterDeviceCallback(
        nullptr,
        GameInputKindKeyboard,
        GameInputDeviceConnected,
        GameInputBlockingEnumeration,
        (void*)&controllerTypes[static_cast<size_t>(ControllerType::Keyboard)],
        OnGameInputDeviceConnectedDisconnected,
        &callbackToken
    ));

}

void Input::DeInitialize()
{
    gameInput->UnregisterCallback(callbackToken);
    //gameInput->Release();
}