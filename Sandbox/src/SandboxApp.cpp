#include <SimpleEngine.h>

class Sandbox : public SimpleEngine::Core::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

SimpleEngine::Core::Application* SimpleEngine::Core::CreateApplication()
{
    return new Sandbox();
}