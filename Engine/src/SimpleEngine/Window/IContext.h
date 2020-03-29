#pragma once

class IContext
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;
};