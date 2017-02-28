#pragma once

#ifndef _COLISION_
#define _COLISION_

#include "Vector2.h"
#include "Draw.h"

using namespace std;

class colision
{
public: colision();
		bool setColision();
		void setPosShip(Vector2 pos);
		void setPosAst(Vector2 pos);
		void setRadioAst(float ra);
		void setRadioShip(float ra);

private: Vector2 PosShip;
		 Vector2 PosAst;
		 float RadioAst;
		 float RadioShip;
};



#endif // !_COLISION_
