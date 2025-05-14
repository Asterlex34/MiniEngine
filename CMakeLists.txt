cmake_minimum_required(VERSION 3.16)

project(MiniEngine)

# Use modern C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

add_library(MiniEngine STATIC)

# Add include directories for core and platform-specific headers
target_include_directories(MiniEngine
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src/core
        ${SDL2_INCLUDE_DIRS}  # Add SDL2 include directories
)

# Platform-specific handling
if(WIN32)
    target_compile_definitions(MiniEngine PRIVATE PLATFORM_WINDOWS)
    target_include_directories(MiniEngine PRIVATE ${PROJECT_SOURCE_DIR}/src/core/platform/Windows)

    # Add platform-specific source files for Windows
    target_sources(MiniEngine PRIVATE
        src/core/platform/Windows/WindowsWindow.cpp
        src/core/platform/Windows/WindowsWindow.h
    )

    # Link against Windows libraries
    target_link_libraries(MiniEngine PUBLIC gdi32 user32)

elseif(UNIX)
    target_compile_definitions(MiniEngine PRIVATE PLATFORM_LINUX)
    target_include_directories(MiniEngine PRIVATE ${PROJECT_SOURCE_DIR}/src/core/platform/Linux)

    # Add platform-specific source files for Linux
    target_sources(MiniEngine PRIVATE
        src/core/platform/Linux/LinuxWindow.cpp
        src/core/platform/Linux/LinuxWindow.h
    )

    # Link against X11 for Linux
    target_link_libraries(MiniEngine PUBLIC X11)
endif()

# Add SDL2 to the link libraries
target_link_libraries(MiniEngine PUBLIC SDL2::SDL2)

# Add the core engine source files
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
    src/core/*.cpp
    src/core/*.h
)

# Add the source files to the target
target_sources(MiniEngine PRIVATE ${ENGINE_SRC})

