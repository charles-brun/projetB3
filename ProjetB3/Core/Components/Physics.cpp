#include "Physics.h"
#include <algorithm>
#include "../../Utils/WorldEnvironment.h"
#include "../Entities/Entity.h"

void CPhysics::Initialize()
{
    Component::Initialize();
    SetGravity();
}

void CPhysics::Update(const float& deltaTime)
{
    if (IsGrounded())
    {
        DisableGravity();
        ApplyGroundFriction(deltaTime);
        if (inertia.Y > 0)
        {
            inertia.Y = 0;
        }
    } else
    {
        ApplyGravity();
        ApplyAirFriction(deltaTime);
    }
    SetVelocity(inertia + GetConstantForces());
}

void CPhysics::SetPhysics(float pWeight, float pAirFriction, float pGroundFriction)
{
    weight = pWeight;
    airFriction = std::ranges::clamp(pAirFriction, 0.0f, 1.0f);
    groundFriction = std::ranges::clamp(pGroundFriction, 0.0f, 1.0f);
}

void CPhysics::AddImpulse(Vector2 force)
{
    if ((velocity + force).Length() <= maxVelocity)
    {
        inertia += force;
    }
}

void CPhysics::AddConstantForce(const std::string& name, Vector2 force)
{
    if (constantForces.contains(name))
    {
        return;
    }
    constantForces.insert(std::pair(name, force));
}

void CPhysics::RemoveConstantForce(const std::string& name)
{
    if (!constantForces.contains(name))
    {
        return;
    }
    constantForces.erase(name);
}

Vector2 CPhysics::GetConstantForces() const
{
    Vector2 forces = Vector2::ZERO();
    for (auto force: constantForces)
    {
        forces += force.second;
    }
    return forces;
}

void CPhysics::SetGravity(Vector2 direction)
{
    gravity = direction * WorldEnvironment::Get()->GetGravity() * weight;
}

void CPhysics::ApplyGravity()
{
    if (constantForces.contains("gravity"))
    {
        return;
    }
    AddConstantForce("gravity", gravity);
}

void CPhysics::DisableGravity()
{
    if (constantForces.contains("gravity"))
    {
        return;
    }
    RemoveConstantForce("gravity");
}

void CPhysics::ApplyAirFriction(const float& deltaTime)
{
    inertia *= 1 - (airFriction * deltaTime);
}

void CPhysics::ApplyGroundFriction(const float& deltaTime)
{
    inertia *= 1 - (groundFriction * deltaTime);
}

void CPhysics::Stop()
{
    inertia = Vector2::ZERO();
}
