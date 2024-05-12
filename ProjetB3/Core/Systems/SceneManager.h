#pragma once
#include "../../Utils/Singleton.h"
#include "../Scenes/Scene.h"

class SSceneManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SSceneManager)
    Scene* currentScene;
    static Scene* LoadScene(const int& classID);
    Scene* ChangeScene(const int& classID) const;
    static void UnloadScene(const Scene* scene);
};
