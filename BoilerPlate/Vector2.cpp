#include "Vector2.h"

Vector2::Vector2()
{
	X = 0.0;
	Y = 0.0;
	Length = 0.0;
}

Vector2::Vector2(float x, float y)
{
	X = x;
	Y = y;
	Length = 0;
}

const float Vector2::GetX()
{
	return X;
}

const float Vector2::GetY()
{
	return Y;
}