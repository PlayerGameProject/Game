#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <optional>
#include <exception>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "../Camera/Camera.h"

class World
{
private:
    std::optional<Mesh> Block;
    std::optional<Camera> Camera;
    
public:
    World(GLFWwindow* window);
    void Run(GLFWwindow* window);
    ~World() = default;
};

#endif
