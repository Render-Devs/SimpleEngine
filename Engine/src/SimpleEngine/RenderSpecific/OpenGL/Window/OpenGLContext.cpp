#include "OpenGLContext.h"

OpenGLContext::OpenGLContext(GLFWwindow* window) : windowHandle(window)
{
}

void OpenGLContext::Init()
{
	glfwMakeContextCurrent(windowHandle);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(windowHandle);
}