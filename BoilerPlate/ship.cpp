#include "ship.h"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#define PI 3.141592653

const float AnguloAjuste = 90.0f;
const float Fuerza = 3.0f;
const float Drag = 0.999f;
const float Max_Speed = 10.0f;

ship::ship()
	: Masa(1.0f)
	, Velocity(0,0)
	, RadioShip(40.0f)
	, Index(0)
{
	setRadioAl(RadioShip);
	Min = GenerarMin(Position, RadioShip);
	Max = GenerarMax(Position, RadioShip);
}

ship::ship(const vector<Vector2> points)
{
	Point = points;
	Angulo = 0;
	AnguloRadianes = (Angulo + AnguloAjuste) * (PI / 180);
	RadioShip = 40.0f;
	setRadioAl(RadioShip);
	Min = GenerarMin(Position, RadioShip);
	Max = GenerarMax(Position, RadioShip);
}

void ship::Draw()
{
	glLoadIdentity();

	limite();

	glTranslatef(Position.GetX(),Position.GetY(), 0.0f);

	glRotatef(Angulo, 0.0f, 0.0f, 1.0f);

	glColor3f(1.0f, 1.0f, 1.0f);

	DrawT(GL_LINE_LOOP, Point);

 	DrawSquare(GL_LINE_LOOP, Min, Max, Position);
}

void ship::Trasladar(Vector2 position)
{
	Position = position;
	setPosAl(Position);
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

		newPosition = Vector2(newPosition.GetX() * Drag, newPosition.GetY() * Drag);
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

void ship::setPoint()
{
	for (int point = 0; point < 16; ++point)
	{
		float valor = static_cast<float> (2.0f * PI * (point / 16.0f));
		float x = RadioShip * cosf(valor);
		float y = RadioShip * sinf(valor);
		Circulo.push_back(Vector2(x, y));
	}
}

Vector2 ship::getPosition()
{
	return Position;
}

void ship::Reiniciar()
{
	Position = Vector2(0.0f, 0.0f);
	Angulo = 0;
	AnguloRadianes = 0;

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	for (auto point : Point)
	{
		glVertex2f(point.GetX(), point.GetY());
	}
	glEnd();

}