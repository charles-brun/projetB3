#pragma once
#include "../../Utils/Delegate.h"
#include "../../Utils/Singleton.h"

class SEntityManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SEntityManager)
    
    DECLARE_DELEGATE(FEntityCreation, int)
    FEntityCreation NewEntityCreated;

    void CreateNewEntity();
};
