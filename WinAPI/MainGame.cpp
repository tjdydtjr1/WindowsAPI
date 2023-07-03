#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);
	
	_player = new Racing;
	_enemy = new Enemy;

	_player->setPlayerBox(WINSIZE_X / 2, WINSIZE_Y - 100);
	


	// 트랙
	IMAGEMANAGER->addImage("Track", "Resources/Images/BackGround/Track.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255,0,255));
	// 플레이어
	IMAGEMANAGER->addFrameImage("Player_Car", "Resources/Images/Object/Car.bmp", 38, 32, 1, 1, true, RGB(255, 0, 255));
	// 적
	IMAGEMANAGER->addFrameImage("Enemy_Car", "Resources/Images/Object/Enemy_Car.bmp", 38, 50, 1, 1, true, RGB(255, 0, 255));
	// 계기판
	IMAGEMANAGER->addFrameImage("speed", "Resources/Images/Object/speed.bmp", 270, 198, 1, 1, true, RGB(255, 0, 255));

	
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

}

void MainGame::update(void)
{
	GameNode::update();
	
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		

	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		

	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		

	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		
	}
	


}


void MainGame::render(void)
{
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	
	/*
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		
	}
	*/

	IMAGEMANAGER->loopRender("Track", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), 0,_player->getSpeed());
	IMAGEMANAGER->frameRender("Player_Car", getMemDC(), _player->getPlayerBox().left, _player->getPlayerBox().top, 0, 0,  100, 100);
	IMAGEMANAGER->frameRender("Enemy_Car", getMemDC(), _enemy->getEnemyBox().left, 0, 0, _enemy->getEnemyBox().top, 100, 100);


	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

