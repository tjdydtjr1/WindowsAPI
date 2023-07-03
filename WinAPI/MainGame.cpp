#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);
	
	_player = new Racing;
	_enemy = new Enemy;

	// 트랙
	IMAGEMANAGER->addImage("Track", "Resources/Images/BackGround/Track.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255,0,255));
	// 플레이어
	IMAGEMANAGER->addFrameImage("Player_Car", "Resources/Images/Object/Car.bmp", 38, 32, 1, 1, true, RGB(255, 0, 255));
	// 적
	IMAGEMANAGER->addFrameImage("Enemy_Car", "Resources/Images/Object/Enemy_Car.bmp", 38, 50, 1, 1, true, RGB(255, 0, 255));
	// 계기판
	IMAGEMANAGER->addFrameImage("Speed", "Resources/Images/Object/speed.bmp", 270, 198, 1, 1, true, RGB(255, 0, 255));
	// 엔드
	IMAGEMANAGER->addImage("End", "Resources/Images/BackGround/End.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_bgSpeed = 0;

	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		_isCreate[i] = false;
	}
	_score = 0;
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

}

void MainGame::update(void)
{
	GameNode::update();

	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		if (_player->collisionCheck(&_player->getPlayerBox(), &_enemy[i].getEnemyBox(i)))
		{
			_player->setDie(true);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player->setPlayerBox(_player->getPlayerBox().left - 5, _player->getPlayerBox().right - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player->setPlayerBox(_player->getPlayerBox().left + 5, _player->getPlayerBox().right + 5);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_player->getSpeed() < 180)
		{
			_player->setSpeed(_player->getSpeed() + 5);
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_player->getSpeed() > 10)
		{
			_player->setSpeed(_player->getSpeed() - 5);
		}
	}
	
	
	if (!_player->getSkill())
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_player->setSkill(true);
		}
		else if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_player->setSkill(true);
		}
		else if (KEYMANAGER->isOnceKeyDown('C'))
		{
			_player->setSkill(true);
		}

	}
	
	// 적 생성
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		if (_isCreate[i])
		{
			_enemy[i].setMoveBox(_enemy[i].getEnemyBox(i).top + _player->getSpeed(), _enemy[i].getEnemyBox(i).bottom + _player->getSpeed(), i);
		}

		if (_enemy[i].getEnemyBox(i).top >= WINSIZE_Y)
		{
			_isCreate[i] = false;
			_score += 1;
		}
	}
	
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		_xy[i].x = rand() % WINSIZE_X + 200;
		_xy[i].y = rand() % WINSIZE_Y / 2 - 600;

		if (!_isCreate[i])
		{
			_enemy[i].setEnemyBox(_xy[i].x, _xy[i].y, i);
			_isCreate[i] = true;
		}
	}

	_bgSpeed -= BASE_SPEED;
	_bgSpeed -= _player->getSpeed();
	
	// 속도 확인용
	printf("_bgSpeed : %d, Speed : %d\n", _bgSpeed, _player->getSpeed());
}


void MainGame::render(void)
{
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================

	IMAGEMANAGER->loopRender("Track", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), 0, _bgSpeed);
	IMAGEMANAGER->frameRender("Player_Car", getMemDC(), _player->getPlayerBox().left, _player->getPlayerBox().top, 0, 0,  100, 100);
	
	//
	//IMAGEMANAGER->frameRender("ENemy_Car",getMemDC(), _test.left, )
	//
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		IMAGEMANAGER->frameRender("Enemy_Car", getMemDC(), _enemy[i].getEnemyBox(i).left, _enemy[i].getEnemyBox(i).top, 0, 0, 100, 100);
	}
	
	
	IMAGEMANAGER->frameRender("Speed", getMemDC(), 0, WINSIZE_Y - 200);
	_player->printSpeedLine(getMemDC());

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		DrawRectMake(getMemDC(), _player->getPlayerBox());
		IMAGEMANAGER->frameRender("Player_Car", getMemDC(), _player->getPlayerBox().left, _player->getPlayerBox().top, 0, 0, 100, 100);
		
		for (int i = 0; i < ENEMY_MAX; ++i)
		{
			DrawRectMake(getMemDC(), _enemy->getEnemyBox(i));
			IMAGEMANAGER->frameRender("Enemy_Car", getMemDC(), _enemy[i].getEnemyBox(i).left, 0, 0, _enemy[i].getEnemyBox(i).top, 100, 100);
		}
	}

	if (_player->getSkill() && KEYMANAGER->isOnceKeyDown('Z'))
	{
	
		_player->absolute(getMemDC(),_player->getPlayerBox());
		IMAGEMANAGER->frameRender("Player_Car", getMemDC(), _player->getPlayerBox().left, _player->getPlayerBox().top, 0, 0, 100, 100);
		_player->setSkill(false);
	}
	if (_player->getSkill() && KEYMANAGER->isOnceKeyDown('X'))
	{
		for (int i = 0; i < ENEMY_MAX; ++i)
		{
			_player->carDivide(_enemy[i].getEnemyBox(i));
		}
		_player->setSkill(false);

	}
	else if (_player->getSkill() && KEYMANAGER->isOnceKeyDown('C'))
	{
		_player->setSkill(false);

	}

	if (_player->getDie())
	{
		RECT _rc = RectMake(WINSIZE_X / 2 - 150 , WINSIZE_Y  - 200, 300, 200);
		char text[128];
		// 엔딩
		IMAGEMANAGER->render("End", getMemDC());
		TextOut(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y - 100, "다시 시작 하려면 여길 누르세요.", strlen("다시 시작 하려면 여길 누르세요."));
		wsprintf(text, "SCORE : %d", _score);
		TextOut(getMemDC(), WINSIZE_X / 2, WINSIZE_Y - 50, text, strlen(text));

		if (PtInRect(&_rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_player->setDie(false);
			_player->setSpeed(0);
			_bgSpeed = -BASE_SPEED;

			for (int i = 0; i < ENEMY_MAX; ++i)
			{
				_isCreate[i] = false;
				_xy[i].x = rand() % WINSIZE_X + 200;
				_xy[i].y = rand() % WINSIZE_Y / 2 - 600;

				if (!_isCreate[i])
				{
					_enemy[i].setEnemyBox(_xy[i].x, _xy[i].y, i);
					_isCreate[i] = true;
				}
			}
		}
	}

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

