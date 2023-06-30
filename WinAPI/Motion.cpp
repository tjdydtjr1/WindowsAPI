#include "Stdafx.h"
#include "Motion.h"

#include "Stdafx.h"
#include "Motion.h"

HRESULT Motion::init(void)
{
	GameNode::init();

	_startBox = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y - 300, 300, 100);
	_moveBox = RectMake(50, 50, 150, 100);
	_outerBox = RectMake(50, 150, 150, 100);
	_stingBox = RectMake(50, 250, 150, 100);
	_quickStingBox = RectMake(50, 350, 150, 100);
	_diagonalStingBox = RectMake(50, 450, 150, 100);
	_jumpBox = RectMake(50, 550, 150, 100);
	_clBox = RectMake(300, 20, 150, 100);


	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/BackGround.bmp", WINSIZE_X, WINSIZE_Y);

	
	_move = new GImage;
	_move->init("Resources/Images/Object/Move.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		3600, 800,
		9, 2,
		true, RGB(255, 0, 255));

	_outer = new GImage;
	_outer->init("Resources/Images/Object/outer.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		13800, 600,
		23, 1,
		true, RGB(255, 0, 255));

	_sting = new GImage;
	_sting->init("Resources/Images/Object/sting.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		8000, 600,
		10, 1,
		true, RGB(255, 0, 255));

	_quickSting = new GImage;
	_quickSting->init("Resources/Images/Object/quickSting.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		8000, 600,
		10, 1,
		true, RGB(255, 0, 255));

	_diagonalSting = new GImage;
	_diagonalSting->init("Resources/Images/Object/diagonalSting.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		15200, 600,
		19, 1,
		true, RGB(255, 0, 255));

	_jump = new GImage;
	_jump->init("Resources/Images/Object/jump.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		22400, 600,
		28, 1,
		true, RGB(255, 0, 255));

	_cl = new GImage;
	_cl->init("Resources/Images/Object/cl.bmp", WINSIZE_X, WINSIZE_Y,
		9800, 1800,
		5, 1,
		true, RGB(255, 0, 255));
	
	_alphaA = 0;
	_count = _index = 0;
	_isLeft = false;
	_isAlphaIncrese = false;
	_isStart = false;
	_clCount = 0;
	_jumpCount = 0;
	_outerCount = 0;
	_stingCount = 0;
	_quickStingCount = 0;
	_motion = 0;
	_diagonalStingCount = 0;



	return S_OK;
}	

void Motion::release(void)
{
	GameNode::release();
	SAFE_DELETE(_move);
	SAFE_DELETE(_outer);
	SAFE_DELETE(_sting);
	SAFE_DELETE(_quickSting);
	SAFE_DELETE(_diagonalSting);
	SAFE_DELETE(_jump);
	SAFE_DELETE(_bgImage);
}

void Motion::update(void)
{
	GameNode::update();
	
	if (PtInRect(&_startBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_isStart = true;
	}
	else if (PtInRect(&_moveBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = MOVE;
	}
	else if (PtInRect(&_outerBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = OUTER;
	}
	else if (PtInRect(&_stingBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = STING;
	}
	else if (PtInRect(&_quickStingBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = QUICKSTING;
	}
	else if (PtInRect(&_diagonalStingBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = DIAGONALSTING;
	}
	else if (PtInRect(&_jumpBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = JUMP;
	}
	else if (PtInRect(&_clBox, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_motion = CL;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_motion = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = false;
		_move->setX(_move->getX() - 8.0f);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = true;
		_move->setX(_move->getX() + 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{

	}

	if (_motion == MOVE)
	{
		if (_isLeft)
		{
			++_count;
			_move->setFrameY(1);

			if (_count % 3 == 0)
			{
				--_index;

				if (_index < 0)
				{
					_index = 10;
				}

				_move->setFrameX(_index);

			}
		}
		else
		{
			++_count;
			_move->setFrameY(0);

			if (_count % 2 == 0)
			{
				++_index;

				if (_index > 9)
				{
					_index = 0;
				}
				_move->setFrameX(_index);

			}
		}
	}
	else if (_motion == OUTER)
	{
		++_outerCount;
		_outer->setFrameY(1);

		if (_outerCount % 3 == 0)
		{
			++_index;
			if (_index > 23)
			{
				_index = 0;
			}

			_outer->setFrameX(_index);

		}
	}
	else if (_motion == STING)
	{
		++_stingCount;
		_sting->setFrameY(1);

		if (_stingCount % 3 == 0)
		{
			++_index;
			if (_index > 10)
			{
				_index = 0;
			}

			_sting->setFrameX(_index);

		}
	}
	else if (_motion == QUICKSTING)
	{
		++_quickStingCount;
		_quickSting->setFrameY(1);

		if (_quickStingCount % 3 == 0)
		{
			++_index;
			if (_index > 10)
			{
				_index = 0;
			}

			_quickSting->setFrameX(_index);

		}
	}

	else if (_motion == DIAGONALSTING)
	{
		++_diagonalStingCount;
		_diagonalSting->setFrameY(1);

		if (_diagonalStingCount % 3 == 0)
		{
			++_index;
			if (_index > 19)
			{
				_index = 0;
			}

			_diagonalSting->setFrameX(_index);

		}
	}
	else if (_motion == JUMP)
	{
		++_jumpCount;
		_diagonalSting->setFrameY(1);

		if (_jumpCount % 3 == 0)
		{
			++_index;
			if (_index > 29)
			{
				_index = 0;
			}

			_jump->setFrameX(_index);

		}
	}
	else if (_motion == CL)
	{
		++_clCount;
		_cl->setFrameY(1);

		if (++_clCount % 10 == 0)
		{
			++_index;
			if (_index > 5)
			{
				_index = 0;
			}

			_cl->setFrameX(_index);

		}
		}



}

void Motion::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : »ç°¢Çü ¾È¿¡ ¿µ¿ªÀ» ºê·¯½¬·Î Ã¤¿ì´Â ÇÔ¼ö
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================

	if (!_isStart)
	{
		_bgImage->alphaRender(memDC, 255);
		HFONT hFont;
		hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, JOHAB_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));
		hFont = (HFONT)SelectObject(memDC, hFont);

		//DrawRectMake(memDC, _startBox);
		SetBkColor(memDC, RGB(255, 255, 0));
		SetTextColor(memDC, RGB(255, 0, 0));
		TextOut(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y - 325, "Game Start", strlen("Game Start"));
		DeleteObject(hFont);
	}
	else
	{
		HFONT hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));
		hFont = (HFONT)SelectObject(memDC, hFont);
		SetTextColor(memDC, RGB(0, 0, 0));

		DrawRectMake(memDC, _moveBox);
		DrawRectMake(memDC, _outerBox);
		DrawRectMake(memDC, _stingBox);
		DrawRectMake(memDC, _quickStingBox);
		DrawRectMake(memDC, _diagonalStingBox);
		DrawRectMake(memDC, _jumpBox);
		DrawRectMake(memDC, _clBox);

		TextOut(memDC, 60, 75, "ÁÂ¿ì ¿òÁ÷ÀÓ", strlen("ÁÂ¿ì ¿òÁ÷ÀÓ"));
		TextOut(memDC, 60, 175, "°Ñ¿Ê ¹þ±â", strlen("°Ñ¿Ê ¹þ±â"));
		TextOut(memDC, 60, 275, "Âî¸£±â", strlen("Âî¸£±â"));
		TextOut(memDC, 60, 375, "ºü¸£°Ô Âî¸£±â", strlen("ºü¸£°Ô Âî¸£±â"));
		TextOut(memDC, 60, 475, "´ë°¢¼± Âî¸£±â", strlen("´ë°¢¼± Âî¸£±â"));
		TextOut(memDC, 60, 575, "¿ø µ¹¸®±â", strlen("¿ø µ¹¸®±â"));
		TextOut(memDC, 330, 50, "Å¬¶óÀÌ¸Æ½º", strlen("Å¬¶óÀÌ¸Æ½º"));

		DeleteObject(hFont);


		_bgImage->alphaRender(memDC, 70);

		switch (_motion)
		{
		case MOVE:
			_move->frameRender(memDC, WINSIZE_X / 2, WINSIZE_Y / 2);
			break;
		case OUTER:
			_outer->frameRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
			break;
		case STING:
			_sting->frameRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
			break;
		case QUICKSTING:
			_quickSting->frameRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
			break;
		case DIAGONALSTING:
			_diagonalSting->frameRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
			break;
		case JUMP:
			_jump->frameRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4);
			break;
		case CL:
			_cl->frameRender(memDC, 0, 0);
			break;

		defalut:
			break;
		}
	}
	// =======================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);

}
