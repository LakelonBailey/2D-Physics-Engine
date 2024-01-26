#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    // Define the window title with the copyright symbol
    std::string windowTitle = "2D Physics Engine (Copyright © 2023 Lakelon Bailey)";

    GLFWwindow* window = glfwCreateWindow(800, 600, windowTitle.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set the color to blue
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the blue box
        glBegin(GL_QUADS); // Start drawing a quad
            glVertex2f(-0.5f, -0.5f); // Bottom left
            glVertex2f(0.5f, -0.5f);  // Bottom right
            glVertex2f(0.5f, 0.5f);   // Top right
            glVertex2f(-0.5f, 0.5f);  // Top left
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
