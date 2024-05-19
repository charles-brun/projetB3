#pragma once
#include "Singleton.h"

class WorldEnvironment
{
public:
    inline DECLARE_SINGLETON(WorldEnvironment)
    float GetGravity() const { return gravity; }
    void SetGravity(float pGravity) { gravity = pGravity; }
private:
    float gravity = 1.0;
};
