#pragma once
#include "../../Maths/Vector2.h"
#include "../Game/BaseObject.h"
#include "../Components/Component.h"
#include "../Components/Transform.h"
#include "../Systems/InputManager.h"

class Entity: public BaseObject
{
public:
    DECLARE_CLASS(Entity, BaseObject)
    Entity() = default;
    void Update(const float& deltaTime);
    virtual void Initialize();
    virtual void AddComponent(const int& classID);
    Component* GetComponent(const int& classID) const;
    CTransform* GetTransform() const;
    ~Entity();
    int GetSceneID() const { return sceneID; }
    void SetSceneID(const int& pSceneID) { sceneID = pSceneID; }
private:
    std::map<int, Component*>components;
    int sceneID = 0;
};