#include "App.h"

App::App(unsigned int width, unsigned int height, const std::string& title, const std::string& icon, bool vSync) : Window(width, height, title, icon, vSync), World(Window.GetWindow())
{
    std::cout << " -- Game has started -- \n" << std::endl;
}

void App::Run()
{
    while (!Window.ShouldClose())
    {
        World.Run(Window.GetWindow());
        Window.Run();
    }
}

App::~App()
{
    std::cout << "\n -- Game has ended -- " << std::endl;
}
