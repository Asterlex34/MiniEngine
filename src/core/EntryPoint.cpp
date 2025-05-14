#include "Engine.h"
#include <iostream>

int main()
{
    MiniEngine::Engine engine;
    try
    {
        engine.Run();
    }
    catch (std::exception e)
    {
        std::cout << e.what();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}