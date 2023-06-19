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
		// PtInRect() : ��Ʈ ���� POINT{ x, y} �� �ִ��� �˻��Ͽ� ����Ʈ�� �簢��
		// �ȿ� ������ true�� ��ȯ�ϴ� API �Լ�
		// �簢���̶� ���콺�� �浹 �ߴ���
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

		// ������� �޸� ����
		DeleteObject(brush);
	}

}
