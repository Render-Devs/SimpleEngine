#include "test.h"

#include <GLFW/glfw3.h>

#include <iostream>

namespace Engine
{
    int Init()
    {
        std::cout << "Hello from the Engine!" << std::endl;

        // glfw: initialize and configure
        // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfw window creation
        // --------------------
        GLFWwindow* window = glfwCreateWindow(800, 600, "SimpleEngine", nullptr, nullptr);
        if (window == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return - 1;
        }
        glfwMakeContextCurrent(window);

        while(!glfwWindowShouldClose(window))
        {
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window, true);
            }

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        return 0;
    }

}