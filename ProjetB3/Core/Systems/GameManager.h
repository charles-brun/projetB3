#pragma once
#include "../../Utils/Singleton.h"

class SGameManager
{
public:
    inline DECLARE_SINGLETON(SGameManager)
    static void Initialize();
    static void Update();
    static void Stop();
};
