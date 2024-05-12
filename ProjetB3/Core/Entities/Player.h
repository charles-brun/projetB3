#pragma once
#include "Actor.h"

class EPlayer: public EActor
{
public:
    DECLARE_CLASS(EPlayer, EActor)
    EPlayer();
    void Initialize() override;
};
