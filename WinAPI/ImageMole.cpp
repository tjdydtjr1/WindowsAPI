#include "Stdafx.h"
#include "ImageMole.h"



HRESULT ImageMole::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/mole.bmp", WINSIZE_X, WINSIZE_Y);

	_moleImage = new GImage;
	_moleImage->init("Resources/Images/Object/mole.bmp", 100, 100);
	setRect(100, 100);

	return S_OK;
}

void ImageMole::release(void)
{
	GameNode::release();
}

void ImageMole::update(void)
{
	GameNode::update();
}

void ImageMole::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getBackBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	_bgImage->render(memDC, 0, 0);
	printBaseGame(memDC);
	printRect(memDC);
	printEllipse(memDC);
	printMole(memDC);

	_moleImage->render(memDC, _rc[_idx].left, _rc[_idx].top);

	this->getBackBuffer()->render(hdc, 0, 0);
}


void ImageMole::printBaseGame(HDC hdc)
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

void ImageMole::setRect(int startX, int startY)
{
	for (int i = 0; i < MOLE_ARR; ++i)
	{
		_rc[i].left = startX + (150 * (i % 3));
		_rc[i].top = startY + (150 * (i / 3));
		_rc[i].right = (startX + 100) + (150 * (i % 3));
		_rc[i].bottom = (startY + 100) + (150 * (i / 3));
	}
}

bool ImageMole::checkXY(long mouseX, long mouseY)
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
				_score += 1000;
			}
			else
			{
				_state = true;
			}
		}
	}
	return _state;
}

void ImageMole::printRect(HDC hdc)
{
	for (int i = 0; i < MOLE_ARR; ++i)
	{
		DrawRectMake(hdc, _rc[i]);
	}
}

void ImageMole::printEllipse(HDC hdc)
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

void ImageMole::printMole(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(150, 75, 0));
	brush = (HBRUSH)::SelectObject(hdc, brush);

	// 0 ~ 9
	_idx = rand() % 9;

	DrawEllipseMake(hdc, _rc[_idx]);


	DeleteObject(brush);
}