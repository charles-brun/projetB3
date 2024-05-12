#pragma once
#include "Transform.h"

void CTransform::SetPosition(const Vector2& newPosition)
{
    position = newPosition;
}

Vector2* CTransform::GetPosition()
{
    return &position;
}

void CTransform::SetRotation(const float& newRotation)
{
    rotation = newRotation;
}

float* CTransform::GetRotation()
{
    return &rotation;
}

void CTransform::SetScale(const float& newScale)
{
    scale = newScale;
}

float* CTransform::GetScale()
{
    return &scale;
}

void CTransform::SetTransform(const Vector2& pPosition, const float& pRotation, const float& pScale)
{
    position = pPosition;
    rotation = pRotation;
    scale = pScale;
}
