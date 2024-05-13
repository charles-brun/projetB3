#include "EntityManager.h"
#include "SceneManager.h"
#include "../Entities/Entity.h"

void SEntityManager::Update(const float& deltaTime)
{
    if (SSceneManager::Get()->currentScene != nullptr)
    {
        for (auto entity: SSceneManager::Get()->currentScene->GetEntities())
        {
            entity.second->Update(deltaTime);
        }

        //at end:
        SSceneManager::Get()->currentScene->ClearEntities();
    }
}

void SEntityManager::Draw(const float& deltaTime)
{
    if (SSceneManager::Get()->currentScene != nullptr)
    {
        for (auto entity: SSceneManager::Get()->currentScene->GetEntities())
        {
            entity.second->Draw(deltaTime);
        }
    }
}
