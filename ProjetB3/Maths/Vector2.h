#pragma once
#include <cmath>

class Vector2
{
public:
	float X = 0;
	float Y = 0;

	Vector2() = default;
	Vector2(float pX, float pY) : X(pX), Y(pY) {}
	static Vector2 ZERO() { return {0, 0};}
	
	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,
	};

	static Vector2 GetDirection(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return {0, -1};
		case LEFT:
			return {-1, 0};
		case DOWN:
			return {0, 1};
		case RIGHT:
			return {1, 0};
		}
		return ZERO();
	}

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

	void operator *= (const float& pFloat)
	{
		X *= pFloat;
		Y *= pFloat;
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
