cmake_minimum_required(VERSION 3.16)

project(MiniEngine)

# Use modern C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------------------------------------------------------------
# MiniEngine Static Library
# --------------------------------------------------------------------

add_library(MiniEngine STATIC)

# Include core engine headers
target_include_directories(MiniEngine PUBLIC
    ${PROJECT_SOURCE_DIR}/src/core
)

# Source files from core
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/core/*.cpp
)

target_sources(MiniEngine PRIVATE ${ENGINE_SRC})

# --------------------------------------------------------------------
# Platform-Specific (Windows)
# --------------------------------------------------------------------

if(WIN32)
    target_compile_definitions(MiniEngine PRIVATE PLATFORM_WINDOWS)

    target_include_directories(MiniEngine PRIVATE
        ${PROJECT_SOURCE_DIR}/src/core/platform/Windows
    )

    target_sources(MiniEngine PRIVATE
        src/core/platform/Windows/WindowsWindow.cpp
    )

    target_link_libraries(MiniEngine PUBLIC gdi32 user32)
endif()

# --------------------------------------------------------------------
# Platform-Specific (Linux)
# --------------------------------------------------------------------

if(LINUX)
    target_compile_definitions(MiniEngine PRIVATE PLATFORM_LINUX)

    target_include_directories(MiniEngine PRIVATE_HEADER
        ${PROJECT_SOURCE_DIR}/src/core/platform/Linux
    )

    target_sources(MiniEngine PRIVATE_HEADER
        src/core/platform/Linux/LinuxWindow.cpp
    )

    target_link_libraries(MiniEngine PUBLIC X11)
endif()

# --------------------------------------------------------------------
# GLAD (local in dependencies/thirdparty/glad)
# --------------------------------------------------------------------

add_subdirectory(dependencies/thirdparty/glad)

# --------------------------------------------------------------------
# Application Executable
# --------------------------------------------------------------------

add_executable(MiniEngineApp src/core/EntryPoint.cpp)

target_include_directories(MiniEngineApp PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/dependencies/thirdparty/glad/include
)

target_link_libraries(MiniEngineApp PRIVATE
    MiniEngine
    glad::glad
)
