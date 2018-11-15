#include"Parameter.h"
#include"Snake.h"

Snake::Snake()
{
	body.push_back(strucPos(-10, -10));
	body.push_back(strucPos(-10, -11));
	body2.push_back(strucPos(10, -10));
	body2.push_back(strucPos(10, -11));
	crashed = false;
}

void Snake::move(vector<vector<int>> & board_XY, Board  * const board)
{
	auto it = body.begin();
	if (direction == up)
	{
		body.insert(body.begin(), *it);
		body.at(0).y += 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == down)
	{
		body.insert(body.begin(), *it);
		body.at(0).y -= 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == right)
	{
		body.insert(body.begin(), *it);
		body.at(0).x += 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == left)
	{
		body.insert(body.begin(), *it);
		body.at(0).x -= 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if ((board->foodPos.x != body.at(0).x || board->foodPos.y != body.at(0).y) && (board->bombPos.x != body.at(0).x || board->bombPos.y != body.at(0).y) && (board->goodPos.x != body.at(0).x || board->goodPos.y != body.at(0).y))
	{
		board_XY[(body.end() - 1)->x + boardSize - 1][(body.end() - 1)->y + boardSize - 1] = 0;
		body.erase(body.end() - 1);
	}
	else if ((board->foodPos.x == body.at(0).x || board->foodPos.y == body.at(0).y) && (board->bombPos.x != body.at(0).x || board->bombPos.y != body.at(0).y))
	{
		board->foodPos = board->createFood();
		board->bombPos = board->createBomb();
		score++;
	}
	else if ((board->goodPos.x == body.at(0).x || board->goodPos.y == body.at(0).y) && (board->bombPos.x != body.at(0).x || board->bombPos.y != body.at(0).y))
	{
		board->goodPos = board->createGoodFood();
		board->bombPos = board->createBomb();

		score = score + 5;
	}
	else if ((board->bombPos.x == body.at(0).x || board->bombPos.y == body.at(0).y) && (board->foodPos.x != body.at(0).x || board->foodPos.y != body.at(0).y))
	{
		body.erase(body.end() - 1);
		body.erase(body.end() - 1);
		board->bombPos = board->createBomb();
		score--;
	}
	else if ((board->bombbPos.x == body.at(0).x || board->bombbPos.y == body.at(0).y) && (board->foodPos.x != body.at(0).x || board->foodPos.y != body.at(0).y))
	{
		body.erase(body.end() - 1);
		body.erase(body.end() - 1);
		board->bombbPos = board->createBombb();
		score--;
	}

	if (checkCrash())
		crashed = true;


}

void Snake::move2(vector<vector<int>> & board_XY, Board  * const board)
{
	auto it = body2.begin();
	if (direction == up)
	{
		body2.insert(body2.begin(), *it);
		body2.at(0).y += 1;

		board_XY[body2.at(0).x + boardSize - 1][body2.at(0).y + boardSize - 1] = 1;
	}
	if (direction == right)
	{
		body2.insert(body2.begin(), *it);
		body2.at(0).x += 1;

		board_XY[body2.at(0).x + boardSize - 1][body2.at(0).y + boardSize - 1] = 1;
	}
	if (direction == down)
	{
		body2.insert(body2.begin(), *it);
		body2.at(0).y -= 1;

		board_XY[body2.at(0).x + boardSize - 1][body2.at(0).y + boardSize - 1] = 1;
	}
	if (direction == left)
	{
		body2.insert(body2.begin(), *it);
		body2.at(0).x -= 1;

		board_XY[body2.at(0).x + boardSize - 1][body2.at(0).y + boardSize - 1] = 1;
	}

	if ((board->foodPos.x != body2.at(0).x || board->foodPos.y != body2.at(0).y) && (board->bombPos.x != body2.at(0).x || board->bombPos.y != body2.at(0).y) && (board->goodPos.x != body2.at(0).x || board->goodPos.y != body2.at(0).y))
	{
		board_XY[(body2.end() - 1)->x + boardSize - 1][(body2.end() - 1)->y + boardSize - 1] = 0;
		body2.erase(body2.end() - 1);
	}
	else if ((board->foodPos.x == body2.at(0).x || board->foodPos.y == body2.at(0).y) && (board->bombPos.x != body2.at(0).x || board->bombPos.y != body2.at(0).y))
	{
		board->foodPos = board->createFood();
		board->bombPos = board->createBomb();
		score2++;

	}
	else if ((board->goodPos.x == body2.at(0).x || board->goodPos.y == body2.at(0).y) && (board->bombPos.x != body2.at(0).x || board->bombPos.y != body2.at(0).y))
	{
		board->goodPos = board->createGoodFood();
		board->bombPos = board->createBomb();
		score2 = score2 + 5;
	}
	else if ((board->bombPos.x == body2.at(0).x || board->bombPos.y == body2.at(0).y) && (board->foodPos.x != body2.at(0).x || board->foodPos.y != body2.at(0).y))
	{
		body2.erase(body2.end() - 1);
		body2.erase(body2.end() - 1);
		board->bombPos = board->createBomb();
		score2--;
	}
	else if ((board->bombbPos.x == body2.at(0).x || board->bombbPos.y == body2.at(0).y) && (board->foodPos.x != body2.at(0).x || board->foodPos.y != body2.at(0).y))
	{
		body2.erase(body2.end() - 1);
		body2.erase(body2.end() - 1);
		board->bombbPos = board->createBombb();
		score2--;
	}

	if (checkCrash2())
		crashed = true;


}


void Snake::dirCheck()
{
	int x = body.at(1).x - body.at(0).x;
	int y = body.at(1).y - body.at(0).y;

	if (x == 1) direction_limit = right;
	if (x == -1) direction_limit = left;
	if (y == 1) direction_limit = up;
	if (y == -1) direction_limit = down;
}


bool Snake::checkCrash()
{
	auto snakehead = body.begin();

	for (auto it = body.begin() + 1; it != body.end(); it++)
	{
		if (snakehead->x == it->x&&snakehead->y == it->y)
			return true;
	}

	if (body.at(0).x == boardSize || body.at(0).x == -boardSize + 1 || body.at(0).y == boardSize || body.at(0).y == -boardSize + 1)
	{
		return true;
	}

	if (body.size() == 1)
	{
		return true;
	}

	return false;
}


void Snake::dirCheck2()
{
	int x = body2.at(1).x - body2.at(0).x;
	int y = body2.at(1).y - body2.at(0).y;

	if (x == 1) direction_limit = right;
	if (x == -1) direction_limit = left;
	if (y == 1) direction_limit = up;
	if (y == -1) direction_limit = down;
}


bool Snake::checkCrash2()
{

	auto head = body2.begin();
	auto head2 = body.begin();
	for (auto it = body2.begin() + 1; it != body2.end(); it++)
	{
		if (head->x == it->x&&head->y == it->y)
			return true;
	}



	if (body2.at(0).x == boardSize || body2.at(0).x == -boardSize + 1 || body2.at(0).y == boardSize || body2.at(0).y == -boardSize + 1)
	{
		return true;
	}

	if (body2.size() == 1)
	{
		return true;
	}

	return false;
}

int Snake::getScore() {
	return score;
}

int Snake::getScore2() {
	return score2;
}





