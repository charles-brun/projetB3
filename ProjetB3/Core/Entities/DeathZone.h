#pragma once
#include "Entity.h"

class EDeathZone: Entity
{
public:
    DECLARE_CLASS(EDeathZone, Entity)
    void Initialize() override;
};
