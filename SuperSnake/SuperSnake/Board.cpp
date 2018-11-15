#include"Board.h"

Board::Board()
{
	for (int i = 0; i < boardSize * 2; i++)
	{
		board_XY.push_back(vector<int>(0));
		for (int j = 0; j < boardSize * 2; j++)
		{
			board_XY[i].push_back(0);
		}
	}

	board_XY.at(boardSize / 2).at(boardSize / 2) = 1;
	board_XY.at(boardSize / 2 - 1).at(boardSize / 2) = 1;

	foodPos = createFood();
	bombPos = createBomb();
	goodPos = createGoodFood();
}

strucPos Board::createFood()
{
	int x = RandomGen(2, boardSize * 2 - 1);
	vector<int> temp;
	int i = 1;
	for (auto it = board_XY.at(x).begin() + 1; it != board_XY.at(x).end() - 2; it++)
	{
		i++;
		if (*it == 0)
			temp.push_back(i - 1);
	}
	int y = RandomGen(0, temp.size() - 1);
	y = temp.at(y);
	strucPos pos(x - boardSize, y - boardSize + 1);

	return pos;
}


strucPos Board::createGoodFood() {
	int x = RandomGen(6, boardSize * 2 - 1);
	vector<int> temp;
	int i = 1;
	for (auto it = board_XY.at(x).begin() + 1; it != board_XY.at(x).end() - 2; it++)
	{
		i++;
		if (*it == 0)
			temp.push_back(i - 1);
	}
	int y = RandomGen(7, temp.size() - 1);
	y = temp.at(y);
	strucPos pos(x - boardSize, y - boardSize + 1);

	return pos;
}



strucPos Board::createBomb() {
	int x = RandomGen(4, boardSize * 2 - 1);
	vector<int> temp;
	int i = 1;
	for (auto it = board_XY.at(x).begin() + 1; it != board_XY.at(x).end() - 2; it++)
	{
		i++;
		if (*it == 0)
			temp.push_back(i - 1);
	}
	int y = RandomGen(2, temp.size() - 1);
	y = temp.at(y);
	strucPos pos(x - boardSize, y - boardSize + 1);

	return pos;
}


strucPos Board::createBombb() {
	int x = RandomGen(8, boardSize * 2 - 1);
	vector<int> temp;
	int i = 1;
	for (auto it = board_XY.at(x).begin() + 1; it != board_XY.at(x).end() - 2; it++)
	{
		i++;
		if (*it == 0)
			temp.push_back(i - 1);
	}
	int y = RandomGen(5, temp.size() - 1);
	y = temp.at(y);
	strucPos pos(x - boardSize, y - boardSize + 1);

	return pos;
}



int Board::RandomGen(unsigned low, unsigned high)
{
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<int> u(low, high);
	auto Gen = std::bind(u, e);
	return Gen();
}


