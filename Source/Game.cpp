#include "App.h"

int main(int argc, char** argv)
{
    try
    {
        App Game(640u, 480u, "Game");
        Game.Run();
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << "[Error] Failed to run the program: " << error.what() << std::endl;

        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
