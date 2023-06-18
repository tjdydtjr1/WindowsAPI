#include "Stdafx.h"
#include "MoleGame.h"


// ���� �⺻Ʋ ����
void MoleGame::printBaseGame(HDC hdc)
{
	// �귯�� ����
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	brush = (HBRUSH)::SelectObject(hdc, brush);

	for (int i = 0; i < MOLE_ARR; ++i)
	{
		_rc[i].left = 100 + (150 * (i % 3));
		_rc[i].top = 100 + (150 * (i / 3));
		_rc[i].right = (100 + 100) + (150 * (i % 3));
		_rc[i].bottom = (100 + 100) + (150 * (i / 3));
		DrawRectMake(hdc, _rc[i]);
	}
	
	// �귯�� ����
	DeleteObject(brush);
}

// 9�� ��ġ�� �簢�� ��ǥ ����
void MoleGame::setRect(int startX, int startY)
{
	for (int i = 0; i < MOLE_ARR; ++i)
	{
		_rc[i].left = startX + (150 * (i % 3));
		_rc[i].top = startY + (150 * (i / 3));
		_rc[i].right = (startX + 100) + (150 * (i % 3));
		_rc[i].bottom = (startY + 100) + (150 * (i / 3));
	}
}

bool MoleGame::checkXY(int mouseX, int mouseY)
{
	// ���°�
	if (_state)
	{
		// true�� �� ���콺 xy��ǥ���� ���� ���
		for (int i = 0; i < MOLE_ARR; ++i)
		{
			if (_rc[i].left <= mouseX && _rc[i].right >= mouseX
				&& _rc[i].top <= mouseY && _rc[i].bottom >= mouseY)
			{
				_state = false;
			}
			else
			{
				_state = true;
			}
		}
	}
	return _state;
}

void MoleGame::printRect(HDC hdc)
{
	for (int i = 0; i < MOLE_ARR; ++i)
	{
		DrawRectMake(hdc, _rc[i]);
	}
}

// ���� ����.
void MoleGame::printEllipse(HDC hdc)
{
	// �귯�� ����
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	brush = (HBRUSH)::SelectObject(hdc, brush);

	for (int i = 0; i < MOLE_ARR; ++i)
	{
		DrawEllipseMake(hdc, _rc[i]);
	}

	// �귯�� ����
	DeleteObject(brush);
}

// ���°��� ���� ����
void MoleGame::printMole(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(150, 75, 0));
	brush = (HBRUSH)::SelectObject(hdc, brush);
	
	// 0 ~ 9
	int idx = rand() % 9;
	
	DrawEllipseMake(hdc, _rc[idx]);
	

	DeleteObject(brush);
}



