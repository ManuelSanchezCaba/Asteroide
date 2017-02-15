#include "ship.h"
#include <SDL2/SDL_opengl.h>


ship::ship()
{}

ship::ship(const vector<Vector2> points)
{
	Point = points;
}

void ship::Draw()
{
	glBegin(GL_LINE_LOOP);
		for (auto point : Point)
		{
			glVertex2f(point.GetX(), point.GetY());
		}
	glEnd();
}

void ship::Move(int x, int y)
{
	HANDLE hCon; //Puntero que me ayuda a controlar el sistema
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos; //Definir Coordenadas
	dwPos.X = x;
	dwPos.Y = y;
	CONSOLE_CURSOR_INFO cc; //Esto hace que pueda modificar el cursor
	cc.bVisible = FALSE; //Hago que desaparezca el cursor

	SetConsoleCursorPosition(hCon, dwPos); //Hacer que lo que cambie
	SetConsoleCursorInfo(hCon, &cc);	   //se ejecute en consola
}

void ship::MoveUp()
{
	/*
	int x = 0, y = 1;
	if (kbhit())
	{
		char tecla = getch();
		if (tecla == 'w' || tecla == 'W') y--;
		//if (tecla == 's' || tecla == 'S') y++;
		//if (tecla == 'a' || tecla == 'A') x--;
		//if (tecla == 'd' || tecla == 'D') x++;

		//cout << "Se esta presionando la tecla " << tecla << endl;
	}*/

}

void ship::MoveDown()
{

}