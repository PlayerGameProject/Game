#pragma once

#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>

#include "Window/Window.h"
#include "World/World.h"

class App
{
private:
    Window Window;
    World World;
    
public:
    App(unsigned int width, unsigned int height, const std::string& title, const std::string& icon, bool vSync);
    void Run();
    virtual ~App();
};

#endif
