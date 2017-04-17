#include "EnemyShip.h"
#include <SDL2/SDL_opengl.h>
#include "Draw.h"
#include <cmath>
#include <algorithm>

#define PI 3.141592653

const float Max_Speed = 10.0f;
const float Fuerza = 1.25f;

EnemyShip::EnemyShip()
	: Position(Vector2(400, 0))
	, IncreX(-565.0f)
	, Radio(15.0f)
	, Time(0)
	, Time2(0)
	, Angulo(0)
{
	initShip2.push_back(Vector2(-7, 0));
	initShip2.push_back(Vector2(-7, 11));
	initShip2.push_back(Vector2(-5, 13));
	initShip2.push_back(Vector2(-3, 14));
	initShip2.push_back(Vector2(0, 15));
	initShip2.push_back(Vector2(3, 14));
	initShip2.push_back(Vector2(5, 12));
	initShip2.push_back(Vector2(6, 11));
	initShip2.push_back(Vector2(6, 0));
	initShip2.push_back(Vector2(0, 0));
	initShip2.push_back(Vector2(-7, 0));

	initShip.push_back(Vector2(0, -8));
	initShip.push_back(Vector2(8, -7));
	initShip.push_back(Vector2(10, -6));
	initShip.push_back(Vector2(15, -1));
	initShip.push_back(Vector2(16, 0));
	initShip.push_back(Vector2(13, 4));
	initShip.push_back(Vector2(9, 7));
	initShip.push_back(Vector2(6, 8));
	initShip.push_back(Vector2(0, 8));
	initShip.push_back(Vector2(-6, 8));
	initShip.push_back(Vector2(-9, 7));
	initShip.push_back(Vector2(-12, 5));
	initShip.push_back(Vector2(-13, 4));
	initShip.push_back(Vector2(-15, 2));
	initShip.push_back(Vector2(-16, 0));
	initShip.push_back(Vector2(-13, -4));
	initShip.push_back(Vector2(-8, -7));
	initShip.push_back(Vector2(-6, -8));
	initShip.push_back(Vector2(0, -8));
	
	setPoint();
	setRadioAl(Radio);
}

void EnemyShip::Draw()
{
	glLoadIdentity();

	limite();

	glTranslatef(Position.GetX(), Position.GetY(), 0.0f);

	glRotatef(Angulo, 0.0f, 0.0f, 1.0f);
	
	DrawT(GL_LINE_LOOP, initShip);
	DrawT(GL_LINE_LOOP, initShip2);
	
	for (int i = 0; i < Balas.size(); i++)
		Balas[i]->Render();
}

void EnemyShip::Update(float deltatime)
{
	float y = IncreX * (PI / 180);
	cout << Angulo << endl;
	if (Time == 200)
	{
		if(Time2 == 0)
			Disparar();

		if (Time2 == 50)
		{
			Time = 0;
			Time2 = 0;
		}
		else
			Time2++;
	}
	else
	{
		Time++;
		Position = Vector2(IncreX, 300 * sinf(y));
		IncreX += 0.500f;
		if (300 * sinf(y) >= 0)
		{
			Angulo -= 0.11f;
		}
		else if (300 * sinf(y) < 0)
		{
			Angulo += 0.11f;
		}
	}

	for (int i = 0; i < Balas.size(); i++)
	{
		Balas[i]->Update(deltatime);
		if (Balas[i]->m_lifeTime >= 50)
		{
			EliminarBala(Balas[i]);
			break;
		}
	}
}

void EnemyShip::limite()
{
	if (Position.GetX() > 570)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetX() < -570)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetY() > 320)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
	else if (Position.GetY() < -320)
	{
		Vector2 newPos = Vector2(Position.GetX() * -1, Position.GetY() * -1);
		Trasladar(newPos);
	}
}

void EnemyShip::Trasladar(Vector2 newPos)
{
	Position = static_cast<Vector2> (newPos);
	IncreX = -570;
	setPosAl(Position);
}

void EnemyShip::Disparar()
{
	Bala* nBullet = new Bala(Position, Vector2(30,30), 290.0f);
	Balas.push_back(nBullet);
}

void EnemyShip::EliminarBala(Bala* bala)
{
	Balas.erase(remove(Balas.begin(), Balas.end(), bala), Balas.end());
	delete bala;
}


void EnemyShip::setPoint()
{
	for (int point = 0; point < 16; ++point)
	{
		float valor = static_cast<float> (2.0f * PI * (point / 16.0f));
		float x = Radio * cosf(valor);
		float y = Radio * sinf(valor);
		Circulo.push_back(Vector2(x, y));
	}
}