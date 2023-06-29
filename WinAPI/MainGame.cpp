#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
	

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


}


void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	//_bgImage->render(memDC, 0, 0);
	//_plImage->render(memDC, _rc.left, _rc.top);
	// =======================================================
	//_bgImage->alphaRender(memDC, _alphaA);

	
	// =======================================================

	// =======================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);


}

