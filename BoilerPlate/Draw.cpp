#include "Draw.h"
#include <SDL2/SDL_opengl.h>

draw::draw()
{
	//PositionAst = Vector2(0, 0);
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

void draw::setPosShip(Vector2 pos)
{
	PositionShip = pos;
}

void draw::setRadioAst(float ra)
{
	RadioAst = ra;
}

void draw::setRadioShip(float ra)
{
	RadioShip = ra;
}

bool draw::Colision(Vector2 PositionAst)
{
	cout << PositionShip.GetX() << " y " << PositionShip.GetY() << endl;
	float x = PositionShip.GetX() - PositionAst.GetX();
	float y = PositionShip.GetY() - PositionAst.GetY();

	float radio = RadioAst + RadioShip;

	float Dis = x * x + y * y;

	return (radio * radio >= Dis);
}