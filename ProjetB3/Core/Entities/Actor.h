#pragma once
#include "Entity.h"
#include "../Components/Physics.h"

class EActor: public Entity
{
public:
    DECLARE_CLASS(EActor, Entity)
    EActor() = default;
    void Move(const float& deltaTime) const;
    void Stop() const;
    void Initialize() override;
    virtual void Collide(int classID);
    virtual void TouchGround(const bool& isGrounded);
    CPhysics* GetPhysics() const;
};
