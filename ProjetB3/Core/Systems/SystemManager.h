#pragma once
#include "../../Utils/Singleton.h"

class SystemManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SystemManager)
    static void Update(const float& deltaTime);
};
