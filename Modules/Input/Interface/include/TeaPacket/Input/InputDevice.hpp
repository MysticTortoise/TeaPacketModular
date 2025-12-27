#pragma once

#include <string_view>
#include <memory>
#include <vector>

#include <functional>

#include "TeaPacket/Input/InputButtons.hpp"
#include "TeaPacket/Input/InputDeviceParameters.hpp"
namespace TeaPacket::Input
{
    struct PlatformInputDevice;
    enum class InputButtonType : uint32_t;
    enum class InputAxisType : uint16_t;
    
    class InputDevice
    {
    private:
        std::function<void(InputDevice*)> PollInputFunction;
        std::function<bool(const InputDevice*, InputButtonType)> GetButtonFunction;
        std::function<float(const InputDevice*, InputAxisType)> GetAxisFunction;
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
        [[nodiscard]] float GetAxis(const InputAxisType axis) const
        {
            return GetAxisFunction(this, axis);
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
        [[nodiscard]] static float GetAxisFromAnyDevice(const InputAxisType axis)
        {
            for (const auto& device : GetDevices())
            {
                if (const float val = device->GetAxis(axis); val != std::numeric_limits<float>::infinity())
                {
                    return val;
                }
            }
            return std::numeric_limits<float>::infinity();
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
