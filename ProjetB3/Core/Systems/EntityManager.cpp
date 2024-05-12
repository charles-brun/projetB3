#include "EntityManager.h"

void SEntityManager::CreateNewEntity()
{
    NewEntityCreated.BroadCast(0);
}
