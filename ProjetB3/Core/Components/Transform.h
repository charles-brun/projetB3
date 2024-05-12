#pragma once
#include "Component.h"
#include "../../Maths/Vector2.h"

class CTransform: public Component
{
public:
	DECLARE_CLASS(CTransform, Component)
	CTransform() = default;
	CTransform(const Vector2 & p) : position(p) {}
	
	void SetPosition(const Vector2& newPosition);
	Vector2* GetPosition();
	void SetRotation(const float& newRotation);
	float* GetRotation();
	void SetScale(const float& newScale);
	float* GetScale();

	void SetTransform(const Vector2& pPosition, const float& pRotation, const float& pScale);
	
private:
	Vector2 position = {0, 0};
	float rotation = 0;
	float scale = 1;
};
