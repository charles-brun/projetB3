#include "DeathZone.h"

#include "../Components/BoundingBox.h"

void EDeathZone::Initialize()
{
    Entity::Initialize();
    AddComponent(CBoundingBox::StaticClass()->GetId());
}
