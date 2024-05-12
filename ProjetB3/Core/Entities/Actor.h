#pragma once
#include "Entity.h"
#include "../Components/Component.h"

class EActor: public Entity
{
public:
    DECLARE_CLASS(EActor, Entity)
    EActor() = default;
};
