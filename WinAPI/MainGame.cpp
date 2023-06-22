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
	* 그림 좌표
	950, 50 1041, 139

	1150, 0 1278, 145

	1192, 254 1275, 336

	1132, 563 1241 618

	1053, 676 1161 776
	*/
	_findPicture[0] = RectMakeCenter(950, 50, 50, 50);
	_findPicture[1] = RectMakeCenter(1150, 0, 50, 50);
	_findPicture[2] = RectMakeCenter(1192, 254, 50, 50);
	_findPicture[3] = RectMakeCenter(1132, 563, 50, 50);
	_findPicture[4] = RectMakeCenter(1053, 676, 50, 50);

	_time = 600;

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

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
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
	}

	
}

void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================
	RECT temp;
	char text[128];
	
	_bgImage->render(memDC, 0, 0);
	wsprintf(text, "마우스 X : %d , 마우스 Y : %d", _ptMouse.x, _ptMouse.y);
	TextOut(memDC, 10, 10, text, strlen(text));

	
	wsprintf(text, "TIME : %d", (--_time) / 10 );
	TextOut(memDC, 600, 10, text, strlen(text));
	
	

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		DrawRectMake(memDC, _rc);
	}

	if (KEYMANAGER->isToggleKey(VK_LBUTTON) && IntersectRect(&temp, &_rc, &_findPicture[0]))
	{
		DrawEllipseMake(memDC, _findPicture[0]);
	}
	else if(!KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && IntersectRect(&temp, &_rc, &_findPicture[0]))
	{
		_time += 100;
	}
	if (IntersectRect(&temp, &_rc, &_findPicture[1]))
	{
		DrawEllipseMake(memDC, _findPicture[1]);
	}
	if (IntersectRect(&temp, &_rc, &_findPicture[2]))
	{
		DrawEllipseMake(memDC, _findPicture[2]);
	}
	if (IntersectRect(&temp, &_rc, &_findPicture[3]))
	{
		DrawEllipseMake(memDC, _findPicture[3]);
	}
	if (IntersectRect(&temp, &_rc, &_findPicture[4]))
	{
		DrawEllipseMake(memDC, _findPicture[4]);
	}
	//_plgImage->render(memDC, _ptMouse.x, _ptMouse.y);

	// =======================================================

	this->getDoubleBuffer()->render(hdc, 0, 0);


}
