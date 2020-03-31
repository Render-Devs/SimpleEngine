#pragma once
enum class RenderAPI
{
	None = 0x00,
	OpenGL = 0x01,
	DirectX = 0x02,
	Metal = 0x03,
	Vulkan = 0x04
};

static RenderAPI CurrentRenderAPI = RenderAPI::OpenGL;