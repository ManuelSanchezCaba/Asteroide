#pragma once

#ifndef _ASTEROIDE_
#define _ASTEROIDE_

#include "Vector2.h"
#include <vector>
#include <time.h>
#include "Draw.h"
#include <random>

using namespace std;

class Asteroide : public draw
{
public:  Asteroide();
		~Asteroide();
		void DrawAst();
		void Mover();
		void Trasladar(Vector2 newPos);
		void limite();
		void GenerarCirculo();
		void Dividir();

private: float Angulo;
		 vector<Vector2> Point;
		 float Radio;

protected: Vector2 PositionAst;
};




#endif // !_ASTEROIDE_
