#pragma once
#include <set>
#include <string>

class ClassType
{
public:
    ClassType(const std::string& className, ClassType* parentClass, int ClassId): name(className), id(ClassId)
    {
        if (parentClass != nullptr)
        {
            this->SetParents(parentClass->GetParents());
            this->AddParent(parentClass);
        }
    }
    std::string GetName()
    {
        return this->name;
    }
    int GetId() const
    {
        return this->id;
    }
    std::set<ClassType*> GetParents()
    {
        return this->parents;
    }
    void SetParents(std::set<ClassType*> classParents)
    {
        if (!classParents.empty())
        {
            this->parents = std::move(classParents);
        }
    }
    void AddParent(ClassType* parentClass)
    {
        this->parents.insert(parentClass);
    }
    
private:
    int id;
    std::string name;
    std::set<ClassType*> parents;
};
