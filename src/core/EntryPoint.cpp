#include "./engine/Engine.h"
#include <iostream>

int main()
{
    MiniEngine::Engine engine;
    try
    {
        engine.Run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
        return EXIT_FAILURE;
    }

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return EXIT_SUCCESS;
}