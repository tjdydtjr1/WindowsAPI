#include "Stdafx.h"
#include "CreditGame.h"

HRESULT CreditGame::init(void)
{
	GameNode::init();
	
	_startBox = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 300, 300);
	_player[0] = RectMake(400, 700, 30, 30);
	_player[1] = RectMake(400, 730, 30, 30);

	for (int i = 0; i < OBJECT_MAX; ++i)
	{
		_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 50, 10, 10);
		_die[i] = false;
	}

	_time = 0;
	_collision = false;
	start = 0;
	return S_OK;
}

void CreditGame::release(void)
{
	GameNode::release();
}

void CreditGame::update(void)
{
	GameNode::update();
	
	for (int i = 0; i < OBJECT_MAX; ++i)
	{
		if (_object[i].bottom >= 750)
		{
			_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 50, 10, 10);
		}
		if (!_die[i] && _object[i].bottom < 750)
		{
			_object[i].top += 3;
			_object[i].bottom += 3;
		}
	}

	// 왼쪽 방향키 플레이어 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		HDC hdc;
		hdc = GetDC(_hWnd);
		_player[0].left -= 3;
		_player[0].right -= 3;
		_player[1].left -= 3;
		_player[1].right -= 3;
		//LineMove(hdc, _player[1].left, _player[1].top, _player[1].bottom,500);

		ReleaseDC(_hWnd, hdc);
	}
	// 오른쪽 방향키 플레이어 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player[0].left += 3;
		_player[0].right += 3;
		_player[1].left += 3;
		_player[1].right += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		HDC hdc;
		hdc = GetDC(_hWnd);
		TextOut(hdc, 400, 400, "게임 재시작", strlen("게임 재시작"));
		Sleep(100);
		_player[0] = RectMake(400, 700, 30, 30);
		_player[1] = RectMake(400, 730, 30, 30);


		for (int i = 0; i < OBJECT_MAX; ++i)
		{
			_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 30, 10, 10);
			_die[i] = false;
		}

		_time = 0;
		_collision = false;

		ReleaseDC(_hWnd, hdc);

	}

}

void CreditGame::render(HDC hdc)
{
	char _timeText[128];
	if (KEYMANAGER->isToggleKey(VK_SPACE))
		/*&& _ptMouse.x > _startBox.left
		&& _ptMouse.x < _startBox.right
		&& _ptMouse.y > _startBox.top
		&& _ptMouse.y < _startBox.bottom)*/
	{
		_time++;
		wsprintf(_timeText, "버틴 시간 : %d  초", _time / 60);
		TextOut(hdc, 670, 10, _timeText, strlen(_timeText));

		DrawEllipseMake(hdc, _player[0]);
		DrawRectMake(hdc, _player[1]);

		for (int i = 0; i < OBJECT_MAX; ++i)
		{
			DrawRectMake(hdc, _object[i]);
		}
	}
	else
	{
		TextOut(hdc, 350, 400, "게임 시작", strlen("게임 시작"));
	}
}

