#pragma once
#include "Component.h"
#include "../../Maths/Vector2.h"

class CPhysics: public Component
{
public:
    DECLARE_CLASS(CPhysics, Component)
    CPhysics() = default;
    Vector2 velocity = {0,0};
};
