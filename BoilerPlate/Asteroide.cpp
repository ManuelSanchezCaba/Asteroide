#include <iostream>
#include "Asteroide.h"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#define PI 3.141592653f

const float Drag = 1.0f;
const float Min = 12.5f;
const float Max = 22.5f;

Asteroide::Asteroide()
	: Radio(30.0f)
	, Angulo(0)
{
	GenerarCirculo();
	//setPosAste(Position);
}

Asteroide::~Asteroide()
{}

void Asteroide::DrawAst()
{
	glLoadIdentity();

	setRadioAst(Radio);

	Mover();

	limite();

	glTranslatef(PositionAst.GetX(), PositionAst.GetY(), 0.0f);

	glRotated(Angulo, 0.0f, 0.0f, 1.0f);

	bool f = Colision(PositionAst);

	DrawT(GL_LINE_LOOP, Point);

}

void Asteroide::Mover()
{
	Vector2 velocity = Vector2(static_cast<float> (rand()%5), static_cast<float> (rand()%5));
	Vector2 newPos = PositionAst + velocity;

	Angulo += 0.9f;

	Trasladar(newPos);
}

void Asteroide::Dividir()
{}

void Asteroide::limite()
{
	if (PositionAst.GetX() > 570)
	{
		Vector2 newPos = Vector2(PositionAst.GetX() * -1, PositionAst.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionAst.GetX() < -570)
	{
		Vector2 newPos = Vector2(PositionAst.GetX() * -1, PositionAst.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionAst.GetY() > 320)
	{
		Vector2 newPos = Vector2(PositionAst.GetX() * -1, PositionAst.GetY() * -1);
		Trasladar(newPos);
	}
	else if (PositionAst.GetY() < -320)
	{
		Vector2 newPos = Vector2(PositionAst.GetX() * -1, PositionAst.GetY() * -1);
		Trasladar(newPos);
	}
}

void Asteroide::Trasladar(Vector2 newPos)
{
	PositionAst = newPos;
}

void Asteroide::GenerarCirculo()
{
	int min = static_cast<int> (Min / 1);
	int max = static_cast<int> (Max / 1);

	for (int point = 0; point < 16; ++point)
	{
		float valor = static_cast<float> (Radio * PI * (point / 16.0f));
		float x = Radio * cosf(valor) - rand()%min;
		float y = Radio * sinf(valor) - rand()%max;
		Point.push_back(Vector2(x, y));
	}
}