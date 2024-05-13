#pragma once
#include <vector>

#include "../../Maths/Vector2.h"
#include "../../Utils/Delegate.h"
#include "../Game/BaseObject.h"

class UIElement: BaseObject
{
public:
    DECLARE_CLASS(UIElement, BaseObject)
    DECLARE_DELEGATE(ChangeVisibility, bool)
    ChangeVisibility changeVisibility;
    DECLARE_DELEGATE(ChangePosition, Vector2)
    ChangePosition changePosition;
    DECLARE_DELEGATE(ChangeSize, Vector2)
    ChangeSize changeSize;
    
    UIElement(const std::string& pName): name(pName) {}
    void Update(const float& deltaTime);
    
    void SetVisible(bool isVisible);
    bool IsVisible() const { return visible; }

    void SetPosition(Vector2 newPos);
    Vector2 GetPosition() const { return position; }

    void SetAnchor(Vector2 newPos);
    Vector2 GetAnchor() const { return anchor; }

    void SetLocalOffset(Vector2 newPos);
    Vector2 GetLocalOffset() const { return localOffset; }

    void SetSize(Vector2 newSize);
    Vector2 GetSize() const { return size; }
    
    UIElement* GetParent() const { return parentNode; }
    virtual void AddChild(UIElement* element);
    std::map<std::string, UIElement*> GetChildren() const { return childrenNodes; }
    UIElement* GetChild(const std::string& pName) const;
    
    virtual void OnParentVisibilityChange(bool isVisible);
    virtual void OnParentPositionChange(Vector2 newPos);
    virtual void OnParentSizeChange(Vector2 newSize);
private:
    bool visible = true;
    std::string name;
    Vector2 anchor;
    Vector2 localOffset;
    Vector2 position;
    Vector2 size;
    UIElement* parentNode = nullptr;
    std::map<std::string, UIElement*> childrenNodes;
};
