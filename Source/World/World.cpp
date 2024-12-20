#include "World.h"

World::World(GLFWwindow* window)
{
    gladLoadGL();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize graphics library");

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    
    Block.emplace();
    Camera.emplace(window, width, height, glm::vec3(0.0f, 0.0f, 5.0f));

    glEnable(GL_DEPTH_TEST);
}

void World::Run(GLFWwindow* window)
{
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Block->Render();

    Camera->Input(window);
    Camera->Update(window, 70.0f, 0.01f, 1000.0f);
    Camera->Matrix(Block->Shader, "CameraMatrix");
}
