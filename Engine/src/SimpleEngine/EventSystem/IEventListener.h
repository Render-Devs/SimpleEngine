#pragma once
#include "IEvent.h"
#include <functional>

namespace SimpleEngine::EventSystem
{
	using EventCallback = std::function<void(const IEvent&)>;
	class IEventListener
	{
	public:
		void SetEventCallback(const EventCallback& callback) { eventHandler = callback; };
	public:
		EventCallback eventHandler;
	};
}