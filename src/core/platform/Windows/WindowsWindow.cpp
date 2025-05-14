#ifndef WINDOWSWINDOW_CPP
#define WINDOWSWINDOW_CPP

#include "WindowsWindow.h"

namespace MiniEngine
{
    std::unique_ptr<WindowsWindow> MiniWindow::Create(const WindowProperties& props)
    {
        return std::make_unique<WindowsWindow>(props);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& windowProps)
    {
        Init(windowProps);
    }

    bool WindowsWindow::Init(const WindowProperties& windowProps)
    {
        m_Data.height = windowProps.Height;
        m_Data.width = windowProps.Width;
        m_Data.title = windowProps.Title;
    }
}

#endif /* WINDOWSWINDOW_CPP */
