#pragma once
#include "Actor.h"

class EPlayer: public EActor
{
public:
    DECLARE_CLASS(EPlayer, EActor)
    DECLARE_DELEGATE(ThreatCollided)
    ThreatCollided threatCollided;
    void Collide(int classID) override;
    void TouchGround(const bool& isGrounded) override;
    void OnMoveLeft(SInputManager::KeyState keyState);
    void OnMoveRight(SInputManager::KeyState keyState);
    void OnJump(SInputManager::KeyState keyState);
private:
    float moveSpeed = 1.0;
    float jumpForce = 10.0;
};
