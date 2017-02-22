#include "ship.h"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#define PI 3.141592653

const float anguloAjuste = 90.0f;

ship::ship()
{}

ship::ship(const vector<Vector2> points)
{
	Point = points;
}

void ship::Draw()
{
	glLoadIdentity();

	limite();

	glTranslatef(Position.GetX(),Position.GetY(), 0.0f);

	glRotatef(angulo, 0.0f, 0.0f, 1.0f);

	cout << angulo << endl;

	glBegin(GL_LINE_LOOP);
		for (auto point : Point)
		{
			glVertex2f(point.GetX(), point.GetY());
		}
	glEnd();
}

void ship::Trasladar(Vector2 position)
{
	Position = position;
}

void ship::MoveUp()
{
	if (angulo != 0)
	{
		Vector2 velocity = Vector2(5.0 * cosf(anguloRadianes), 5.0 * sinf(anguloRadianes));
		Vector2 newPosition = Position + velocity;

		Trasladar(newPosition);
	}
	else
	{
		Vector2 velocity = Vector2(0, 1);
		Vector2 newPosition = Position + velocity;

		Trasladar(newPosition);
	}

}

void ship::MoveDown()
{
	if (angulo != 0)
	{
		Vector2 velocity = Vector2(-5.0 * cosf(anguloRadianes), -5.0 * sinf(anguloRadianes));
		Vector2 newPosition = Position + velocity;

		Trasladar(newPosition);
	}
	else
	{
		Vector2 velocity = Vector2(0, 1);
		Vector2 newPosition = Position - velocity;

		Trasladar(newPosition);
	}
}

void ship::MoveRight()
{
	angulo -= 5.0f;
	anguloRadianes = (angulo + anguloAjuste) * (PI / 180);	
}

void ship::MoveLeft()
{
	angulo += 5.0f;
	anguloRadianes = (angulo + anguloAjuste) * (PI / 180);
}

void ship::limite()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

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