#pragma once

#include <SimpleEngine.h>

class RenderLayer : public SimpleEngine::Core::ILayer
{
public:
	RenderLayer();
	~RenderLayer();

	//Not allow copy constructor and asignment
	RenderLayer(const RenderLayer&) = delete;
	RenderLayer& operator=(const RenderLayer&) = delete;

	//Not allow move constructor and asignment
	RenderLayer(const RenderLayer&&) = delete;
	RenderLayer& operator=(const RenderLayer&&) = delete;

	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate() override;
	void OnRender() override;
};