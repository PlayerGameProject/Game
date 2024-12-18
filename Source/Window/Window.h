#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <cerrno>
#include <thread>
#include <exception>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    int width, height;
    std::string title;
    GLFWwindow* window;
    
public:
    Window(unsigned int width, unsigned int height, std::string title);
    void Run();
    void SetViewport();
    bool ShouldClose() const;

    GLFWwindow* GetWindow() const;
    ~Window();
    
private:
    void KeyInput();
    void SetCenter(GLFWwindow* window);
    void Fullscreen(GLFWwindow* window);
};

#endif
