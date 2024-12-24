#include "World.h"

World::World(GLFWwindow* window)
{
    gladLoadGL();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize graphics library");

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    
    Mesh.emplace();
    Light.emplace();
    Camera.emplace(window, width, height, glm::vec3(0.0f, 0.0f, 5.0f));

    glm::vec4 LightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 LightPosition = glm::vec3(2.5f, 2.5f, 2.5f);
    glm::mat4 LightModel = glm::mat4(1.0f);
    GLfloat LightIntensity = 2.0f;
    LightModel = glm::translate(LightModel, LightPosition);
    LightModel = glm::scale(LightModel, glm::vec3(0.25f));
    
    glm::vec3 MeshPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 MeshModel = glm::mat4(1.0f);
    MeshModel = glm::translate(MeshModel, MeshPosition);
    MeshModel = glm::scale(MeshModel, glm::vec3(1.0f));
    MeshModel = glm::rotate(MeshModel, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    Light->Shader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(Light->Shader.programID, "Model"), 1, GL_FALSE, glm::value_ptr(LightModel));
    glUniform4f(glGetUniformLocation(Light->Shader.programID, "Color"), LightColor.x, LightColor.y, LightColor.z, LightColor.w);
    
    Mesh->Shader.Activate();
    glUniformMatrix4fv(glGetUniformLocation(Mesh->Shader.programID, "Model"), 1, GL_FALSE, glm::value_ptr(MeshModel));
    glUniform4f(glGetUniformLocation(Mesh->Shader.programID, "LightColor"), LightColor.x, LightColor.y, LightColor.z, LightColor.w);
    glUniform3f(glGetUniformLocation(Mesh->Shader.programID, "LightPosition"), LightPosition.x, LightPosition.y, LightPosition.z);
    glUniform1f(glGetUniformLocation(Mesh->Shader.programID, "LightIntensity"), LightIntensity);
    
    glEnable(GL_DEPTH_TEST);
}

void World::Run(GLFWwindow* window)
{
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Camera->Input(window);
    Camera->Update(window, 70.0f, 0.01f, 1000.0f);

    Mesh->Render();
    glUniform3f(glGetUniformLocation(Mesh->Shader.programID, "CameraPosition"), Camera->Position.x, Camera->Position.y, Camera->Position.z);
    Camera->Matrix(Mesh->Shader, "CameraMatrix");

    Light->Render();
    Camera->Matrix(Light->Shader, "CameraMatrix");
}
