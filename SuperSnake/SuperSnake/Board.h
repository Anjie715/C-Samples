#ifndef _Board_H_
#define _Board_H_ 

#include"Parameter.h"
#include<vector>
#include <functional> 
#include<random>
#include<time.h>

#include<iostream>
#include<fstream>
using namespace std;
extern struct strucPos;
class Board
{

public:
	vector<vector<int>> board_XY;
	vector<vector<int>> board_XY_;
	strucPos foodPos;
	strucPos bombPos;
	strucPos goodPos;
	strucPos bombbPos;

public:
	Board();
	strucPos createFood();
	strucPos createBomb();
	strucPos createBombb();
	strucPos createGoodFood();
	int RandomGen(unsigned low, unsigned high);

};
#endif