#pragma once
#include "Window\IWindow.h"
#include "GLFW\glfw3.h"
#include <memory>

class OpenGLWindow final : public IWindow
{
public:
	OpenGLWindow(const WindowData& configData) noexcept;
	virtual ~OpenGLWindow();

	void Update() override;

	inline uint32_t GetWidth() const noexcept override { Data.width; }
	inline uint32_t GetHeight() const noexcept override { Data.height; }
	void SetVSync(bool enabled) noexcept override;
	bool IsVSync() const noexcept override;

	void* GetPlatformWindow() const noexcept override;
	void* GetNativeWindow() const noexcept override { return window; };
	void Shutdown() override;

private:
	void Init(const WindowData& configData);

	struct WindowInternalData
	{
		std::string title;
		uint32_t width, height;
		bool vsync;
	} 
	Data;

	GLFWwindow* window;
	std::unique_ptr<IContext> context;

	static bool isInitialized;
};