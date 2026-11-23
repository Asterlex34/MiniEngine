#include <iostream>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include "Engine.h"
#include "EngineTime.h"
#include "../logger/MiniLogger.h"


namespace MiniEngine {
    void Engine::Run() {
        if (!Init()) {
            MiniLogger::Log(ErrorPriority, "Engine", "Failed to initialize engine")
        }

        RenderLoop();
    }

    bool Engine::Init() {
        // Setup the logger for the Engine Window
        MiniLogger::Log(InfoPriority, "Engine", "Initializing Engine");

        // Start the timer for time-related info and convert output into seconds
        m_StartTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() / 1000000.0f;

        // Create a Window and check for Initialization failure
        m_Window = MiniWindow::Create(MiniEngine::WindowProperties());
        if (!m_Window->Init(MiniEngine::WindowProperties())) {
            return false; 
        }

        m_Window->Show();
        return true;
    }

    void Engine::RenderLoop() {
        // Main command processing loop
        while(m_Running) {
            m_Window->ProcessMessages();

            // Handle window close event
            if (m_Window->shouldClose())
            {
                MiniLogger::Log(InfoPriority, "Engine", "Closing Window");
                m_Running = false;
                break;
            }

            // Frame timer
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

            /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            /                      ADD RENDER LOGIC HERE
            /  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

            // Time related calculations
            EngineTime::_unscaledDeltaTime = (float)(end - start) / 1000.0f;                          // Elapsed frame time in milliseconds
            EngineTime::_deltaTime = EngineTime::_unscaledDeltaTime * EngineTime::_timeScale;         // Having fun with time-perception I actually don't know if this is useful
            EngineTime::_realTimeSinceStartup = end / 1000000.0f - m_StartTime;                       // Actual time passed since the engine started in seconds
            EngineTime::_gameTime = EngineTime::_realTimeSinceStartup * EngineTime::_timeScale;       // How much time has passed in-game
            EngineTime::_frameCount++;                                                                // Tracks how many frames have passed since the engine started

            // DEBUG
            printf("Delta Time: %f\tUnscaled Delta Time: %f\tTime Scale: %f\tTime: %f\tReal Time Since Startup: %f\tFrame Count: %d\n",
                EngineTime::deltaTime(), EngineTime::unscaledDeltaTime(), EngineTime::timeScale(), EngineTime::gameTime(), EngineTime::realTimeSinceStartup(), EngineTime::frameCount());
        }

        Cleanup();
    }

    void Engine::Cleanup() {
        std::cout << "NOT IMPLEMENTED YET!!!~" << std::endl;
    }
}
