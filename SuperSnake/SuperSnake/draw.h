#ifndef _DRAW_H_
#define _DRAW_H_ 
#include <GLUT/glut.h>
#include"Parameter.h"
#include<vector>

using namespace std;
extern struct strucPos;

class Draw
{

public:
	void DrawString(void *font, const char s[], float x, float y);
	void DrawScore(void *font, int s, float x, float y);
	void DrawGrid();
	void DrawSnake(vector<strucPos> &  body);
	void DrawSnake2(vector<strucPos> &  body2);
	void DrawFood(strucPos foodpos);
	void DrawGoodFood(strucPos goodpos);
	void DrawBomb(strucPos bombpos);
	void DrawBombb(strucPos bombbpos);

	void DrawSide();
	void gameOver();
	//void score();
	void changeSize(int w, int h);
	void myDisplay(void);
};

#endif

