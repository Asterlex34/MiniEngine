#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <cstdint>

namespace MiniEngine
{
    /* Define the default attributes a Window receives in the form of a struct */
    struct WindowProperties
    {
        const char* Title;
        uint32_t Width;
        uint32_t Height;

        WindowProperties(const char* title = "Mini Engine", uint32_t width = 800, uint32_t height = 400)
            : Title(title), Width(width), Height(height) {}
    };

    /* 
    Define a pure abstract class so that all derived classes must follow
    this interface and enforce implementation of certain functions
    */

    class MiniWindow
    {
        public:
            virtual ~MiniWindow() {};
            MiniWindow(const MiniWindow&) = delete;             // delete the copy constructor
            MiniWindow& operator=(const MiniWindow&) = delete;  // delete the assignment operator

            virtual void OnUpdate() = 0;
            virtual void OnDraw() = 0;
            virtual void Show() = 0;
            virtual void SetSize(int width, int height) = 0;

            virtual uint32_t GetWidth() const = 0;  
            virtual uint32_t GetHeight() const = 0;
            virtual bool shouldClose() const = 0;
            // the above methods must be overriden by derived classes as they are pure virtual

            static std::unique_ptr<MiniWindow> Create(const WindowProperties& props = WindowProperties());
        
        private:
            bool Init(const WindowProperties& props);
            void ProcessMessages();

        protected:
            MiniWindow() = default;
            
        friend class Engine;
    };
}

#endif /* WINDOW_H */