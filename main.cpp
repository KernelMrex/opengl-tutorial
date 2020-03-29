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

    // Purple background
    glClearColor(0.3f, 0.0f, 0.6f, 0.0f);

    // VAO
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create rectangle model
    static const GLfloat vertexBufferData[] = {
            -0.8f, -0.8f, 0.0f,
            0.8f, -0.8f, 0.0f,
            0.8f, 0.8f, 0.0f,
    };
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

    // Check if the ESC key was pressed or the window was closed
    do {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw rectangle
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(
                0,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                nullptr
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        // Swap buffers
        glfwSwapBuffers(window.GetGLFWWindow());
        glfwPollEvents();
    } while (window.GetKey(GLFW_KEY_ESCAPE) != GLFW_PRESS && window.ShouldClose());

    return 0;
}
