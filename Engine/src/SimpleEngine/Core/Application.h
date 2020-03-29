#pragma once

#include "Core.h"

namespace SimpleEngine::Core
{
    class SE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}