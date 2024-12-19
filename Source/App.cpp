#include "App.h"

App::App(unsigned int width, unsigned int height, const std::string& title) : Window(width, height, title)
{
}

void App::Run()
{
    while (!Window.ShouldClose())
    {
        World.Run();
        Window.Run();
    }
}

App::~App()
{
}

