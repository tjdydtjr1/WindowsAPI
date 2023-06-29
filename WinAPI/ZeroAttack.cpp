#include "Stdafx.h"
#include "ZeroAttack.h"

HRESULT ZeroAttack::init(void)
{
	GameNode::init();
	Attack_1 = new GImage;
	Attack_1->init("Resources/Images/Object/Attak_1.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		1440, 100,
		12, 1,
		true, RGB(255, 0, 255));

	Attack_2 = new GImage;
	Attack_2->init("Resources/Images/Object/Attack_2.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		1200, 80,
		10, 1,
		true, RGB(255, 0, 255));

	Attack_3 = new GImage;
	Attack_3->init("Resources/Images/Object/Attack_3.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		1440, 80,
		12, 1,
		true, RGB(255, 0, 255));

	/*MX 3940, MY 586,
		X 갯수 10, Y 갯수 2,*/

	_alphaA = 0;
	_count = _index = 0;
	_isLeft = false;
	_isAlphaIncrese = false;

	_rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 120, 80);

	_motion = 0;
	return S_OK;
}

void ZeroAttack::release(void)
{
	GameNode::release();

	SAFE_DELETE(Attack_1);
	SAFE_DELETE(Attack_2);
	SAFE_DELETE(Attack_3);
}

void ZeroAttack::update(void)
{
	GameNode::update();


	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		Attack_1->setX(Attack_1->getX() - 8.0f);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		Attack_1->setX(Attack_1->getX() + 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{

	}

	//if (_isLeft)
	//{
	//	++_count;
	//	Attack_1->setFrameY(1);
	//	Attack_2->setFrameY(1);
	//	Attack_3->setFrameY(1);

	//	if (_count % 3 == 0)
	//	{
	//		--_index;

	//		if (_index < 0)
	//		{
	//			_index = 10;
	//		}

	//		Attack_1->setFrameX(_index);
	//		Attack_2->setFrameX(_index);
	//		Attack_3->setFrameX(_index);

	//	}
	//}
	//else
	//{
	//	++_count;
	//	Attack_1->setFrameY(0);
	//	Attack_2->setFrameY(0);
	//	Attack_3->setFrameY(0);

	//	if (_count % 2 == 0)
	//	{
	//		++_index;

	//		if (_index > 10)
	//		{
	//			_index = 0;
	//		}
	//		Attack_1->setFrameX(_index);
	//		Attack_2->setFrameX(_index);
	//		Attack_3->setFrameX(_index);

	//	}
	//}


	if (true)
	{
		++_count;
		Attack_1->setFrameY(0);
		Attack_2->setFrameY(0);
		Attack_3->setFrameY(0);

		if (_count % 2 == 0)
		{
			++_index;

		}
	}

	if (_index < 13)
	{
		_motion = 0;
		Attack_1->setFrameX(_index);
	}
	else if (_index > 12 && _index < 22)
	{
		_motion = 1;
		Attack_2->setFrameX(_index - 12);
	}
	else if (_index < 34)
	{
		_motion = 2;
		Attack_3->setFrameX(_index - 22);
	}
	else
	{
		_motion = 0;
		_index = 0;
	}
}

void ZeroAttack::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	//_bgImage->render(memDC, 0, 0);
	//_plImage->render(memDC, _rc.left, _rc.top);
	// =======================================================
	//_bgImage->alphaRender(memDC, _alphaA);

	if (KEYMANAGER->isToggleKey(VK_SPACE))
	{
		switch (_motion)
		{
		case 0:
			Attack_1->frameRender(memDC, WINSIZE_X / 2, WINSIZE_Y / 2 - 15);
			break;
		case 1:
			Attack_2->frameRender(memDC, WINSIZE_X / 2 + 5, WINSIZE_Y / 2);
			break;
		case 2:
			Attack_3->frameRender(memDC, WINSIZE_X / 2 + 20, WINSIZE_Y / 2 - 5);
			break;
		}
	}
	// =======================================================

	// =======================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);

}
