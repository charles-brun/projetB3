#pragma once
#include <cmath>

class Vector2
{
public:
	float X = 0;
	float Y = 0;

	Vector2() = default;
	Vector2(float pX, float pY) : X(pX), Y(pY) {}

	auto operator + (const Vector2& pVector) const
	{
		return Vector2(X + pVector.X, Y + pVector.Y);
	}

	void operator += (const Vector2& pVector)
	{
		X += pVector.X;
		Y += pVector.Y;
	}

	auto operator - (const Vector2& pVector) const
	{
		return Vector2(X - pVector.X, Y - pVector.Y);
	}

	void operator -= (const Vector2& pVector)
	{
		X -= pVector.X;
		Y -= pVector.Y;
	}

	auto operator * (const float& pFloat) const
	{
		return Vector2(X * pFloat, Y * pFloat);
	}

	auto operator / (const float& pFloat) const
	{
		return Vector2(X / pFloat, Y / pFloat);
	}
	
	float Length()
	{
		return (float)sqrt((pow(X, 2) + pow(Y, 2)));
	}

	void Normalize()
	{
		*this / this->Length();
	}

	void SafeNormalize()
	{
		if (this->Length() != 0)
		{
			this->Normalize();
		}
	}

	void toSFML(Vector2)
	{
		
	}
	
	void Rotate()
	{
		
	}
};
