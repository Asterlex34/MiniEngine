#include <iostream>
#include "Engine.h"
#include <stdexcept>

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
        return true;
    }

    void Engine::Cleanup()
    {
        std::cout << "Cleaning up Engine...\n";
    }
}