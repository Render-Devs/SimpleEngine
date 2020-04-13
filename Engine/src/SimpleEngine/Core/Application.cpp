#include "Application.h"
#include "SimpleEngine\Window\WindowFactory.h"
#include <GLFW\glfw3.h>

namespace SimpleEngine::Core
{
    Application::Application()
    {
        pInstance = this;

        pWindow = std::make_unique<IWindow*>(WindowFactory::CreateWindow(WindowData("SimpleEngine", 1920, 1080)));
        pLayerStack = std::make_unique<LayerStack>(LayerStack());
        //TODO: Init Render here

        //TODO: Init UI Layer here

    }

    Application::~Application()
    {
        pLayerStack.reset();
        pWindow.reset();
    }

    void Application::Run()
    {
        while (isRunning)
        {
            float time = (float)glfwGetTime();
            //calculate deltaTime here
            lastFrameTime = time;

            if (!isMinimized)
            {
                for (ILayer* layer : *pLayerStack)
                {
                    layer->OnUpdate();
                }

                for (ILayer* layer : *pLayerStack)
                {
                    layer->OnRender();
                }

                //TODO: Implement UI layer calls here
                //begin
                //render
                //end


                (*pWindow)->Update();
            }
        }
    }

    void Application::PushLayer(ILayer* layer)
    {
        pLayerStack->PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushUILayer(ILayer* layer)
    {
        pLayerStack->PushOverlay(layer);
        layer->OnAttach();
    }
}