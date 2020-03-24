#include <stdexcept>
#include "GLFWWindow.h"

// Constructors
GLFWWindow::GLFWWindow() = default;

GLFWWindow::GLFWWindow(int x, int y, std::string title)
        : sizeX(x), sizeY(y), title(std::move(title)), isInitialized(false) {}

// Destructor
GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow(this->glfWindow);
}

void GLFWWindow::Create() {
    auto window = glfwCreateWindow(
            this->sizeX,
            this->sizeY,
            this->title.data(),
            nullptr,
            nullptr
    );
    if (window == nullptr) {
        throw std::runtime_error("cannot create glfw window");
    }
    this->glfWindow = window;
    this->isInitialized = true;
}


// Setters and Getters
void GLFWWindow::SetSizes(int x, int y) {
    this->sizeX = x;
    this->sizeY = y;
}

void GLFWWindow::SetTitle(std::string title) {
    this->title = std::move(title);
}

GLFWwindow *GLFWWindow::GetGLFWWindow() {
    if (!isInitialized || this->glfWindow == nullptr) {
        throw std::runtime_error("GLFW window not initialized");
    }
    return this->glfWindow;
}

void GLFWWindow::SetInputMode(int mode, int value) {
    glfwSetInputMode(this->GetGLFWWindow(), mode, value);
}


