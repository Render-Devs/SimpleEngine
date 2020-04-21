#pragma once

#include "SimpleEngine\Core\Core.h"
#include "EventType.h"
#include "EventCategory.h"

namespace SimpleEngine::EventSystem
{
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags()const override {return category;}
	
	#define BIND_EVENT_HANDLER(func, p) std::bind(&func, p, std::placeholders::_1)

	class IEvent
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		inline bool IsInCategoty(EventCategory category)
		{
			return GetCategoryFlags() & static_cast<int>(category);
		}

	public:
		bool Handled = false;
	};
}