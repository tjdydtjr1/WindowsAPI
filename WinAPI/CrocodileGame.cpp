#include "Stdafx.h"
#include "CrocodileGame.h"

HRESULT CrocodileGame::init(void)
{
	GameNode::init();
	
	for (int i = 0; i < 8; ++i)
	{
		_tooth[i] = RectMake(200 + ((i % 4) * 100), 200 + ((i / 4) * 200), 50, 50);
	}
	_idx = rand() % 8;
	_isDie = false;

	return S_OK;
}

void CrocodileGame::release(void)
{
	GameNode::release();
}

void CrocodileGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_tooth[_idx], _ptMouse))
		{
			_isDie = true;
		}
	}
}

void CrocodileGame::render(HDC hdc)
{
	for (int i = 0; i < 8; ++i)
	{
		DrawRectMake(hdc, _tooth[i]);
	}
	
	if (_isDie)
	{

		TextOut(hdc, 300, 400, "게임 종료", strlen("게임 종료"));
	}

	
}
