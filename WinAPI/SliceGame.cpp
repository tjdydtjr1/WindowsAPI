#include "Stdafx.h"
#include "SliceGame.h"

HRESULT SliceGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/Object/baseball.bmp", 600, 600, true, RGB(255, 0, 255));

	_idx = 0;
	_temp = 0;


	for (int i = 0; i < 9; ++i)
	{
		// 초기화
		_plImage[i].init("Resources/Images/Object/baseball.bmp", 600, 600, true, RGB(255, 0, 255));
	}

	for (int i = 0; i < 9; ++i)
	{
		_rc[i] = RectMake(900 + (201 * (i % 3)),201 * (i / 3), 200, 200);
	}

	// 그림 섞기 위한 인덱스
	for (int i = 0; i < 9; ++i)
	{
		_idx = rand() % 9;
		_temp = _idx;
		if (_check[_temp])
		{
			--i;
			continue;
		}
		_check[_temp] = i;
	}

	_countA = _countB = 0;
	_alphaA = _alphaB = 0;
	_alphaNum = 1;

	_isAlphaIncrese = false;

	return S_OK;
}

void SliceGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_bgImage);
	//SAFE_DELETE_ARRAY(_plImage);
	delete[] _plImage;
}

void SliceGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc[8].left += 5;
		_rc[8].right += 5;
		for (int i = 0; i < 8; ++i)
		{
			if (IntersectRect(&_switch, &_rc[8], &_rc[i]))
			{
				_switch = _rc[8];
				_rc[8] = _rc[i];
				_rc[i] = _switch;
				
				_rc[i].left -= 5;
				_rc[i].right -= 5;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc[8].left -= 5;
		_rc[8].right -= 5;
		for (int i = 0; i < 8; ++i)
		{
			if (IntersectRect(&_switch, &_rc[8], &_rc[i]))
			{
				_switch = _rc[8];
				_rc[8] = _rc[i];
				_rc[i] = _switch;

				_rc[i].left += 5;
				_rc[i].right += 5;

			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc[8].top -= 5;
		_rc[8].bottom -= 5;
		for (int i = 0; i < 8; ++i)
		{
			if (IntersectRect(&_switch, &_rc[8], &_rc[i]))
			{
				_switch = _rc[8];
				_rc[8] = _rc[i];
				_rc[i] = _switch;

				_rc[i].top += 5;
				_rc[i].bottom += 5;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc[8].top += 5;
		_rc[8].bottom += 5;
		for (int i = 0; i < 8; ++i)
		{
			if (IntersectRect(&_switch, &_rc[8], &_rc[i]))
			{
				_switch = _rc[8];
				_rc[8] = _rc[i];
				_rc[i] = _switch;

				_rc[i].top -= 5;
				_rc[i].bottom -= 5;
			}
		}
	}
	
}

void SliceGame::render(HDC hdc)
{

	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	//_bgImage->render(memDC, 0, 0);
	//_plImage->render(memDC, _rc.left, _rc.top);
	// =======================================================
	// 투명값
	//_bgImage->alphaRender(memDC, _alphaA);
	
	//_plImage->alphaRender(memDC, _rc.left, _rc.top, _alphaB);
	// =======================================================
	// 좌측 원본 이미지	
	_bgImage->render(memDC, 0, 0);

	
	// 짤린 이미지 및 해당하는 rect 출력
	for (int i = 0; i < 9; ++i)
	{
		//DrawRectMake(memDC, _rc[i]);
		_plImage[i].render(memDC, _rc[_check[i]].left, _rc[_check[i]].top,
			(200 * (i % 3)), 200 * (i / 3), 200, 200, 255);
	}
	
	// 클리핑 : 자르기
	//_bgImage->render(memDC, _rc.left, _rc.top, 500, 500, 300, 300, _alphaB);
	
	// =======================================================

	// =======================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);


}
