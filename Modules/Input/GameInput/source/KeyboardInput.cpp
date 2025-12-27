#include "TeaPacket/Input/InputFunctions.hpp"

#include <GameInput.h>

#include "TeaPacket/Input/GameInputGlobal.hpp"
#include "TeaPacket/Input/InputDevice.hpp"
#include "TeaPacket/Input/PlatformInputDevice.hpp"
#include "TeaPacket/Input/InputButtonInfo/IsKeyboard.hpp"
#include "TeaPacket/Input/GameInput/VirtualKey.gen"
#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

using namespace TeaPacket;

static bool KeyboardGetButtonPressed(const InputDevice* device, const InputButtonType button)
{
    if (!IsKeyboardButton(button)) { return false; }

    const uint8_t virtualKey = InputButtonTypeToVK(button);
    
    for (const GameInputKeyState& keyState :
        std::any_cast<std::vector<GameInputKeyState>>(device->controllerData))
    {
        if (keyState.virtualKey == virtualKey)
        {
            return true;
        }
    }
    return false;
}

static float KeyboardGetAxis(const InputDevice* device, const InputAxisType axis)
{
    (void)device;
    (void)axis;
    return 0.0f;
}

static void KeyboardPollInput(InputDevice* device)
{
    CheckErrorWinCom(
        gameInput->GetCurrentReading(
            GameInputKindKeyboard,
            device->platformDevice->inputDevice,
            device->platformDevice->reading.ReleaseAndGetAddressOf())
    );
    const uint32_t keyCount = device->platformDevice->reading->GetKeyCount();
    auto* keyboardState =
        std::any_cast<std::vector<GameInputKeyState>>(&device->controllerData);
    
    keyboardState->resize(keyCount);
    device->platformDevice->reading->GetKeyState(
        keyCount,
        keyboardState->data()
        );
}

InputDevice* Input::CreateKeyboardDevice()
{
    return &inputDevices.emplace_back(InputDeviceParameters{
            .PollInputFunction = KeyboardPollInput,
            .GetButtonFunction = KeyboardGetButtonPressed,
            .GetAxisFunction = KeyboardGetAxis,
            .GetNameFunction = GenericInputDeviceGetName,
            .isPhysical = true,
            .controllerData = std::vector<GameInputKeyState>()
        });
}
