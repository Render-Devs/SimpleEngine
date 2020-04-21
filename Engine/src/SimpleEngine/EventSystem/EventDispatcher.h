#pragma once
#include "IEvent.h"
#include <string>
#include <functional>
namespace SimpleEngine::EventSystem
{
	class EventDispatcher
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;

	public:
		EventDispatcher(const IEvent& event):currentEvent(const_cast<IEvent&>(event))
		{}

		template<typename T>
		bool Dispatch(EventFunction<T> func)
		{
			if (currentEvent.GetEventType() == T::GetStaticType())
			{
				currentEvent.Handled = func(*(T*)&currentEvent);
				return true;
			}
			return false;
		}
	private:
		IEvent& currentEvent;
	};
}