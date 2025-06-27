#include <iostream>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include "Engine.h"
#include "EngineTime.h"

namespace MiniEngine
{
    void Engine::Run()
    {
        if (!Init()) throw std::runtime_error("Failed to Initialize Engine\n");
        RenderLoop();
    }

    bool Engine::Init()
    {
        m_StartTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() / 1000000.0f;
        std::cout << "Initializing Engine...\n";
        m_Window = MiniWindow::Create(MiniEngine::WindowProperties());

        if (!m_Window->Init(MiniEngine::WindowProperties()))
        {
            return false; 
        }

        m_Window->Show();
        return true;
    }

    void Engine::RenderLoop()
    {
        while(m_Running)
        {
            m_Window->ProcessMessages();

            if (m_Window->shouldClose())
            {
                std::cout << "closing Window...\n";
                m_Running = false;
                break;
            }

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

            // Rendering Logic comes later

            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

            EngineTime::_unscaledDeltaTime = (float)(end - start) / 1000.0f;              // elapsed frame time in milliseconds
            EngineTime::_deltaTime = EngineTime::_unscaledDeltaTime * EngineTime::_timeScale;         // useful for messing around with time-perception
            EngineTime::_realTimeSinceStartup = end / 1000000.0f - m_StartTime;           // actual time passed since the engine started in seconds
            EngineTime::_gameTime = EngineTime::_realTimeSinceStartup * EngineTime::_timeScale;       // how much time has passed in-game
            EngineTime::_frameCount++;                                                    // tracks how many frames have passed since the engine started

            printf("Delta Time: %f\tUnscaled Delta Time: %f\tTime Scale: %f\tTime: %f\tReal Time Since Startup: %f\tFrame Count: %d\n",
                EngineTime::deltaTime(), EngineTime::unscaledDeltaTime(), EngineTime::timeScale(), EngineTime::gameTime(), EngineTime::realTimeSinceStartup(), EngineTime::frameCount());
        }

        Cleanup();
    }

    void Engine::Cleanup()
    {
        std::cout << "NOT IMPLEMENTED YET!!!~" << std::endl;
    }
    // implement the window class first retard, pmo
}