#include "Draw.h"
#include <SDL2/SDL_opengl.h>

draw::draw()
{

}

void draw::DrawT(unsigned int mode, vector<Vector2> Point)
{

	glBegin(mode);
	for (auto point : Point)
	{
		glVertex2f(point.GetX(), point.GetY());
	}
	glEnd();

}

Vector2 draw::PosAL()
{
	Vector2 PosAleatoria;
	float x = static_cast<float> (-500 + (500 + 500) * (rand() / static_cast<float> (RAND_MAX)));
	float y = static_cast<float> (-500 + (500 + 500) * (rand() / static_cast<float> (RAND_MAX)));
	PosAleatoria = Vector2(x, y);
	return PosAleatoria;
}

bool draw::Colliding(draw rhs)
{
	float x = PosAl.GetX() - rhs.PosAl.GetX();
	float y = PosAl.GetY() - rhs.PosAl.GetY();

	float radio = (radioAl + 40.0f) + rhs.radioAl;
	float Distancia = x * x + y * y;

	if (Distancia <= radio * radio)
		return true;

}