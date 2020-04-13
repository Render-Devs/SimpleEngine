#pragma once

#include "Core.h"
#include "ILayer.h"
#include "LayerStack.h"
#include "SimpleEngine\Window\IWindow.h"
#include <memory>

namespace SimpleEngine::Core
{
    class SE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void PushLayer(ILayer* layer);
        void PushUILayer(ILayer* layer);

        inline static Application& Get() { return *pInstance; }
    private:
        std::unique_ptr<IWindow*> pWindow;
        bool isRunning = true;
        bool isMinimized = false;
        std::unique_ptr<LayerStack> pLayerStack;
        float lastFrameTime = 0.0f;
        static Application* pInstance;
    };

    Application* CreateApplication();
}