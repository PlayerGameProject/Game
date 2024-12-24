#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <optional>
#include <exception>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Light.h"
#include "../Camera/Camera.h"

class World
{
private:
    std::optional<Mesh> Mesh;
    std::optional<Light> Light;
    std::optional<Camera> Camera;
    
public:
    World(GLFWwindow* window);
    void Run(GLFWwindow* window);
    ~World() = default;
};

#endif
