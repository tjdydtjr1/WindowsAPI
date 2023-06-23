#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plgImage = new GImage;
	_plgImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));
	_rc = RectMakeCenter(400, 400, 173, 291);

	_radian = 3.1415926535f;
	_degree = 180.0f;

	for (int i = 0; i < 5; ++i)
	{
		_star[i].x = cosf((i * 72 - 90 ) * PI / 180.0f) * 200 + WINSIZE_X / 2;
		_star[i].y = sinf((i * 72 - 90 ) * PI / 180.0f) * 200 + WINSIZE_Y / 2;
		
		/*
		오망성을 그리기 위한 포인트 5개
		ㄴ 72 = 360 / 5
		
		90 -> 초기 각도

		디그리를 -> 라디안으로

		200 -> 중심에서의 거리
		WINSIZE_X / Y -> 중점
		*/
	}

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

	GetLocalTime(&_st);
	_st.wSecond;
}

void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	/*_bgImage->render(memDC, 0, 0);
	_plgImage->render(memDC, _rc.left, _rc.top);*/
	// =======================================================


	char strRadian[128];
	char strDegree[128];
	char strSecond[128];

	sprintf_s(strSecond, "%d 초", _st.wSecond);
	TextOut(memDC, WINSIZE_X / 2, 100, strSecond, strlen(strSecond));

	// 라디안에서 디그리로
	// ㄴ 1 Radian = 180 / PI Degree
	sprintf_s(strRadian, "%.2f 라디안 값은 %.2f 디그리 값과 같다."
		, _radian, _radian * (180.0f / M_PI));
	TextOut(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2 - 100, strRadian, strlen(strRadian));

	// 디그리에서 라디안으로
	// ㄴ 1 Degree = PI / 180 Radian
	sprintf_s(strDegree, "%.2f 디그리 값은 %.2f 라디안 값과 같다."
		, _degree, _degree * (PI / 180.0f));
	TextOut(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2, strDegree, strlen(strDegree));

	// CreatePen(펜 스타일, 길이, 색상);
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN currentPen;
	
	currentPen = (HPEN)::SelectObject(memDC, pen);


	LineMake(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2 + 100, WINSIZE_X / 2 + 200, WINSIZE_Y / 2 + 100);

	DeleteObject(pen);


	// =======================================================
	/*
	

	*/


	SetPixel(memDC, _star[0].x, _star[0].y, RGB(255, 0, 0));

	for (int i = 0; i < 5; ++i)
	{
		EllipseMake(memDC, _star[i].x, _star[i].y, 10, 10);
	}

	this->getDoubleBuffer()->render(hdc, 0, 0);


}
