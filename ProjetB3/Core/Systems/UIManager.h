#pragma once
#include "../../Utils/Singleton.h"

class SUIManager
{
public:
    inline DECLARE_SINGLETON(SUIManager)
    void Update(const float& deltaTime);
};
