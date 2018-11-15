#include"draw.h"

void Draw::DrawString(void *font, const char s[], float x, float y)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	for (int i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}

void Draw::DrawGrid()
{
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);

	float row = boardSize * 10 + 10;
	float column = -boardSize * 10 - 10;
	for (int i = 0; i < boardSize * 2 + 1; i++)
	{
		row -= 10;
		column += 10;

		glVertex2f(column, -boardSize * 10);
		glVertex2f(column, boardSize * 10);
		glVertex2f(-boardSize * 10, row);
		glVertex2f(boardSize * 10, row);
	}
	glEnd();
}

void Draw::DrawSnake(vector<strucPos>  &  body)
{

	for (auto it = body.begin(); it != body.end(); it++)
	{
		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);

		glVertex2f(it->x * 10 - 10, it->y * 10);
		glVertex2f(it->x * 10, it->y * 10);
		glVertex2f(it->x * 10, it->y * 10 - 10);
		glVertex2f(it->x * 10 - 10, it->y * 10 - 10);
		glEnd();
	}
}


void Draw::DrawSnake2(vector<strucPos>  &  body2)
{

	for (auto it = body2.begin(); it != body2.end(); it++)
	{
		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex2f(it->x * 10 - 10, it->y * 10);
		glVertex2f(it->x * 10, it->y * 10);
		glVertex2f(it->x * 10, it->y * 10 - 10);
		glVertex2f(it->x * 10 - 10, it->y * 10 - 10);
		glEnd();
	}
}


void Draw::DrawFood(strucPos foodpos)
{


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10);
	glVertex2f(foodpos.x * 10, foodpos.y * 10);
	glVertex2f(foodpos.x * 10, foodpos.y * 10 - 10);
	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10 - 10);

	glEnd();
}


void Draw::DrawGoodFood(strucPos goodpos)
{


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);

	//glVertex2f(goodpos.x * 9.5, goodpos.y * 9.5);
	glVertex2f(goodpos.x * 10 - 10, goodpos.y * 10);
	glVertex2f(goodpos.x * 10, goodpos.y * 10);
	glVertex2f(goodpos.x * 10, goodpos.y * 10 - 10);
	glVertex2f(goodpos.x * 10 - 10, goodpos.y * 10 - 10);

	glEnd();
}


void Draw::DrawBomb(strucPos bombpos)
{


	//glBegin(GL_QUADS);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(bombpos.x * 10 - 5, bombpos.y * 10 - 5);
	glVertex2f(bombpos.x * 10 - 10, bombpos.y * 10);
	glVertex2f(bombpos.x * 10, bombpos.y * 10);
	glVertex2f(bombpos.x * 10, bombpos.y * 10 - 10);
	glVertex2f(bombpos.x * 10 + 5, bombpos.y * 10 + 5);

	glEnd();
}


void Draw::DrawBombb(strucPos bombbpos)
{


	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(bombbpos.x * 10 - 5, bombbpos.y * 10 - 5);
	glVertex2f(bombbpos.x * 10 - 10, bombbpos.y * 10);
	glVertex2f(bombbpos.x * 10, bombbpos.y * 10);
	glVertex2f(bombbpos.x * 10, bombbpos.y * 10 - 10);
	glVertex2f(bombbpos.x * 10 + 5, bombbpos.y * 10 + 5);


	glEnd();
}


void Draw::DrawSide()
{


	for (int i = 0; i < boardSize * 2; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(-boardSize * 10 + 10 * i, -boardSize * 10 + 10);
		glVertex2f(-boardSize * 10 + 10 + 10 * i, -boardSize * 10 + 10);
		glVertex2f(-boardSize * 10 + 10 + 10 * i, -boardSize * 10);
		glVertex2f(-boardSize * 10 + 10 * i, -boardSize * 10);
		glEnd();
	}
	for (int i = 0; i < boardSize * 2; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(-boardSize * 10 + 10 * i, boardSize * 10);
		glVertex2f(-boardSize * 10 + 10 + 10 * i, boardSize * 10);
		glVertex2f(-boardSize * 10 + 10 + 10 * i, boardSize * 10 - 10);
		glVertex2f(-boardSize * 10 + 10 * i, boardSize * 10 - 10);
		glEnd();
	}

	for (int i = 0; i < boardSize * 2; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(-boardSize * 10, -boardSize * 10 + 10 + 10 * i);
		glVertex2f(-boardSize * 10 + 10, -boardSize * 10 + 10 + 10 * i);
		glVertex2f(-boardSize * 10 + 10, -boardSize * 10 + 10 * i);
		glVertex2f(-boardSize * 10, -boardSize * 10 + 10 * i);
		glEnd();
	}

	for (int i = 0; i < boardSize * 2; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(boardSize * 10 - 10, -boardSize * 10 + 10 + 10 * i);
		glVertex2f(boardSize * 10, -boardSize * 10 + 10 + 10 * i);
		glVertex2f(boardSize * 10, -boardSize * 10 + 10 * i);
		glVertex2f(boardSize * 10 - 10, -boardSize * 10 + 10 * i);
		glEnd();
	}



}


void  Draw::changeSize(int w, int h)
{
	if (h == 0)
	{
		h = 1;
	}

	float ratio = 1 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	if (w <= h) {
		glOrtho(-boardSize * 10 * ratio, boardSize * 10 * ratio, -boardSize * 10 / ratio, boardSize * 10 / ratio, 1.0, -1.0);
	}
	else {
		glOrtho(-boardSize * 10 * ratio, boardSize * 10 * ratio, -boardSize * 10, boardSize * 10, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Draw::myDisplay(void) {

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}


void Draw::gameOver()
{
	DrawString(GLUT_BITMAP_HELVETICA_18, "Game Over", -30, 0);
}
