#include "UIElement.h"

void UIElement::Update(const float& deltaTime)
{
}

void UIElement::SetVisible(bool isVisible)
{
    visible = isVisible;
    changeVisibility.BroadCast(visible);
}

void UIElement::SetPosition(Vector2 newPos)
{
    position = newPos;
    changePosition.BroadCast(position);
}

void UIElement::SetAnchor(Vector2 newPos)
{
    anchor = newPos;
    SetPosition(anchor + localOffset);
}

void UIElement::SetLocalOffset(Vector2 newPos)
{
    localOffset = newPos;
    SetPosition(anchor + localOffset);
}

void UIElement::SetSize(Vector2 newSize)
{
    size = newSize;
    changeSize.BroadCast(size);
}

void UIElement::AddChild(UIElement* element)
{
    if (childrenNodes.contains(element->name))
    {
        return;
    }
    this->changeVisibility.Bind(element, &UIElement::OnParentVisibilityChange);
    this->changePosition.Bind(element, &UIElement::OnParentPositionChange);
    this->changeSize.Bind(element, &UIElement::OnParentSizeChange);
    childrenNodes.insert(std::pair<std::string, UIElement*>(element->name, element));
}

UIElement* UIElement::GetChild(const std::string& pName) const
{
    if (!childrenNodes.contains(pName))
    {
        return nullptr;
    }
    return childrenNodes.find(pName)->second;
}

void UIElement::OnParentVisibilityChange(bool isVisible)
{
    SetVisible(isVisible);
}


void UIElement::OnParentSizeChange(Vector2 newSize)
{
    
}

void UIElement::OnParentPositionChange(Vector2 newPos)
{
    SetAnchor(newPos);
}
