#pragma once

#ifndef _DRAW_
#define _DRAW_

#include <vector>
#include "Vector2.h"
#include <iostream>
#include "Colision.h"

using namespace std;

class draw
{
public: draw();
		void DrawT(unsigned int mode, vector<Vector2> point);

};


#endif // !_DRAW_
