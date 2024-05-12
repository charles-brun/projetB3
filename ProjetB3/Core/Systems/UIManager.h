#pragma once
#include "../../Utils/Singleton.h"

class SUIManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SUIManager)
    static void Update();
};
