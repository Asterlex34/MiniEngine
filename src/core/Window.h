#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <cstdint>

namespace MiniEngine
{
    struct WindowProperties
    {
        const char* Title;
        uint32_t Width;
        uint32_t Height;

        WindowProperties(const char* title = "Mini Engine", uint32_t width = 800, uint32_t height = 400)
            : Title(title), Width(width), Height(height) {}
    };

    class MiniWindow
    {
        public:
            virtual ~MiniWindow() {};
            virtual void OnUpdate() = 0;
            virtual void OnDraw() = 0;
            virtual void OnClose() = 0;
            virtual uint32_t GetWidth() const = 0;  
            virtual uint32_t GetHeight() const = 0;

            static std::unique_ptr<MiniWindow> Create(const WindowProperties& props = WindowProperties());
    };
}

#endif /* WINDOW_H */