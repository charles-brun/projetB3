#pragma once
#include "../Entities/Entity.h"
#include "../Game/BaseObject.h"

class Scene: BaseObject
{
public:
    DECLARE_CLASS(Scene, BaseObject)
    virtual void Load();
    ~Scene() = default;
    std::map<int, Entity*> GetEntities() { return entities; }
    std::vector<Entity*> GetRemovedEntities() { return removedEntities; }
    Entity* GetEntity(const int& sceneID) const;
    int AddEntity(Entity* entity);
    void RemoveEntity(const int& sceneID);
    void ClearEntities() const;
private:
    std::map<int, Entity*> entities;
    std::vector<Entity*> removedEntities;
};
