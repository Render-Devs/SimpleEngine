#pragma once
#include "IWindow.h"
class WindowFactory
{
public:
	static IWindow* CreateWindow(const WindowData& data);
};