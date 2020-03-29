#pragma once
#include "IWindow.h"
class WindowFactory
{
	static IWindow* CreateWindow(const WindowData& data);
};