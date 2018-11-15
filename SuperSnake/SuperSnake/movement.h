#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_ 
#include"Snake.h"
using namespace std;
class Snake;
class Move
{
public:
	Snake * snk;
	Snake *snk2;
	int check;
	int timeUpdate = 500;
public:
	Move(Snake* snake, int type) { check = type; snk = snake; snk2 = snake; check = type; }
	void ChangeKey(unsigned char key, int x, int y);
};
#endif
