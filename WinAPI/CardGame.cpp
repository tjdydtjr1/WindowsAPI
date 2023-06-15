#include "Stdafx.h"
#include "CardGame.h"

HRESULT CardGame::init(void)
{
	GameNode::init();
	CardGame::setRect(rc, 20, 100, 100);
	return S_OK;
}

void CardGame::release(void)
{
	GameNode::release();
}

void CardGame::update(void)
{
	GameNode::update();
}
void CardGame::render(HDC hdc)
{
	CardGame::printRect(hdc, rc, 20);
}
void CardGame::setRect(RECT* rc, int n, int x, int y)
{
	for (int i = 0; i < n; ++i)
	{
		rc[i].left = x + (120 * (i % 5));
		rc[i].top = y + (120 * (i / 5));
		rc[i].right = (x + 100) + (120 * (i % 5));
		rc[i].bottom = (y + 100) + (120 * (i / 5));
	}
}

void CardGame::printRect(HDC hdc, RECT* rc, int n)
{
	for (int i = 0; i < n; ++i)
	{
		DrawRectMake(hdc, rc[i]);
	}
}