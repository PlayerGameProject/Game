#include "App.h"

int main(int argc, char** argv)
{
    try
    {
        App Game(640u, 480u, "Game");
        Game.Run();
        Game.~App();

        return EXIT_SUCCESS;
    }
    catch (std::runtime_error& error)
    {
        std::cout << "[Error] Failed to run the program: " << error.what() << std::endl;

        return EXIT_FAILURE;
    }
}
