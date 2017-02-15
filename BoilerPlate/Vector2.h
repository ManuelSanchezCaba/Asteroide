#pragma once

#ifndef _VECTOR2_
#define _VECTOR2_

class Vector2
{
public: Vector2();
		Vector2(float x, float y);
		const float GetX();
		const float GetY();

private:   float X;
		   float Y;
		   float Length;
};
#endif // !_VECTOR2_