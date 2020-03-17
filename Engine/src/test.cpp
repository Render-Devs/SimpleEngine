#include "test.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/gtx/string_cast.hpp>
#include <imgui.h>

#include <iostream>

namespace Engine
{
    void framebufferSizeCallback(GLFWwindow*, int width, int height);
    
    int Init()
    {
        std::cout << "Hello from the Engine!" << std::endl;
        

        glm::vec3 vector{ 1, 2, 3 };
        std::cout << "TEST_VECTOR::" << glm::to_string(vector) << std::endl;

        vector *= 2;
        std::cout << "TEST_VECTOR*2::" << glm::to_string(vector) << std::endl;

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
        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        while(!glfwWindowShouldClose(window))
        {
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window, true);
            }

            glClearColor(0.23f, 0.47f, 0.30f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        return 0;
    }

    // glfw: whenever the window size changed (by OS or user resize) this callback function executes
    // ---------------------------------------------------------------------------------------------
    void framebufferSizeCallback(GLFWwindow*, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

}
