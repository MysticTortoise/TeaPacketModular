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
    Keyboard = 0,
    Mouse = 1,
    COUNT
};
constexpr ControllerType controllerTypes[static_cast<size_t>(ControllerType::COUNT)] = {
    ControllerType::Keyboard,
    ControllerType::Mouse,
};

GameInputCallbackToken callbackTokens[static_cast<size_t>(ControllerType::COUNT)] = {};

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
        case Mouse:
            inputDevice = CreateMouseDevice();
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

static void RegisterCallback(const GameInputKind kind, const ControllerType controllerType)
{
    CheckErrorWinCom(gameInput->RegisterDeviceCallback(
        nullptr,
        kind,
        GameInputDeviceConnected,
        GameInputBlockingEnumeration,
        (void*)&controllerTypes[static_cast<size_t>(controllerType)],
        OnGameInputDeviceConnectedDisconnected,
        &callbackTokens[static_cast<size_t>(controllerType)]
    ));
}

void Input::Initialize()
{
    CheckErrorWinCom(
        GameInputCreate(gameInput.GetAddressOf())
    );
    
    RegisterCallback(GameInputKindKeyboard, ControllerType::Keyboard);
    RegisterCallback(GameInputKindMouse, ControllerType::Mouse);

}

void Input::DeInitialize()
{
    for (const GameInputCallbackToken callbackToken : callbackTokens)
    {
        gameInput->UnregisterCallback(callbackToken);
    }
    //gameInput->Release();
}