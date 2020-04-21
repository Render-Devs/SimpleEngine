#include "OpenGLWindow.h"
#include "OpenGLContext.h"

#if _WIN32 || _WIN64
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW\glfw3native.h"
#endif

static bool isInitialized = false;

OpenGLWindow::OpenGLWindow(const WindowData& configData) noexcept
{
	Init(configData);
}

OpenGLWindow::~OpenGLWindow()
{
	Shutdown();
}

void OpenGLWindow::Init(const WindowData& configData)
{
	Data.title = configData.title;
	Data.width = configData.width;
	Data.height = configData.height;

	if (!isInitialized)
	{
		int success = glfwInit();
		if (success)
		{
			isInitialized = true;
		}
		else
		{
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		window = glfwCreateWindow(Data.width, Data.height, Data.title.c_str(), nullptr, nullptr);
		context = std::make_unique<OpenGLContext>(window);
		context->Init();
		glfwSetWindowUserPointer(window, &Data);
		SetVSync(true);
		//TODO: Add events here (Stenky)
	}
}

void* OpenGLWindow::GetPlatformWindow() const noexcept
{
#if _WIN32 || _WIN64
	return glfwGetWin32Window(window);
#else
	return nullptr;
#endif
}

void OpenGLWindow::Shutdown()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void OpenGLWindow::Update()
{
	glfwPollEvents();
	context->SwapBuffers();
}

void OpenGLWindow::SetVSync(bool enabled) noexcept
{
	if (enabled)
	{
		glfwSwapInterval(1);
	}
	else
	{
		glfwSwapInterval(0);
	}

	Data.vsync = enabled;
}

bool OpenGLWindow::IsVSync() const noexcept
{
	return Data.vsync;
}