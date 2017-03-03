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
		Vector2 PosAL();
		bool Colliding(draw rhs);
		virtual void setPosAl(Vector2 pos) { PosAl = pos; }
		virtual void setRadioAl(float ra) { radioAl = ra; }

protected: Vector2 PosAl;
		   float radioAl;

};


#endif // !_DRAW_
