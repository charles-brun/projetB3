#pragma once
#include "../Core/Entities/UIElement.h"
#include "../Core/Game/Level.h"
#include "../Core/Scenes/Scene.h"
#include "../Maths/Vector2.h"

class Factory
{
public:
    inline DECLARE_SINGLETON(Factory)
    Entity* SpawnEntity(const int& classId, Vector2 startingPosition);
    Component* CreateComponent(const int& classId);
    Scene* CreateScene(const int& classID);
    UIElement* CreateUIElement(const int& classID);
    Level* CreateLevel(const int& classID);
    ~Factory();
private:
    std::vector<BaseObject*> allObjects;
};
