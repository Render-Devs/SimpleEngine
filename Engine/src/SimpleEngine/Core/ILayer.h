#pragma once
#include "Core.h"
#include <string>
#include <memory>

namespace SimpleEngine::Core
{
	class SE_API ILayer
	{
	public:
		ILayer(const std::string& name) : layerName(std::make_shared<std::string>(name)) {}
		virtual ~ILayer() { layerName.reset(); };

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;

		protected:
			std::shared_ptr <std::string> layerName;
	};
}