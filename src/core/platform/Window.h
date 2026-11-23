#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <cstdint>

namespace MiniEngine
{
    // Define the default attributes a Window receives in the form of a struct
    struct WindowProperties {
        const char* Title;
        uint32_t Width;
        uint32_t Height;

        WindowProperties(const char* title = "Mini Engine", uint32_t width = 800, uint32_t height = 400)
            : Title(title), Width(width), Height(height) {}
    };

    /*      Define a pure abstract class so that all derived classes must follow
    /       this interface and enforce implementation of certain functions           */

    class MiniWindow {
        public:
            virtual ~MiniWindow() {};
            MiniWindow(const MiniWindow&) = delete;
            MiniWindow& operator=(const MiniWindow&) = delete;

            virtual void OnUpdate() = 0;
            virtual void OnDraw() = 0;
            virtual void Show() = 0;
            virtual void SetSize(int width, int height) = 0;

            virtual uint32_t GetWidth() const = 0;  
            virtual uint32_t GetHeight() const = 0;
            virtual bool shouldClose() const = 0;
            
            /*      The above methods must be overriden by derived classes as they are pure virtual
            /       Also I'm lowk gay but no one will ever read this (Tony stark gif)
            /       and it's 3am I'm cryne                                                              */ 

            static std::unique_ptr<MiniWindow> Create(const WindowProperties& props = WindowProperties());
        
        protected:
            virtual bool Init(const WindowProperties& props) = 0;
            virtual void ProcessMessages() = 0; 

        protected:
            MiniWindow() = default;
            
        friend class Engine;
    };
}

#endif /* WINDOW_H */
