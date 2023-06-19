#include "Stdafx.h"
#include "DumpAvoid.h"

HRESULT DumpAvoid::init(void)
{
	GameNode::init();
	
	_startBox = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 300, 300);
	_player[0] = RectMake(400, 700, 30, 30);
	_player[1] = RectMake(400, 730, 30, 30);

	for (int i = 0; i < OBJECT_MAX; ++i)
	{
		_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 50, 10, 10);
	}
	_isDie = false;
	_time = 0;
	
	return S_OK;
}

void DumpAvoid::release(void)
{
	GameNode::release();
}

void DumpAvoid::update(void)
{
	GameNode::update();
	
	// ������Ʈ ��ǥ
	for (int i = 0; i < OBJECT_MAX; ++i)
	{
		if (_object[i].bottom >= 750)
		{
			_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 50, 10, 10);
		}
		else if (_object[i].bottom < 750)
		{
			// �浹 �� ���� ����
			if (_player[0].left < _object[i].left &&
				_player[0].right > _object[i].right &&
				_player[0].top <= _object[i].top &&
				_player[0].bottom >= _object[i].bottom)
			{
				_isDie = true;
			}

			_object[i].top += 3;
			_object[i].bottom += 3;
		}
	}

	// ���� ����Ű �÷��̾� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player[0].left -= 3;
		_player[0].right -= 3;
		_player[1].left -= 3;
		_player[1].right -= 3;
		
		_arrow[0] = { _player[1].left, (_player[1].top + _player[1].bottom) / 2};
		_arrow[1] = { (_player[1].left + _player[1].right) / 2, _player[1].top};
		_arrow[2] = { (_player[1].left + _player[1].right) / 2, _player[1].bottom };
	}
	// ������ ����Ű �÷��̾� �̵�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player[0].left += 3;
		_player[0].right += 3;
		_player[1].left += 3;
		_player[1].right += 3;

		_arrow[0] = { _player[1].right, (_player[1].top + _player[1].bottom) / 2 };
		_arrow[1] = { (_player[1].left + _player[1].right) / 2, _player[1].top };
		_arrow[2] = { (_player[1].left + _player[1].right) / 2, _player[1].bottom };
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		HDC hdc;
		hdc = GetDC(_hWnd);
		TextOut(hdc, 400, 400, "���� �����", strlen("���� �����"));
		_player[0] = RectMake(400, 700, 30, 30);
		_player[1] = RectMake(400, 730, 30, 30);
		_isDie = false;

		for (int i = 0; i < OBJECT_MAX; ++i)
		{
			_object[i] = RectMake(10 + rand() % 700, 30 + rand() % 30, 10, 10);
		}

		_time = 0;

		ReleaseDC(_hWnd, hdc);
	}

}

void DumpAvoid::render(HDC hdc)
{
	char _timeText[128];

	// ���׾����� ����
	if(!_isDie)
	{
		// ���͸� ������ ����
		if (KEYMANAGER->isToggleKey(VK_RETURN))
		{
			_time++;
			wsprintf(_timeText, "��ƾ �ð� : %d  ��", _time / 60);
			TextOut(hdc, 670, 10, _timeText, strlen(_timeText));

			// �÷��̾�
			DrawEllipseMake(hdc, _player[0]);
			DrawRectMake(hdc, _player[1]);
			LineMove(hdc, _player[1].left, _player[1].top, _player[1].left - 10, _player[1].top + 10);
			LineMove(hdc, _player[1].left, _player[1].bottom, _player[1].left - 10, _player[1].bottom + 10);
			LineMove(hdc, _player[1].right, _player[1].top, _player[1].right + 10, _player[1].top + 10);
			LineMove(hdc, _player[1].right, _player[1].bottom, _player[1].right + 10, _player[1].bottom + 10);
			// ����
			Polygon(hdc, _arrow, 3);

			// ������ ������Ʈ
			for (int i = 0; i < OBJECT_MAX; ++i)
			{
				HBRUSH brush = CreateSolidBrush(RGB(150, 75, 0));
				DrawRectMake(hdc, _object[i]);
				FillRect(hdc, &_object[i], brush);
				DeleteObject(brush);
			}

		}
		// ���� ������ ���� ��� â
		else
		{
			// ����
			DrawRectMake(hdc, _startBox);
			TextOut(hdc, 350, 400, "Press Enter", strlen("Press Enter"));
		}
	}
	// ���� �׾����� ��� â
	else
	{
		TextOut(hdc, 300, 400, "���� ����", strlen("���� ����"));
		
		wsprintf(_timeText, "��ƾ �ð� : %d  ��", _time / 60);
		TextOut(hdc, 300, 420, _timeText, strlen(_timeText));
		TextOut(hdc, 300, 440, "�ٽ� ���� SPACE_BAR", strlen("�ٽ� ���� SPACE_BAR"));
		
		_isDie = true;
		
	}
}

