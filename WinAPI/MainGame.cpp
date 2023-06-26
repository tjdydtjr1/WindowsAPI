#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));


	_rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 173, 291);

	_countA = _countB = 0;
	_alphaA = _alphaB = 0;
	_alphaNum = 1;

	_isAlphaIncrese = false;


	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
}

void MainGame::update(void)
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

	_countA++;
	if (_countA % 3 == 0)
	{
		_alphaA++;

		if (_alphaA >= 255)
		{
			_alphaA = 0;
		}
	}

	_countB++;
	if (_countB % 6 == 0)
	{
		_alphaB += 5;
		if (_alphaB >= 255)
		{
			_alphaB = 0;
		}
	}
}

void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================
	//_bgImage->render(memDC, 0, 0);
	//_plImage->render(memDC, _rc.left, _rc.top);
	// =======================================================
	_bgImage->alphaRender(memDC, _alphaA);

	_plImage->alphaRender(memDC, _rc.left, _rc.top, _alphaB);
	
	_bgImage->render(memDC, _rc.left, _rc.top, 500, 500, 300, 300, _alphaB);
	
	// =======================================================

	// =======================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);


}

