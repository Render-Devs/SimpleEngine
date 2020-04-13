#pragma once

#include "Core.h"
#include "ILayer.h"
#include "LayerStack.h"
#include "SimpleEngine\Window\IWindow.h"
#include <memory>
#include "SimpleEngine\RenderSpecific\OpenGL\Window\OpenGLWindow.h" //TEMP solution. TODO: Remove after implement Window events 

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
    private:
        std::unique_ptr<IWindow*> pWindow;
        bool isRunning = true;
        bool isMinimized = false;
        std::unique_ptr<LayerStack> pLayerStack;
        float lastFrameTime = 0.0f;
    protected:
        static Application* pInstance;
    };

    Application* CreateApplication();
}