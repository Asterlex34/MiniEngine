#ifndef LINUXWINDOW_CPP
#define LINUXWINDOW_CPP

#include "LinuxWindow.h"
#include  <SDL2/SDL.h>

namespace MiniEngine
{
    static std::unique_ptr<MiniWindow> LinuxWindow::Create(const WindowProperties& props)
    {
        
    }
}

#endif /* LINUXWINDOW_CPP */

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