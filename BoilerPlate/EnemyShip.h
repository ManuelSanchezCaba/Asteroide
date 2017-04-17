#pragma once

#ifndef _ENEMYSHIP_
#define _ENEMYSHIP_

#include <iostream>
#include <vector>
#include "Vector2.h"
#include "Draw.h"

using namespace std;

class EnemyShip : public draw
{
public: EnemyShip();
		void Draw();
		void Update(float deltatime);
		void Trasladar(Vector2 newPos);
		void limite();
		void setPoint();

private: vector<Vector2> initShip;
		 vector<Vector2> initShip2;
		 Vector2 Position;
		 vector<Vector2> Circulo;
		 float Radio;
		 float Masa;
		 float IncreX;
};




#endif // !_ENEMYSHIP_
