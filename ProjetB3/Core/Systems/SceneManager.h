#pragma once
#include "../../Utils/Singleton.h"
#include "../Scenes/Scene.h"

class SSceneManager
{
public:
    inline DECLARE_SINGLETON(SSceneManager)
    Scene* currentScene;
    Scene* LoadScene(const int& classID);
    Scene* ChangeScene(const int& classID);
    void UnloadScene(const Scene* scene);
};
