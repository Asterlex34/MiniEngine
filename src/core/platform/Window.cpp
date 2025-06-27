#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "Window.h"
#include <memory>

#if defined(_WIN32)
#include "platform/Windows/WindowsWindow.h"
#elif defined(__linux__)
#include "platform/Linux/LinuxWindow.h"
#else
#error Unsupported platform
#endif

namespace MiniEngine
{
    std::unique_ptr<MiniWindow> MiniWindow::Create(const WindowProperties& props)
    {
        #if defined(_WIN32)
            return std::make_unique<WindowsWindow>(props);
        #elif defined(__linux__)
            return std::make_unique<LinuxWindow>(props);
        #else
            return nullptr;
        #endif
    }
}

#endif /* WINDOW_CPP */
