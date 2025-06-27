#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
#include <Windows.h>
#ifdef __cplusplus
}
#endif

#include "../Window.h"
#include <memory>

namespace MiniEngine
{
    class WindowsWindow : public MiniEngine::MiniWindow
    {
        public:
            WindowsWindow(const WindowProperties& props);
            virtual ~WindowsWindow();

            virtual void OnUpdate() override;
            virtual void OnDraw() override;
            virtual void Show() override;
            virtual void SetSize(int width, int height) override;

            virtual uint32_t GetWidth() const { return m_Data.Width; }
            virtual uint32_t GetHeight() const { return m_Data.Height; }
            virtual bool shouldClose() const { return m_shouldClose; }
        
        private:
            bool Init(const WindowProperties& props);
            void ProcessMessages();

        private:
            HINSTANCE hinst;
            HWND hWnd;
            bool m_shouldClose = false; 
            struct windowData
            {
                const char* Title;
                uint32_t Height, Width;
            } m_Data;
        

        friend class Engine;
    };
}

#endif /* WINDOWSWINDOW_H */
