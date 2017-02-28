#include "Colision.h"

colision::colision()
{
	PosAst = Vector2(0, 0);
	PosShip = Vector2(0, 0);
}

bool colision::setColision()
{
	//cout << PosShip.GetX() << " y " << PosShip.GetY() << endl;
	float x = PosShip.GetX() - PosAst.GetX();
	float y = PosShip.GetY() - PosAst.GetY();

	float radio = RadioAst + RadioShip;

	float Dis = x * x + y * y;

	return (radio * radio >= Dis);
}

void colision::setPosShip(Vector2 pos)
{
	PosShip = pos;
}

void colision::setPosAst(Vector2 pos)
{
	PosAst = pos;
	setColision();
}

void colision::setRadioAst(float ra)
{
	RadioAst = ra;
}

void colision::setRadioShip(float ra)
{
	RadioShip = ra;
}