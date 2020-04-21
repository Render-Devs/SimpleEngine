#include "RenderLayer.h"

RenderLayer::RenderLayer() : ILayer("Render Layer")
{
}

RenderLayer::~RenderLayer()
{
}

void RenderLayer::OnAttach()
{
	//TODO: Allocate resources
}

void RenderLayer::OnDetach()
{
	//TODO: Free resources
}

void RenderLayer::OnUpdate()
{
	//TODO: Update values, logic etc.
}

void RenderLayer::OnRender()
{
	//TODO: Render Only
}
