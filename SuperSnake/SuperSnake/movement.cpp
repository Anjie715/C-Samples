#include"movement.h"

void Move::ChangeKey(unsigned char key, int x, int y)
{
	if (check == 0) {
		snk->dirCheck();
		if (key == 'w')
		{
			if (snk2->up != snk2->direction_limit)
				snk2->direction = snk2->up;
		}
		if (key == 'a')
		{
			if (snk2->left != snk2->direction_limit)
				snk2->direction = snk2->left;
		}
		if (key == 's')
		{
			if (snk2->down != snk2->direction_limit)
				snk2->direction = snk2->down;
		}
		if (key == 'd')
		{
			if (snk2->right != snk2->direction_limit)
				snk2->direction = snk2->right;
		}
		if (key == '3')
		{
			timeUpdate = 200;
		}
		if (key == '2')
		{
			timeUpdate = 300;
		}
		if (key == '1')
		{
			timeUpdate = 500;
		}
	}
	else if (check == 1) {
		snk2->dirCheck2();

		if (key == 'i')
		{
			if (snk2->up != snk2->direction_limit)
				snk2->direction = snk2->up;
		}
		if (key == 'j')
		{
			if (snk2->left != snk2->direction_limit)
				snk2->direction = snk2->left;
		}
		if (key == 'k')
		{
			if (snk2->down != snk2->direction_limit)
				snk2->direction = snk2->down;
		}
		if (key == 'l')
		{
			if (snk2->right != snk2->direction_limit)
				snk2->direction = snk2->right;
		}
	}

}
