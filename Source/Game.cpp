#include "App.h"

int main(int argc, char** argv)
{
    try
    {
        App Game(640u, 480u, "Game", std::string(ProjectDirectory "/Resource/Image/Block.png"), true);
        Game.Run();
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << "[Error] Failed to run the program: " << error.what() << "\n";

        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
