#include "Stdafx.h"
#include "MoleGame.h"

void MoleGame::setRect(RECT* rc, int startX, int startY)
{
	for (int i = 0; i < MOLE_ARR; ++i)
	{
		rc[i].left = startX + (150 * (i % 3));
		rc[i].top = startY + (150 * (i / 3));
		rc[i].right = (startX + 100) + (150 * (i % 3));
		rc[i].bottom = (startY + 100) + (150 * (i / 3));
	}
}

bool MoleGame::checkXY(RECT* rc, int mouseX, int mouseY)
{
	if (rc->left <= mouseX && rc->right >= mouseX 
		&& rc->top <= mouseY && rc->bottom >= mouseY)
	{
		_state = true;
	}
	else
	{
		_state = false;
	}

	return _state;
}

void MoleGame::printRect(HDC hdc, RECT* rc, int n)
{
	for (int i = 0; i < n; ++i)
	{
		DrawRectMake(hdc, rc[i]);
	}
}

void MoleGame::printEllipse(HDC hdc, RECT* rc, int n)
{
	for (int i = 0; i < n; ++i)
	{
		DrawEllipseMake(hdc, rc[i]);
	}
}

