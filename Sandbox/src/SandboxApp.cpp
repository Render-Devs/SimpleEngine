#include "RenderLayer.h"
#include <SimpleEngine\Core\EntryPoint.h>
class Sandbox : public SimpleEngine::Core::Application
{
public:
    Sandbox()
    {
        //TODO: Push Layers here
        PushLayer(new RenderLayer());
    }

    ~Sandbox()
    {

    }
};

SimpleEngine::Core::Application* SimpleEngine::Core::CreateApplication()
{
    return new Sandbox();
}