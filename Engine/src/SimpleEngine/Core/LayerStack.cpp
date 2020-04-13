#include "LayerStack.h"


namespace SimpleEngine::Core
{
	LayerStack::LayerStack() : layerInserts(0)
	{
		layers.reset(new std::vector<ILayer*>());
	}

	LayerStack::~LayerStack()
	{
		layers.reset();
	}

	void LayerStack::PushLayer(ILayer* layer)
	{
		layers->emplace(layers->begin() + layerInserts++, layer);
	}

	void LayerStack::PushOverlay(ILayer* layer)
	{
		layers->emplace_back(layer);
	}

	void LayerStack::PopLayer(ILayer* layer)
	{
		auto iter = std::find(layers->begin(), layers->end(), layer);
		if (iter != layers->begin() + layerInserts)
		{
			layers->erase(iter);
			layerInserts--;
		}
	}

	void LayerStack::PopOverlay(ILayer* layer)
	{
		auto iter = std::find(layers->begin(), layers->end(), layer);
		if (iter != layers->end())
		{
			layers->erase(iter);
		}
	}
}
