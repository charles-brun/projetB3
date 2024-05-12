#pragma once
#include "../Core/Entities/Actor.h"
#include "../Core/Scenes/Scene.h"
#include "../Maths/Vector2.h"

class Factory
{
public:
    static EActor* SpawnActor(const int& classId, Vector2 startingPosition);
    static Component* CreateComponent(const int& classId);
    static Scene* CreateScene(const int& classID);
};
