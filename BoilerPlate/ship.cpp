#include "ship.h"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#define PI 3.141592653

const float AnguloAjuste = 90.0f;
const float Fuerza = 3.0f;
const float Drag = 1.0f;
const float Max_Speed = 350.0f;

ship::ship()
	: Masa(1.0f)
	, Velocity(0,0)
{}

ship::ship(const vector<Vector2> points)
{
	Point = points;
	Angulo = 0;
	AnguloRadianes = (Angulo + AnguloAjuste) * (PI / 180);
}

void ship::Draw()
{
	glLoadIdentity();

	colic.setRadioShip(10.0f);

	limite();

	glTranslatef(Position.GetX(),Position.GetY(), 0.0f);

	glRotatef(Angulo, 0.0f, 0.0f, 1.0f);
	
	bool f = colic.setColision();
	/*
	if (f == true)
		cout << "Impacto" << endl;
	else
		cout << "No impacto" << endl;*/

	DrawT(GL_LINE_LOOP, Point);

}

void ship::Trasladar(Vector2 position)
{
	Position = position;
	colic.setPosShip(Position);
}

void ship::MoveUp()
{
		setMasa();
		Vector2 Velocity = Vector2((Fuerza / Masa) * cosf(AnguloRadianes), (Fuerza / Masa) * sinf(AnguloRadianes));
		Vector2 newPosition = Position + Velocity;

		Trasladar(newPosition);
}

void ship::MoveDown()
{
		setMasa();
		Vector2 Velocity = Vector2(-(Fuerza / Masa) * cosf(AnguloRadianes), -(Fuerza / Masa) * sinf(AnguloRadianes));
		Vector2 newPosition = Position + Velocity;

		Trasladar(newPosition);
}

void ship::MoveRight()
{
	Angulo -= 5.0f;
	AnguloRadianes = (Angulo + AnguloAjuste) * (PI / 180);	
}

void ship::MoveLeft()
{
	Angulo += 5.0f;
	AnguloRadianes = (Angulo + AnguloAjuste) * (PI / 180);
}

void ship::limite()
{
	if (Position.GetX() > 600)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetX() < -600)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetY() > 350)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetY() < -350)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
}

void ship::setMasa()
{
	Masa = Fuerza / 10.0f;
}
