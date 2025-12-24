#include "TeaPacket/Input/InputFunctions.hpp"

#include <GameInput.h>

#include "TeaPacket/Input/GameInputGlobal.hpp"
#include "TeaPacket/Input/InputDevice.hpp"
#include "TeaPacket/Input/PlatformInputDevice.hpp"
#include "TeaPacket/Input/InputButtonInfo/IsMouse.hpp"
#include "TeaPacket/Input/GameInput/VirtualKey.gen"
#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

using namespace TeaPacket;

static bool MouseGetButtonPressed(const InputDevice* device, const InputButtonType button)
{
    if (!IsMouseButton(button)) { return false; }
    const GameInputMouseState* state =
        std::any_cast<GameInputMouseState>(&device->controllerData);

    switch (button)
    {
        using enum InputButtonType;
    case MOUSE_LEFT:
        return state->buttons & GameInputMouseLeftButton;
    case MOUSE_RIGHT:
        return state->buttons & GameInputMouseRightButton;
    case MOUSE_MIDDLE:
        return state->buttons & GameInputMouseMiddleButton;
    default: return false;
    }
}

static void MousePollInput(InputDevice* device)
{
    CheckErrorWinCom(
        gameInput->GetCurrentReading(
            GameInputKindMouse,
            device->platformDevice->inputDevice,
            device->platformDevice->reading.ReleaseAndGetAddressOf())
    );
    GameInputMouseState* state =
        std::any_cast<GameInputMouseState>(&device->controllerData);
    device->platformDevice->reading->GetMouseState(state);
}

InputDevice* Input::CreateMouseDevice()
{
    return &inputDevices.emplace_back(InputDeviceParameters{
            .PollInputFunction = MousePollInput,
            .GetButtonFunction = MouseGetButtonPressed,
            .GetNameFunction = GenericInputDeviceGetName,
            .isPhysical = true,
            .controllerData = GameInputMouseState()
        });
}
