#pragma once

#include <string_view>
#include <memory>
#include <vector>

#include <functional>

#include "InputButtons.hpp"
#include "InputDeviceParameters.hpp"

namespace TeaPacket::Input
{
    struct PlatformInputDevice;
    enum class InputButtonType : uint32_t;
    
    class InputDevice
    {
    private:
        std::function<void(InputDevice*)> PollInputFunction;
        std::function<bool(const InputDevice*, InputButtonType)> GetButtonFunction;
        std::function<std::string_view(const InputDevice*)> GetNameFunction;
    
    public:
        explicit InputDevice(const InputDeviceParameters& parameters);
        
        std::unique_ptr<PlatformInputDevice> platformDevice;
        std::any controllerData;

        [[nodiscard]] std::string_view GetName() const
        {
            return GetNameFunction(this);
        }

        void PollInput()
        {
            PollInputFunction(this);
        }
        [[nodiscard]] bool GetButtonPressed(const InputButtonType button) const
        {
            return GetButtonFunction(this, button);
        }

    public:

        static std::vector<InputDevice*> GetDevices();

        
        [[nodiscard]] static bool AnyDeviceHasButtonPressed(const InputButtonType button)
        {
            for (const auto & device : GetDevices())
            {
                if (device->GetButtonPressed(button))
                {
                    return true;
                }
            }
            return false;
        }
        static void PollAllDevices()
        {
            for (const auto & device : GetDevices())
            {
                device->PollInput();
            }
        }
    };
}
