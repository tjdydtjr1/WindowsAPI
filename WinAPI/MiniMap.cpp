#include "Stdafx.h"
#include "MiniMap.h"

HRESULT MiniMap::init(void)
{
	GameNode::init();

	_bgImage = new GImage;
	_miniMap = new GImage;
	
	_testImage = new GImage;

	_charImage = new GImage;

	_bgImage->init("Resources/Images/BackGround/stage1.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	_miniMap->init("Resources/Images/BackGround/stage1.bmp", WINSIZE_X / 4, WINSIZE_Y / 4 + 50, true, RGB(255, 0, 255));
	
	_testImage->init("Resources/Images/BackGround/stage1.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, true, RGB(255, 0, 255));

	_charImage->init("Resources/Images/Object/Char.bmp", 40, 40, true, RGB(255, 0, 255));
	
	//_testImage->init(, WINSIZE_X / 2, WINSIZE_Y / 2, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y - 50, 40, 40);
	_miniRc = RectMake((WINSIZE_X - 210), (WINSIZE_Y - 25), 15, 15);

	_testRc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2 + 150, 50, 50);

	return S_OK;
}

void MiniMap::release(void)
{
	GameNode::release();
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_miniMap);
}

void MiniMap::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += MOVE_SPEED;
		_rc.right += MOVE_SPEED;

		_miniRc.left += MOVE_SPEED / 4.0f;
		_miniRc.right += MOVE_SPEED / 4.0f;

		_testRc.left += 2;
		_testRc.right += 2;

	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= MOVE_SPEED;
		_rc.right -= MOVE_SPEED;

		_miniRc.left -= MOVE_SPEED / 4.0f;
		_miniRc.right -= MOVE_SPEED / 4.0f;

		_testRc.left -= 2;
		_testRc.right -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= MOVE_SPEED;
		_rc.bottom -= MOVE_SPEED;

		_miniRc.top -= MOVE_SPEED / 4.0f;
		_miniRc.bottom -= MOVE_SPEED / 4.0f;

		_testRc.top -= 2;
		_testRc.bottom -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += MOVE_SPEED;
		_rc.bottom += MOVE_SPEED;

		_miniRc.top += MOVE_SPEED / 4.0f;
		_miniRc.bottom += MOVE_SPEED / 4.0f;

		_testRc.top += 2;
		_testRc.bottom += 2;
	}

}

void MiniMap::render(HDC hdc)
{
	HDC memDC = this->getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	// ��ü �̹���
	_bgImage->render(memDC, 0, 0);

	_charImage->render(memDC, _rc.left, _rc.top);
	//_miniMap->render(memDC, _miniRc.left - 550, _miniRc.top - 500, WINSIZE_X, WINSIZE_Y, 0, 0, 0);

	// �̴ϸ� ��ġ
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_testImage->render(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
		_charImage->render(memDC, _testRc.left, _testRc.top);
	}
	else
	{
		_miniMap->render(memDC, (WINSIZE_X - 350), WINSIZE_Y - 220);
		_charImage->render(memDC, _miniRc.left, _miniRc.top);
	}


	this->getBackBuffer()->render(hdc, 0, 0);

	
}
