#include "WindowFactory.h"
#include "RenderSpecific\Window\OpenGLWindow.h"
#include "RenderSpecific\RenderAPI.h"

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
