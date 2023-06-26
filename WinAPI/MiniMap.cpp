#include "Stdafx.h"
#include "MiniMap.h"

HRESULT MiniMap::init(void)
{
	GameNode::init();

	_bgImage = new GImage;
	_miniMap = new GImage;

	_bgImage->init("Resources/Images/BackGround/stage1.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	_miniMap->init("Resources/Images/BackGround/stage1.bmp", 300, 300, true, RGB(255, 0, 255));

	_rc = RectMake(WINSIZE_X - 300, WINSIZE_Y - 200, 50, 50);

	return S_OK;
}

void MiniMap::release(void)
{
	GameNode::release();
	SAFE_DELETE(_bgImage);
}

void MiniMap::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5;
		_rc.right += 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5;
		_rc.right -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 5;
		_rc.bottom -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 5;
		_rc.bottom += 5;
	}

}

void MiniMap::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	_bgImage->render(memDC, 0, 0);

	_miniMap->render(memDC, _rc.left, _rc.top);

	this->getDoubleBuffer()->render(hdc, 0, 0);

	
}
