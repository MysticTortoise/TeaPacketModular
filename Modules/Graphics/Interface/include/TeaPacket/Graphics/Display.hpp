#pragma once
#include <vector>
#include <memory>

#include "TeaPacket/Graphics/Viewport.hpp"

namespace TeaPacket::Graphics{

    struct PlatformDisplay;
    struct DisplayParameters;

    /// @brief Represents a user-viewable area.
    class Display{
        public:

        [[nodiscard]] uint16_t GetWidth() const {return viewport.GetWidth(); }
        [[nodiscard]] uint16_t GetHeight() const { return viewport.GetHeight(); }

        [[nodiscard]] Viewport* GetViewport() { return &viewport; }

        explicit Display(const DisplayParameters& parameters);
        ~Display();

        void PresentDisplay();

        std::unique_ptr<PlatformDisplay> platformDisplay;

        private:
        Viewport viewport;


    public:
        static void InitializeDefaultDisplays(const std::vector<DisplayParameters>& requestedParameters);
        static [[nodiscard]] size_t GetDisplayCount() { return Displays.size(); }
        static [[nodiscard]] Display* GetDisplay(const unsigned char index) { return Displays[index].get(); }
        static void DeInitialize();

    private:
        static inline std::vector<std::unique_ptr<Display>> Displays = {};
    };
}
