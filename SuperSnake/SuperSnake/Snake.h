#ifndef _Snake_H_
#define _Snake_H_ 
#include"Board.h"

using namespace std;
extern struct strucPos;
class Snake
{

public:
	vector<strucPos> body;
	vector<strucPos> body2;
	enum { up, right, down, left };
	int direction = up;
	int direction_limit = down;
	bool crashed = false;
	int score = 0;
	int score2 = 0;
public:
	Snake();
	void move(vector<vector<int>> & board_XY, Board  * const board);
	void move2(vector<vector<int>> & board_XY, Board  * const board);
	void dirCheck();
	void dirCheck2();
	bool checkCrash();
	bool checkCrash2();
	int getScore();
	int getScore2();
	friend class Draw;
};
#endif