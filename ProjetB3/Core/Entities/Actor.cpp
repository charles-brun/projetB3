#include "Actor.h"
#include "../Components/BoundingBox.h"
#include "../Components/AnimatedSprite.h"
#include "../Components/Physics.h"
#include "../Components/Transform.h"

void EActor::Initialize()
{
    Entity::Initialize();
    AddComponent(CBoundingBox::StaticClass()->GetId());
    AddComponent(CAnimatedSprite::StaticClass()->GetId());
    AddComponent(CPhysics::StaticClass()->GetId());
}

void EActor::Move(const float& deltaTime) const
{
    CTransform* transform = GetTransform();
    CPhysics* physics = GetPhysics();
    if (transform == nullptr || physics == nullptr)
    {
        return;
    }
    transform->SetPosition(*transform->GetPosition() + physics->GetVelocity() * deltaTime);
}

void EActor::Stop() const
{
    if (GetComponent(CPhysics::StaticClass()->GetId()) == nullptr)
    {
        return;
    }
    dynamic_cast<CPhysics*>(GetComponent(CPhysics::StaticClass()->GetId()))->Stop();
}

void EActor::Collide(int classID) {}

void EActor::TouchGround(const bool& isGrounded)
{
    if (GetPhysics() == nullptr)
    {
        return;
    }
    GetPhysics()->SetGrounded(isGrounded);
}

CPhysics* EActor::GetPhysics() const
{
    if (GetComponent(CPhysics::StaticClass()->GetId()) == nullptr)
    {
        return nullptr;
    }
    return dynamic_cast<CPhysics*>(GetComponent(CPhysics::StaticClass()->GetId()));
}
