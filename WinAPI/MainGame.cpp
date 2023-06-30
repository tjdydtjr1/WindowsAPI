#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);

	IMAGEMANAGER->addImage("���� �����̽�", "Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255,0,255));

	_alphaA = 0;
	_isAlphaIncrese = false;

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();



}

void MainGame::update(void)
{
	GameNode::update();

	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		
	}

	++_count;

	if (_count % 3 == 0)
	{
		++_alphaA;
		if (_alphaA > 255)
		{
			_alphaA = 255;
		}
	}


}


void MainGame::render(void)
{
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	
	IMAGEMANAGER->alphaRender("���� �����̽�", getMemDC(), 0, 0, _alphaA);

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

