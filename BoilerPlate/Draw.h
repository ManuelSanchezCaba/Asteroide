#pragma once

#ifndef _DRAW_
#define _DRAW_

#include <vector>
#include "Vector2.h"
#include <iostream>

using namespace std;

class draw
{
public: draw();
		void DrawT(unsigned int mode, vector<Vector2> point);
		void setPosShip(Vector2 pos);
		void setRadioAst(float ra);
		void setRadioShip(float ra);
		bool Colision(Vector2 PositionAst);

private: float RadioAst;
		 float RadioShip;
		 Vector2 PositionShip;
};


#endif // !_DRAW_
