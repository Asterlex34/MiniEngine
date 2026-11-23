cmake_minimum_required(VERSION 3.15)
project(MiniEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all CPP files recursively
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*/CMakeFiles/.*")

add_executable(MiniEngine ${SOURCES})

# Include GLAD header
target_include_directories(MiniEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/thirdparty/glad/include"
)

# Link GLAD source file
target_sources(MiniEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/thirdparty/glad/src/gl.c"
)

# Platform-specific linking
if(WIN32)
    target_link_libraries(MiniEngine PRIVATE opengl32)
elseif(UNIX)
    find_package(X11 REQUIRED)
    if(X11_FOUND)
        target_include_directories(MiniEngine PRIVATE ${X11_INCLUDE_DIR})
        target_link_libraries(MiniEngine PRIVATE ${X11_LIBRARIES})
    endif()

    # Find OpenGL on Linux por favor find it
    find_package(OpenGL REQUIRED)
    if(OPENGL_FOUND)
        target_include_directories(MiniEngine PRIVATE ${OPENGL_INCLUDE_DIR})
        target_link_libraries(MiniEngine PRIVATE ${OPENGL_LIBRARIES})
    endif()
endif()

# I hate cmake files claude scratch my nuts a lil
