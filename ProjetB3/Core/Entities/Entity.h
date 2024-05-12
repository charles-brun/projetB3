#pragma once
#include "../Game/BaseObject.h"
#include "../Components/Component.h"
#include "../Systems/InputManager.h"

class Entity: BaseObject
{
public:
    DECLARE_CLASS(Entity, BaseObject)
    Entity();
    void Update(float deltaTime);
    void OnNewEntityCreate(int ID);
    virtual void Initialize();
    void AddComponent(const int& classID);
    Component* GetComponent(const int& classID) const;
    ~Entity();
    void OnKeyDown(SInputManager::KeyState keyState);
private:
    std::map<int, Component*>components;
};
