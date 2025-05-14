#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include "../../Window.h"
#include <memory>

namespace MiniEngine
{
    class LinuxWindow : public MiniEngine::MiniWindow
    {
        public:
            virtual ~MiniWindow();
            virtual void OnUpdate() = 0;
            virtual void OnDraw() = 0;
            virtual void OnClose() = 0;
            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;
            static std::unique_ptr<MiniWindow> Create(const WindowProperties& props = WindowProperties());
    };
}

#endif /* LINUXWINDOW_H */
