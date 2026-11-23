#include "./engine/Engine.h"
#include <iostream>
#include "./logger/MiniLogger.h"

int main(int argc, char* argv[])
{
    /*   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /          ADD LOCKFILE SO SUM PAKISTANI DUDE CAN'T START 7 INSTANCES
    /    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    */
   
    MiniEngine::Engine engine;

    try { engine.Run(); } 
    catch (std::exception& e) {
        MiniLogger::Log(ErrorPriority, "EntryPoint", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}