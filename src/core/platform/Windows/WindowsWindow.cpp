#ifndef WINDOWSWINDOW_CPP
#define WINDOWSWINDOW_CPP

#include "WindowsWindow.h"
#include "../../../../dependencies/thirdparty/glad/include/glad/gl.h"

#ifdef __cplusplus
extern "C" {
#endif
#include <Windows.h>
#ifdef __cplusplus
}
#endif

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    MiniEngine::WindowsWindow* windowPtr = reinterpret_cast<MiniEngine::WindowsWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

    switch (msg)
    {
        case WM_CREATE:
            {
                /* OPENGL FRAMEBUFFER */
                PIXELFORMATDESCRIPTOR pfd =
		        {
			        sizeof(PIXELFORMATDESCRIPTOR),
			        1,
			        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,       // Flags
			        PFD_TYPE_RGBA,                                                    // The kind of framebuffer. RGBA or palette.
			        32,                                                               // Colordepth of the framebuffer
			        0, 0, 0, 0, 0, 0,                                                 // rape blacks 
			        0,
			        0,
			        0,

			        0, 0, 0, 0,
			        24,                                                               // Number of bits for the depthbuffer
			        8,                                                                // Number of bits for the stencilbuffer
			        0,                                                                // Number of Aux buffers in the framebuffer.
			        PFD_MAIN_PLANE,
			        0,
			        0, 0, 0
		        };

                HDC hdc = GetDC(hWnd);
                int pixelFormatNumber = ChoosePixelFormat(hdc, &pfd);

                SetPixelFormat(hdc, pixelFormatNumber, &pfd);
                HGLRC HandleToOpenglContext = wglCreateContext(hdc);
                wglMakeCurrent(hdc, HandleToOpenglContext);
            }

        case WM_CLOSE:
            if (MessageBox(hWnd, "Really Quit?", "MiniEngine", MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hWnd);
            }
            return 0;

        case WM_DESTROY: 
            PostQuitMessage(0);
            return 0;
        
        case WM_PAINT:
            {
                if (windowPtr)
                {
                    windowPtr->OnDraw();
                }
                return 0;
            }
        
        case WM_SIZE:
            {
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);

                if (windowPtr)
                {
                    windowPtr->SetSize(width, height);
                    InvalidateRect(hwnd, nullptr, TRUE);
                }

                return 0;
            }

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

namespace MiniEngine
{
    WindowsWindow::WindowsWindow(const WindowProperties& windowProps)
    {
        Init(windowProps);
    }

    bool WindowsWindow::Init(const WindowProperties& windowProps)
    {
        m_Data.Height = windowProps.Height;
        m_Data.Width = windowProps.Width;
        m_Data.Title = windowProps.Title;
        hinst = GetModuleHandle(nullptr);
        static bool classRegistered = false;

        if (!classRegistered)
        {
            WNDCLASS wc = {};
            wc.lpfnWndProc   = WndProc;
            wc.hInstance     = hinst;
            wc.lpszClassName = "MainEngineWindow";
            wc.style = CS_OWNDC;

            if (!RegisterClass(&wc))
            {
                return false;
            }

            classRegistered = true;
        }

        hWnd = CreateWindowEx( 
            0,                   // Optional Window styling
            "MainEngineWindow",  // Window Class                  
            m_Data.Title,        // Window Text                   
            WS_OVERLAPPEDWINDOW, // Window Style
            // Size and Position                 
            CW_USEDEFAULT, CW_USEDEFAULT, m_Data.Width, m_Data.Height,                     
            (HWND) nullptr,      // Parent Window 
            (HMENU) nullptr,     // Menu 
            hinst,               // Instance Handle           
            nullptr              // Additional application data
        );                      

        if (!hWnd) { return false; }
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)this);   // attach a uint64 ptr 
        return true;
    }

    void WindowsWindow::Show()
    {
        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
    }

    void WindowsWindow::OnDraw()
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        
        int cx = m_Data.Width/2;
        int cy = m_Data.Height/2;
        int radius = 50;

        Ellipse(hdc, cx - radius, cy - radius, cx + radius, cy + radius);
        EndPaint(hWnd, &ps);
    }

    void WindowsWindow::ProcessMessages()
    {
        MSG msg;
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                m_shouldClose = true;
                break;
            }
            
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void WindowsWindow::SetSize(int width, int height)
    {
        m_Data.Width = width;
        m_Data.Height = height;
    }


    void MiniEngine::WindowsWindow::OnUpdate()
    {
        // empty for now
    }

    MiniEngine::WindowsWindow::~WindowsWindow()
    {
        // empty for now
    }
}

#endif /* WINDOWSWINDOW_CPP */
