#ifndef _PARAMETER_H_
#define _PARAMETER_H_ 
static float boardSize = 20;
struct strucPos {
	int x;
	int y;
	strucPos() {}
	strucPos(int _x, int _y) :x(_x), y(_y) { }
};
class Parameter
{
public:
	void Get(unsigned char key, int x, int y);
};
#endif