#include "Stdafx.h"
#include "WormGame.h"

HRESULT WormGame::init(void)
{
	GameNode::init();
	_theta = 30;
	_xy.x = cosf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_xy.y = sinf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_Y;

	_rc = RectMakeCenter(_xy.x, _xy.y, 50, 50);

	_test = 5;
	return S_OK;
}

void WormGame::release(void)
{
	GameNode::release();
}

void WormGame::update(void)
{
	GameNode::update();
	_test += 5;
	
	// x > y 45도 이하
	// x < y 45도 이상
	
	_rc.left -= 5;
	_rc.right -= 5;
	_rc.top -= 2;
	_rc.bottom -= 2;



	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_theta += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_theta -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		
	}
}

void WormGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =====================================================================
	
	DrawEllipseMake(memDC, _rc);

	this->getDoubleBuffer()->render(hdc, 0, 0);

}
