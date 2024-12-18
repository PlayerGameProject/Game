#include "Window.h"

Window::Window(unsigned int width, unsigned int height, std::string title)
{
    glfwInit();

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize window library");

    glfwDefaultWindowHints();

    this->width = width;
    this->height = height;
    this->title = title;
    
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create window");

    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(window, this);

    glfwSwapInterval(1);

    if (glfwRawMouseMotionSupported())
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    SetCenter(window);
}

void Window::Run()
{
    glfwSwapBuffers(window);
    glfwPollEvents();

    KeyInput();
}

void Window::SetViewport()
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    glViewport(0, 0, width, height);
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(window);
}

GLFWwindow* Window::GetWindow() const
{
    return this->window;
}

void Window::KeyInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS)
        Fullscreen(window);
}

void Window::SetCenter(GLFWwindow* window)
{
    int windowX, windowY;
    glfwGetWindowPos(window, &windowX, &windowY);

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    windowWidth *= 0.5;
    windowHeight *= 0.5;

    windowX += windowWidth;
    windowY += windowHeight;

    int monitorsLen;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorsLen);
    if (monitors == NULL)
    {
        return;
    }

    GLFWmonitor* monitor = NULL;
    int monitorX, monitorY, monitorWidth, monitorHeight;

    for (int i = 0; i < monitorsLen; i++)
    {
        int monitorsX, monitorsY;
        glfwGetMonitorPos(monitors[i], &monitorsX, &monitorsY);

        int monitorsWidth, monitorsHeight;
        GLFWvidmode* monitorVidmode = (GLFWvidmode*)glfwGetVideoMode(monitors[i]);
        if (monitorVidmode == NULL)
        {
            continue;
        }
        else
        {
            monitorsWidth = monitorVidmode->width;
            monitorsHeight = monitorVidmode->height;
        }

        if ((windowX > monitorsX && windowX < (monitorsX + monitorsWidth)) && (windowY > monitorsY && windowY < (monitorsY + monitorsHeight)))
        {
            monitor = monitors[i];

            monitorX = monitorsX;
            monitorY = monitorsY;

            monitorWidth = monitorsWidth;
            monitorHeight = monitorsHeight;
        }
    }

    if (monitor != NULL)
    {
        glfwSetWindowPos(window, monitorX + (monitorWidth * 0.5) - windowWidth, monitorY + (monitorHeight * 0.5) - windowHeight);
    }
}

void Window::Fullscreen(GLFWwindow* window)
{
    if (glfwGetWindowMonitor(window) == NULL)
    {
        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
        glfwSetWindowMonitor(window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        glfwSwapBuffers(window);
    }
    else
    {
        glfwSetWindowMonitor(window, NULL, 0, 0, width, height, 0);

        SetCenter(window);

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        glfwSwapBuffers(window);
    }
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
