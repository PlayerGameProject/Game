#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <optional>
#include <exception>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"

class World
{
private:
    std::optional<Mesh> Block; // Late-initialize the Mesh class
    
public:
    World();
    void Run();
    ~World();
};

#endif
