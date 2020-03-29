#ifndef OPENGLTUTORIAL_GLFWWINDOW_H
#define OPENGLTUTORIAL_GLFWWINDOW_H

#include <string>
#include <GLFW/glfw3.h>

class GLFWWindow {
public:
    GLFWWindow(int x, int y, std::string title);

    GLFWWindow();

    ~GLFWWindow();

    // Creating GLFW window struct
    void Create();

    // Returns pointer to a GLFW window struct
    GLFWwindow *GetGLFWWindow();

    // Sets window sizes
    void SetSizes(int x, int y);

    // Sets window title
    void SetTitle(std::string title);

    // Sets window input mode
    void SetInputMode(int mode, int value);

    // Get key status when window focused
    int GetKey(int keyCode);

    bool ShouldClose();

private:
    bool isInitialized = false;
    GLFWwindow *glfWindow{};
    int sizeX{};
    int sizeY{};
    std::string title;
};


#endif //OPENGLTUTORIAL_GLFWWINDOW_H
