#include "Draw.h"
#include <SDL2/SDL_opengl.h>

draw::draw()
{
	//PositionAst = Vector2(0, 0);
}

void draw::DrawT(unsigned int mode, vector<Vector2> Point)
{
	glBegin(mode);
	for (auto point : Point)
	{
		glVertex2f(point.GetX(), point.GetY());
	}
	glEnd();

}