#include "Stdafx.h"
#include "WormGame.h"

HRESULT WormGame::init(void)
{
	GameNode::init();
	_theta = 30;
	_xy.x = cosf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_xy.y = sinf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_Y;

	_rc = RectMakeCenter(_xy.x, _xy.y, 50, 50);

	_test = 30;
	return S_OK;
}

void WormGame::release(void)
{
	GameNode::release();
}

void WormGame::update(void)
{
	GameNode::update();
	
	// x > y 45도 이하
	// x < y 45도 이상
	
	_xy.x = cosf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_xy.y = sinf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_Y;

	if (_rc.left <= 0)
	{
		_test = -(_test);
	}
	else if (_rc.right >= WINSIZE_X)
	{
		_test = -(_test);
	}
	else if (_rc.top <= 0)
	{
		_xy.y = -(_xy.y);
	}
	else if (_rc.bottom >= WINSIZE_Y)
	{
		_xy.y = -(_xy.y);
	}
	
	_rc.left -= _test;
	_rc.right -= _test;
	_rc.top -= _xy.y / (_xy.x + _test);
	_rc.bottom -= _xy.y / (_xy.x + _test);


	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_theta += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_theta -= 10;
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
