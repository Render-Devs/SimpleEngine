#pragma once

extern SimpleEngine::Core::Application* SimpleEngine::Core::CreateApplication();

int main(int argc, char** argv)
{
    auto app = SimpleEngine::Core::CreateApplication();
    app->Run();
    delete app;

    return 0;
}