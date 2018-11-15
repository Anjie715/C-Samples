#include <GLUT/glut.h>
#include <vector>
#include"draw.h"
#include"Board.h"
#include"movement.h"
#include <iostream>

static Draw* draw = 0;
static Board* board = 0;
static Parameter* set = 0;
static Move* key_event = 0;
static Move* key_event2 = 0;
static Snake* snake = 0;
static Snake* snake2 = 0;



void timerProc(int id)
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	if (!snake->crashed && !snake2->crashed)
	{

		snake->move(board->board_XY, board);
		draw->DrawSnake(snake->body);
		snake2->move2(board->board_XY, board);
		draw->DrawSnake2(snake2->body2);
		draw->DrawFood(board->foodPos);
		if (key_event->timeUpdate > 300) {
			draw->DrawGoodFood(board->goodPos);
		}
		else if (key_event->timeUpdate < 300) {
			draw->DrawBombb(board->bombbPos);
		}
		draw->DrawBomb(board->bombPos);
		draw->DrawGrid();
		draw->DrawSide();
	}
	else if (snake->crashed || snake2->crashed)
	{
		draw->DrawGrid();
		draw->DrawSide();
		draw->gameOver();
	}

	glutSwapBuffers();
	glutTimerFunc(key_event->timeUpdate, timerProc, 1);
}

void changeSize(int x, int y)
{
	draw->changeSize(x, y);
}
void myDisplay()
{
	draw->myDisplay();
}
void ChangeKey(unsigned char key, int x, int y)
{
	key_event->ChangeKey(key, x, y);
	key_event2->ChangeKey(key, x, y);
}

int main(int argc, char ** argv) {

	draw = new Draw;
	board = new Board;
	snake = new Snake;
	snake2 = new Snake;
	key_event = new Move(snake, 0);
	key_event2 = new Move(snake2, 1);
	set = new Parameter;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Super Snake");
	glShadeModel(GL_SMOOTH);

	glutReshapeFunc(changeSize);
	glutDisplayFunc(myDisplay);
	glutTimerFunc(key_event->timeUpdate, timerProc, 1);
	glutKeyboardFunc(ChangeKey);

	int score = snake->getScore();
	std::cout << score << std::endl;

	glutMainLoop();


	delete draw;
	delete set;
	delete board;
	delete snake;
	delete snake2;
	delete key_event;
	return(0);
}

