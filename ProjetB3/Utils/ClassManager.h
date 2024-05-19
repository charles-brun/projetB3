#pragma once
#include <map>
#include "ClassType.h"
#include "Singleton.h"

class ClassManager
{
public:
    inline DECLARE_SINGLETON(ClassManager)
    ClassType* GetClass(const std::string& className, ClassType* parentClass);
    ClassType* GetClassByID(const int& ID) const;
private:
    std::map<int, ClassType*> classTypes;
    ClassType* AddClass(const std::string& className, ClassType* parentClass);
};
