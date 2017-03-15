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
#include <conio.h>
#include <time.h>

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
	void setPoint();
	Vector2 getPosition();
	void Reiniciar();

private: vector<Vector2> Point;
		 vector<Vector2> Circulo;
		 Vector2 Velocity;
		 float Angulo;
		 float AnguloRadianes;
		 float Masa;
		 int Index;
		 float RadioShip;
		 float Speed;
		 Vector2 Min;
		 Vector2 Max;

protected: Vector2 Position;
};


#endif // !_SHIP_

