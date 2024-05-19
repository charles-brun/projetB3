#include "Scene.h"

void Scene::Load() {}

Entity* Scene::GetEntity(const int& sceneID) const
{
    if (!entities.contains(sceneID))
    {
        return nullptr;
    }
    return entities.find(sceneID)->second;
}

int Scene::AddEntity(Entity* entity)
{
    int sceneID = 0;
    if (entity != nullptr)
    {
        do
        {
            sceneID++;
        } while (entities.contains(sceneID));
        entity->SetSceneID(sceneID);
        entity->Initialize();
        entities.insert(std::pair<int, Entity*>(sceneID, entity));
    }
    return sceneID;
}

void Scene::RemoveEntity(const int& sceneID)
{
    if (!entities.contains(sceneID))
    {
        return;
    }
    const auto it = entities.find(sceneID);
    removedEntities.push_back(it->second);
    entities.erase(it);
}

void Scene::ClearEntities() const
{
    for (Entity* entity: removedEntities)
    {
        delete entity;
    }
}
