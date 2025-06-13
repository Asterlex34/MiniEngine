#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include <Windows.h>
#include "../../Window.h"
#include <memory>

namespace MiniEngine
{
    class WindowsWindow : public MiniEngine::MiniWindow
    {
        public:
            WindowsWindow(const WindowProperties& props);
            WindowsWindow(const WindowsWindow&) = delete;
            WindowsWindow operator=(const WindowsWindow&) = delete;
            virtual ~MiniWindow();

            virtual void OnUpdate() override;
            virtual void OnDraw() override;
            virtual void OnClose() override;

            virtual uint32_t GetWidth() const { return m_Data.Width; }
            virtual uint32_t GetHeight() const { return m_Data.Height; }
        
        private:
            bool Init(const WindowProperties& props);
            bool ProcessMessages();

        private:
            HINSTANCE hinst;
            HWND hwndMain;
            struct windowData
            {
                const char* Title;
                uint32_t Height, Width;
            } m_Data;
    };
}

#endif /* WINDOWSWINDOW_H */
