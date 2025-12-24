#include "TeaPacket/Input/InputDevice.hpp"

#include "TeaPacket/Input/GameInputGlobal.hpp"
#include "TeaPacket/Input/PlatformInputDevice.hpp"
#include "TeaPacket/Input/InputFunctions.hpp"
#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

using namespace TeaPacket::Input;

std::vector<InputDevice*> InputDevice::GetDevices()
{
    std::vector<InputDevice*> devices;
    devices.reserve(inputDevices.size());

    for (auto& device : inputDevices)
    {
        devices.emplace_back(&device);
    }
    return devices;
}

InputDevice::InputDevice(const InputDeviceParameters& parameters):
PollInputFunction(parameters.PollInputFunction),
GetButtonFunction(parameters.GetButtonFunction),
GetNameFunction(parameters.GetNameFunction),
controllerData(parameters.controllerData)
{
    if (parameters.isPhysical) { return; }
}

std::string_view TeaPacket::Input::GenericInputDeviceGetName(const InputDevice* device)
{
    const GameInputDeviceInfo* info;
    CheckErrorWinCom(device->platformDevice->inputDevice->GetDeviceInfo(&info));
    return info->displayName == nullptr ? "NULL" : std::string_view(info->displayName);
}