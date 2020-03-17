namespace Engine
{
    _declspec(dllimport) int Init();
}

int main()
{
    return Engine::Init();
}