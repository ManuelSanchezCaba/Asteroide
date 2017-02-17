#pragma once

#ifndef _SHIP_
#define _SHIP_

using namespace std;

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Vector2.h"

class ship
{
public:
	ship();
	ship(const vector<Vector2> points);
	void Draw();
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	void Trasladar(Vector2 position);

private: vector<Vector2> Point;
		 Vector2 Position;
		 float angulo;
		 float anguloRadianes;
};


#endif // !_SHIP_

