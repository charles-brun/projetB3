#include "Player.h"
#include "../Components/BoundingBox.h"
#include "../Components/AnimatedSprite.h"
#include "../Components/Physics.h"

EPlayer::EPlayer()
{
    AddComponent(CBoundingBox::StaticClass()->GetId());
    AddComponent(CAnimatedSprite::StaticClass()->GetId());
    AddComponent(CPhysics::StaticClass()->GetId());
}

void EPlayer::Initialize()
{
    EActor::Initialize();
}
