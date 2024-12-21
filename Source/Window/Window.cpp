#include "Window.h"

#include <dinput.h>

Window::Window(unsigned int width, unsigned int height, const std::string& title, const std::string& icon, bool vSync) : width(width), height(height), title(title)
{
    glfwInit();

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize window library");

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title.c_str(), nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create window");

    if (!icon.empty())
    {
        if (!Icon(icon, window))
        {
            std::cout << "[Warn] Failed to load icon, operating system default will be used"<< std::endl;
        }
    }

    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(window, this);

    glfwSwapInterval(vSync);

    if (glfwRawMouseMotionSupported())
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    SetCenter(window);

    glfwShowWindow(window);
}

void Window::Run()
{
    glfwSwapBuffers(window);
    glfwPollEvents();

    SetViewport();

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

bool Window::Icon(const std::string& path, GLFWwindow* window)
{
    int width, height, channels;
    unsigned char* image = stbi_load(path.c_str(), &width, &height, &channels, 4);

    if (image == nullptr)
        return false;

    GLFWimage icon;
    icon.width = width;
    icon.height = height;
    icon.pixels = image;

    glfwSetWindowIcon(window, 1, &icon);
    stbi_image_free(image);
    return true;
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

    int monitorsLength;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorsLength);
    if (monitors == nullptr)
        return;

    GLFWmonitor* monitor = nullptr;
    int monitorX, monitorY, monitorWidth, monitorHeight;

    for (int i = 0; i < monitorsLength; i++)
    {
        int monitorsX, monitorsY;
        glfwGetMonitorPos(monitors[i], &monitorsX, &monitorsY);

        int monitorsWidth, monitorsHeight;
        GLFWvidmode* monitorVideoMode = (GLFWvidmode*)glfwGetVideoMode(monitors[i]);
        if (monitorVideoMode == nullptr)
            continue;
        else
        {
            monitorsWidth = monitorVideoMode->width;
            monitorsHeight = monitorVideoMode->height;
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

    if (monitor != nullptr)
        glfwSetWindowPos(window, monitorX + (monitorWidth * 0.5) - windowWidth, monitorY + (monitorHeight * 0.5) - windowHeight);
}

void Window::Fullscreen(GLFWwindow* window)
{
    if (glfwGetWindowMonitor(window) == nullptr)
    {
        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
        glfwSetWindowMonitor(window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        glfwSwapBuffers(window);
    }
    else
    {
        glfwSetWindowMonitor(window, nullptr, 0, 0, width, height, 0);

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
