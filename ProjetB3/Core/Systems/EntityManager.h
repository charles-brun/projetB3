#pragma once
#include "../../Utils/Delegate.h"
#include "../../Utils/Singleton.h"

class SEntityManager
{
public:
    inline DECLARE_SINGLETON(SEntityManager)
    void Update(const float& deltaTime);
};