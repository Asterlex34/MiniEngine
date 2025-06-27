#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include "./platform/Window.h"

namespace MiniEngine
{
    class Engine 
    {
        public:
            void Run();
        
        private:
            bool Init();
            void RenderLoop();
            void Cleanup();

        private:
            std::unique_ptr<MiniEngine::MiniWindow> m_Window;
            bool m_Running = true;
            float m_StartTime = 0.0f;
        };
}

#endif /* engine_h */