#pragma once

#include "SimpleEngine\Window\IContext.h"
#include <GLFW\glfw3.h>

class OpenGLContext final : public IContext
{
public:
	OpenGLContext(GLFWwindow* window);
	virtual void Init() override;
	virtual void SwapBuffers() override;

private:
	GLFWwindow* windowHandle;
};