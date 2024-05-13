#pragma once
#include "../../Utils/Delegate.h"
#include "../../Utils/Singleton.h"

class SEntityManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SEntityManager)
    static void Update(const float& deltaTime);
    static void Draw(const float& deltaTime);
};