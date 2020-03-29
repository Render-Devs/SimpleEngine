#pragma once
#include <cstdint>
#include <string>

struct WindowData
{
	std::string title;
	uint32_t width, height;

	WindowData(const std::string& title, uint32_t width, uint32_t height) : 
		title(title), width(width), height(height) {}
};

class IWindow
{
public:
	virtual ~IWindow() {}
	virtual void Update() = 0;
	virtual uint32_t GetWidth() const noexcept = 0;
	virtual uint32_t GetHeight() const noexcept = 0;


	virtual void SetVSync(bool enabled) noexcept = 0;
	virtual bool IsVSync() const noexcept = 0;

	virtual void* GetPlatformWindow() const noexcept = 0;
	virtual void* GetNativeWindow() const noexcept = 0;
	virtual void Shutdown() = 0;
};