#include "SceneManager.h"
#include "../../Utils/Factory.h"

Scene* SSceneManager::LoadScene(const int& classID)
{
    Scene* scene = Factory::CreateScene(classID);
    scene->Load();
    return scene;
}

Scene* SSceneManager::ChangeScene(const int& classID) const
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
