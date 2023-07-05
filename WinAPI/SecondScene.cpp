#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("��� ����", "Resources/Images/BackGround/map.bmp", WINSIZE_X, WINSIZE_Y);


	return S_OK;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
	_bgSpeed += 3;
}

void SecondScene::render(void)
{
	IMAGEMANAGER->loopRender("��� ����", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed, 0);

	FONTMANAGER->drawText(getMemDC(), 100, WINSIZE_Y / 2, "�ü�ü", 200, 100, L"testtesttest", strlen("testtesttest"), RGB(255, 255, 255));
	
}
