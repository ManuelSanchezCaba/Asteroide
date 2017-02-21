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
	angulo = 0;
	anguloRadianes = 0;
}

void ship::Draw()
{
	glLoadIdentity();

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
		Vector2 velocity = Vector2(3.0 * cosf(anguloRadianes), 3.0 * sinf(anguloRadianes));
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
		Vector2 velocity = Vector2(-3.0 * cosf(anguloRadianes), -3.0 * sinf(anguloRadianes));
		Vector2 newPosition = Position + velocity;

		Trasladar(newPosition);
	}
	else
	{
		Vector2 velocity = Vector2(0, -1);
		Vector2 newPosition = Position + velocity;

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