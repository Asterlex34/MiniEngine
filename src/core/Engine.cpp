#include <iostream>
#include "Engine.h"
#include <stdexcept>

const char* platform = nullptr

#if defined(_WIN32)
constexpr const char* platform = "Windows";
#elif defined(__linux__)
constexpr const char* platform = "Linux";
#else
constexpr const char* platform = "Unknown";
#endif

namespace MiniEngine
{
    void Engine::Run()
    {
        if (!Init()) throw std::runtime_error("Failed to Initialize Engine\n");
        RenderLoop();
    }

    void Engine::RenderLoop()
    {
        while(m_Running)
        {
            // Futher logic...
        }

        Cleanup();
    }

    bool Engine::Init()
    {
        std::cout << "Initializing Engine...\n";

        if (platform == "Unknown")
        {
            std::cout << "I am NOT extending this to further platforms\n"
            return false;
        }

        if (platform == "Windows")
        {
            #include "./platform/Windows/WindowsWindow.h"
            
            m_Window = MiniWindow::Create(WindowProperties());
            if (!m_Window->Init(WindowProperties())) { return false; }
            m_Window->Show()
        }

        if (platform == "Linux")
        {
            // not yet implemented, pmo
        }

        return true;
    }

    void Engine::Cleanup()
    {
        std::cout << "Kill yourself Swarth...\n";
    }
    // implement the window class first retard, pmo
}