#pragma once

#ifndef _SHIP_
#define _SHIP_

using namespace std;

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Vector2.h"
#include "Draw.h"
#include "Asteroide.h"

class ship : public draw
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
	void limite();
	void setMasa();

private: vector<Vector2> Point;
		 Vector2 Velocity;
		 float Angulo;
		 float AnguloRadianes;
		 float Masa;
		 int Index;

protected: Vector2 Position;
};


#endif // !_SHIP_

