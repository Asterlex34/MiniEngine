#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include "../Window.h"
#include <memory>

namespace MiniEngine
{
    class LinuxWindow : public MiniEngine::MiniWindow
    {
        public:
            LinuxWindow(const WindowProperties& props);
            virtual ~LinuxWindow();

            virtual void OnUpdate() override;
            virtual void OnDraw() override;
            virtual void Show() override;
            virtual void SetSize(int width, int height) override;

            virtual uint32_t GetWidth() const { return m_Data.Width; }
            virtual uint32_t GetHeight() const { return m_Data.Height; }
            virtual bool shouldClose() const { return m_shouldClose; }
        
        private:
            bool Init(const WindowProperties& props);
            bool ProcessMessages();

        private:
            bool m_shouldClose = false; 
            struct windowData
            {
                const char* Title;
                uint32_t Height, Width;
            } m_Data;

        friend class Engine;
    };
}

#endif /* LINUXWINDOW_H */
