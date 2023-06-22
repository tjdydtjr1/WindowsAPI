#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/test.bmp", WINSIZE_X, WINSIZE_Y);

	//_plgImage = new GImage;
	//_plgImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));
	/*
	950, 50 1041, 139

	1150, 0 1278, 145

	1192, 254 1275, 336

	1132, 563 1241 618

	1053, 676 1161 776
	*/

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_bgImage);
	//SAFE_DELETE(_plgImage);


}

void MainGame::update(void)
{
	GameNode::update();

	_rc = RectMakeCenter(_ptMouse.x, _ptMouse.y, 80, 80);

	if (!KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료 확인", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}

	/*if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5.0f;
		_rc.right += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5.0f;
		_rc.right -= 5.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 5.0f;
		_rc.bottom -= 5.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 5.0f;
		_rc.bottom += 5.0f;
	}*/

	
}

void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================
	char text[128];
	
	_bgImage->render(memDC, 0, 0);
	wsprintf(text, "마우스 X : %d , 마우스 Y : %d", _ptMouse.x, _ptMouse.y);
	TextOut(memDC, 10, 10, text, strlen(text));
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		DrawRectMake(memDC, _rc);
	}
	//_plgImage->render(memDC, _ptMouse.x, _ptMouse.y);

	// =======================================================

	this->getDoubleBuffer()->render(hdc, 0, 0);


}
