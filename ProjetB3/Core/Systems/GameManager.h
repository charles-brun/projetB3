#pragma once
#include "../../Utils/Singleton.h"

class SGameManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SGameManager)
    static void Initialize();
    static void Update();
    static void Stop();
};
