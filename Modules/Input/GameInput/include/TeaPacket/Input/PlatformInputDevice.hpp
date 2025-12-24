#pragma once

#include <wrl/client.h>
#include <GameInput.h>

namespace TeaPacket::Input
{
    struct PlatformInputDevice
    {
        IGameInputDevice* inputDevice;
        Microsoft::WRL::ComPtr<IGameInputReading> reading;
    };
}
