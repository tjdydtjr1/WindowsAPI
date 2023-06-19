#include "Stdafx.h"
#include "Example_Mole.h"

#define CENTER_X    WINSIZE_X / 2
#define CENTER_Y    WINSIZE_Y / 2

HRESULT Example_Mole::init(void)
{
	GameNode::init();
	_currentRect = CURRENT_RECT_NULL;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			_rc[i * 4 + j] = RectMakeCenter(100 + j * 200, 200 + i * 200, 100, 100);
		}
	}
	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromIntTo(30, 60);

	_bIsSelected = false;
	_bIsOnceCheck = false;
    return S_OK;
}

void Example_Mole::release(void)
{
	GameNode::release();
}

void Example_Mole::update(void)
{
	GameNode::update();
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		/*if (_rc[0].right > _ptMouse.x &&
			_rc[0].left < _ptMouse.y &&
			_rc[0].left < _ptMouse.x && _bIsOnceCheck)
		{

		}*/
		// PtInRect() : 렉트 안의 POINT{ x, y} 가 있는지 검사하여 포인트가 사각형
		// 안에 있으면 true를 반환하는 API 함수
		// 사각형이랑 마우스가 충돌 했는지
		if (PtInRect(&_rc[_index], _ptMouse) && !_bIsOnceCheck)
		{
			_score += 100;
			_bIsOnceCheck = true;
		}
	}

	if (!_bIsSelected)
	{
		_count++;
		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_currentRect = (CURRENT_RECT)_index;
			_bIsSelected = true;
		}
	}
	else
	{
		_count++;
		if (_count % _time == 0)
		{
			_bIsOnceCheck = false;
			_bIsSelected = false;
			_currentRect = CURRENT_RECT_NULL;
			_time = RND->getFromIntTo(30, 60);

			_index = 180;
		}
	}
}

void Example_Mole::render(HDC hdc)
{
	char strScore[128];

	wsprintf(strScore, "SCORE : %d", _score);
	TextOut(hdc, 50, 100, strScore, strlen(strScore));

	for (int i = 0; i < 8; ++i)
	{
		Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}

	if (_bIsSelected)
	{
		int r = RND->getInt(256);
		int g = RND->getInt(256);
		int b = RND->getInt(256);


		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		FillRect(hdc, &_rc[_index], brush);

		// 안지우면 메모리 누수
		DeleteObject(brush);
	}

}
