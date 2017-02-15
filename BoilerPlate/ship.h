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
	void Move(int x, int y);
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

private: vector<Vector2> Point;
};


#endif // !_SHIP_

