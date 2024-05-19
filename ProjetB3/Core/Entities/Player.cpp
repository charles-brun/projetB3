#include "Player.h"
#include "DeathZone.h"
#include "Threat.h"

void EPlayer::Collide(int classID)
{
    EActor::Collide(classID);
    if (classID == EDeathZone::StaticClass()->GetId() || classID == EThreat::StaticClass()->GetId())
    {
        threatCollided.BroadCast();
    }
    Stop();
}

void EPlayer::TouchGround(const bool& isGrounded)
{
    EActor::TouchGround(isGrounded);
}

void EPlayer::OnMoveLeft(SInputManager::KeyState keyState)
{
    if (keyState == SInputManager::Pressed)
    {
        GetPhysics()->AddImpulse(Vector2::GetDirection(Vector2::LEFT) * moveSpeed);
    }
}

void EPlayer::OnMoveRight(SInputManager::KeyState keyState)
{
    if (keyState == SInputManager::Pressed)
    {
        GetPhysics()->AddImpulse(Vector2::GetDirection(Vector2::RIGHT) * moveSpeed);
    }
}

void EPlayer::OnJump(SInputManager::KeyState keyState)
{
    if (keyState == SInputManager::Pressed)
    {
        GetPhysics()->AddImpulse(Vector2::GetDirection(Vector2::UP) * jumpForce);
    }
}
