#include "SceneManager.h"
#include "../../Utils/Factory.h"

Scene* SSceneManager::LoadScene(const int& classID)
{
    currentScene = Factory::Get()->CreateScene(classID);
    currentScene->Load();
    return currentScene;
}

Scene* SSceneManager::ChangeScene(const int& classID)
{
    if (currentScene != nullptr)
    {
        UnloadScene(currentScene);
    }
    return LoadScene(classID);
}

void SSceneManager::UnloadScene(const Scene* scene)
{
    delete scene;
}
