#include "WindowFactory.h"
#include "SimpleEngine\RenderSpecific\OpenGL\Window\OpenGLWindow.h"
#include "SimpleEngine\RenderSpecific\RenderAPI.h"

IWindow* WindowFactory::CreateWindow(const WindowData& data)
{
	switch (CurrentRenderAPI)
	{
	case RenderAPI::OpenGL:
		return new OpenGLWindow(data);
	default:
		return nullptr;
	}
}
