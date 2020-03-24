#include <iostream>

// OpenGL Extension loader simplifier
#include <GL/glew.h>

// OpenGL window manager (or X11 API linux, WinAPI windows, Cocoa API Mac)
#include <GLFW/glfw3.h>
#include "GLFWWindow.h"

// Lib for 3D maths(not needed at current moment)
// #include <glm/glm.hpp>

int main() {
    // Initializing GLFW
    if (!glfwInit()) {
        std::cerr << "Error while glfw initialization!" << std::endl;
        return 1;
    }

    // Creating window
    GLFWWindow window(1024, 768, "Test 1");
    window.Create();

    // Makes the context of the specified window current for the calling thread
    glfwMakeContextCurrent(window.GetGLFWWindow());

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return 1;
    }

    // Ensure we can capture the escape key being pressed below
    window.SetInputMode(GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.1f, 0.3f, 0.4f, 0.0f);

    // Check if the ESC key was pressed or the window was closed
    do {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing
        // TODO

        // Swap buffers
        glfwSwapBuffers(window.GetGLFWWindow());
        glfwPollEvents();
    } while (
            glfwGetKey(window.GetGLFWWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window.GetGLFWWindow()) == 0
            );
    
    return 0;
}
