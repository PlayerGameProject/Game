#include "World.h"

World::World()
{
    gladLoadGL();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize graphics library");

    Block.emplace();
}

void World::Run()
{
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Block->Render();
}

World::~World()
{
}
