#include "Stdafx.h"
#include "MoleGame.h"


// 게임 기본틀 생성
void MoleGame::printBaseGame(HDC hdc)
{
	// 브러쉬 생성
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
	
	// 브러쉬 삭제
	DeleteObject(brush);
}

// 9개 위치의 사각형 좌표 셋팅
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
	// 상태값
	if (_state)
	{
		// true일 때 마우스 xy좌표값이 같은 경우
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

// 나올 공간.
void MoleGame::printEllipse(HDC hdc)
{
	// 브러쉬 생성
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	brush = (HBRUSH)::SelectObject(hdc, brush);

	for (int i = 0; i < MOLE_ARR; ++i)
	{
		DrawEllipseMake(hdc, _rc[i]);
	}

	// 브러쉬 삭제
	DeleteObject(brush);
}

// 상태값에 따른 출현
void MoleGame::printMole(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(150, 75, 0));
	brush = (HBRUSH)::SelectObject(hdc, brush);
	
	// 0 ~ 9
	int idx = rand() % 9;
	
	DrawEllipseMake(hdc, _rc[idx]);
	

	DeleteObject(brush);
}



