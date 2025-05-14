#ifndef ENGINE_H
#define ENGINE_H

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
            bool m_Running = true;
    };
}

#endif /* engine_h */