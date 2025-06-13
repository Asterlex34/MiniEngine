#ifndef WINDOWSWINDOW_CPP
#define WINDOWSWINDOW_CPP

#include "WindowsWindow.h"

#include <Windows.h>

// Minimal dummy window procedure since I don't want event handling as of now
LRESULT CALLBACK DummyWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

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
        hinst = GetModuleHandle(nullptr);
        static bool classRegistered = false;

        if (!classRegistered)
        {
            WNDCLASS wc = {};
            wc.lpfnWndProc   = DummyWndProc;
            wc.hInstance     = hinst;
            wc.lpszClassName = "MainEngineWindow";

            if (!RegisterClass(&wc))
            {
                return false;
            }

            classRegistered = true;
        }

        hwndMain = CreateWindowEx( 
            0,                     // no extended styles YET :3           
            "MainEngineWindow",    // class name                   
            m_Data.title,          // window name                  
            WS_OVERLAPPEDWINDOW,   // overlapped window                 
            CW_USEDEFAULT,         // default horizontal position  
            CW_USEDEFAULT,         // default vertical position    
            m_Data.width,          // default width                
            m_Data.height,         // default height               
            (HWND) nullptr,        // no parent Window
            (HMENU) nullptr,       // class menu used              
            hinst,                 // instance handle              
            nullptr                // no window creation data 
        );                      

        if (!hwndMain) { return false; }
        return true;
    }

    void WindowsWindow::Show()
    {
        ShowWindow(hwndMain, SW_SHOW);
        UpdateWindow(hwndMain);
    }
}

#endif /* WINDOWSWINDOW_CPP */
