#pragma once
#include "ILayer.h"
#include <vector>
#include <memory>

namespace SimpleEngine::Core
{
	class SE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(ILayer* layer);
		void PushOverlay(ILayer* layer);
		void PopLayer(ILayer* layer);
		void PopOverlay(ILayer* layer);

		std::vector<ILayer*>::iterator begin() { layers->begin(); }
		std::vector<ILayer*>::iterator end() { layers->end(); }

	private:
		std::shared_ptr<std::vector<ILayer*>> layers;
		unsigned short layerInserts;
	};

}