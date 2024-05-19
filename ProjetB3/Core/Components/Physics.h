#pragma once
#include "Component.h"
#include "../../Maths/Vector2.h"

class CPhysics: public Component
{
public:
    DECLARE_CLASS(CPhysics, Component)
    CPhysics() = default;
    void Initialize() override;
    void Update(const float& deltaTime) override;
    Vector2 GetInertia() const { return inertia; }
    Vector2 GetVelocity() const { return velocity; }
    void SetInertia(Vector2 pInertia) { inertia = pInertia; }
    void SetVelocity(Vector2 pVelocity) { velocity = pVelocity; }
    void SetMaxVelocity(float pMaxVelocity) { maxVelocity = pMaxVelocity; }
    void SetPhysics(float pWeight, float pAirFriction, float pGroundFriction);
    void AddImpulse(Vector2 force);
    void AddConstantForce(const std::string& name, Vector2 force);
    void RemoveConstantForce(const std::string& name);
    Vector2 GetConstantForces() const;
    void SetGravity(Vector2 direction = Vector2::GetDirection(Vector2::DOWN));
    void ApplyGravity();
    void DisableGravity();
    void ApplyAirFriction(const float& deltaTime);
    void ApplyGroundFriction(const float& deltaTime);
    bool IsGrounded() const { return isGrounded; }
    void SetGrounded(bool grounded) { isGrounded = grounded; }
    void Stop();
private:
    bool isGrounded;
    float weight = 1.0;
    Vector2 gravity;
    float airFriction = 0.5;
    float groundFriction = 0.5;
    std::map<std::string, Vector2> constantForces;
    Vector2 inertia = Vector2::ZERO();
    Vector2 velocity = Vector2::ZERO();
    float maxVelocity;
};
