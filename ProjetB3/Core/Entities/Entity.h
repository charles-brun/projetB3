#pragma once
#include "../Game/BaseObject.h"
#include "../Components/Component.h"
#include "../Systems/InputManager.h"

class Entity: BaseObject
{
public:
    DECLARE_CLASS(Entity, BaseObject)
    Entity();
    void Update(const float& deltaTime);
    void Draw(const float& deltaTime);
    //void OnNewEntityCreate(int ID);
    virtual void Initialize();
    virtual void AddComponent(const int& classID);
    Component* GetComponent(const int& classID) const;
    ~Entity();
    int GetSceneID() const { return sceneID; }
    void SetSceneID(const int& pSceneID) { sceneID = pSceneID; }
private:
    std::map<int, Component*>components;
    int sceneID = 0;
};
