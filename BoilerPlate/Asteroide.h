#pragma once

#ifndef _ASTEROIDE_
#define _ASTEROIDE_

#include "Vector2.h"
#include <vector>
#include <time.h>
#include "Draw.h"
#include <random>
#include "Colision.h"

using namespace std;

class Asteroide : public draw
{
public: Asteroide(Vector2 pos, int size);
		Asteroide();
		~Asteroide();
		void DrawAst();
		void Mover(float deltaTime);
		void Trasladar(Vector2 newPos);
		void limite();
		void GenerarCirculo();
		void Dividir(int Cantidad, int size, Vector2 position);
		void setMasa();
		int getSize();

private: float Angulo;
		 vector<Vector2> Point;
		 float RadioAst;
		 float Masa;
		 float AnguloRadian;
		 int Size;
		 Vector2 PositionAst;
};




#endif // !_ASTEROIDE_
