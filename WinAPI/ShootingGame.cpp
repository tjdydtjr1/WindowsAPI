#include "Stdafx.h"
#include "ShootingGame.h"

HRESULT ShootingGame::init(void)
{
	GameNode::init();
	
	// 플레이어 초기 위치
	_playerA.setPlayerXY(50, 400);
	_playerB.setPlayerXY(750, 400);

	// hpBar
	_hpBar[0] = RectMake(50, 50, 350, 50);
	_hpBar[1] = RectMake(400, 50, 350, 50);

	// mpBar
	_mpBar[0] = RectMake(10, 750, 100, 20);
	_mpBar[1] = RectMake(690, 750, 100, 20);
	return S_OK;
}

void ShootingGame::release(void)
{
	GameNode::release();
}

void ShootingGame::update(void)
{
	GameNode::update();
	_playerBoxA[0] = RectMakeCenter(_playerA.getPlayerXY().x, _playerA.getPlayerXY().y, 50, 50);
	_playerBoxA[1] = RectMakeCenter(_playerA.getPlayerXY().x + 30, _playerA.getPlayerXY().y, 30, 20);

	_playerBoxB[0] = RectMakeCenter(_playerB.getPlayerXY().x, _playerB.getPlayerXY().y, 50, 50);
	_playerBoxB[1] = RectMakeCenter(_playerB.getPlayerXY().x - 30, _playerB.getPlayerXY().y, 30, 20);
	
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _playerA.getPlayerXY().y > 140)
	{
		_playerA.setPlayerXY(_playerA.getPlayerXY().x, _playerA.getPlayerXY().y - PLAYER_SPEED);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _playerB.getPlayerXY().y < WINSIZE_Y - 80)
	{
		_playerA.setPlayerXY(_playerA.getPlayerXY().x, _playerA.getPlayerXY().y + PLAYER_SPEED);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RETURN))
	{
		fireBulletA();
	}
	for (int i = 0; i < 5; ++i)
	{
		if (!_bulletA[i].fire)
		{
			continue;
		}
		_bulletA[i].rc.left += 14;
		_bulletA[i].rc.right += 14;

		if (_bulletA[i].rc.right > WINSIZE_X)
		{
			_bulletA[i].fire = false;
		}
	}
	

	if (KEYMANAGER->isStayKeyDown(VK_WKEY) && _playerB.getPlayerXY().y > 140)
	{
		_playerB.setPlayerXY(_playerB.getPlayerXY().x, _playerB.getPlayerXY().y - PLAYER_SPEED);
	}
	if (KEYMANAGER->isStayKeyDown(VK_SKEY) && _playerB.getPlayerXY().y < WINSIZE_Y - 80)
	{
		_playerB.setPlayerXY(_playerB.getPlayerXY().x, _playerB.getPlayerXY().y + PLAYER_SPEED);
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		fireBulletB();
	}
	for (int i = 0; i < 5; ++i)
	{
		if (!_bulletB[i].fire)
		{
			continue;
		}
		_bulletB[i].rc.left -= 14;
		_bulletB[i].rc.right -= 14;

		if (_bulletB[i].rc.right < 0)
		{
			_bulletB[i].fire = false;
		}
	}
	
}

void ShootingGame::render(HDC hdc)
{
	DrawRectMake(hdc, _hpBar[0]);
	DrawRectMake(hdc, _hpBar[1]);
	DrawRectMake(hdc, _mpBar[0]);
	DrawRectMake(hdc, _mpBar[1]);
	DrawRectMake(hdc, _playerBoxA[0]);
	DrawRectMake(hdc, _playerBoxA[1]);

	DrawRectMake(hdc, _playerBoxB[0]);
	DrawRectMake(hdc, _playerBoxB[1]);

	for (int i = 0; i < 5; ++i)
	{
		if (!_bulletB[i].fire)
		{
			continue;
		}
		Ellipse(hdc,
			_bulletB[i].rc.left,
			_bulletB[i].rc.top,
			_bulletB[i].rc.right,
			_bulletB[i].rc.bottom);
	}

	for (int i = 0; i < 5; ++i)
	{
		if (!_bulletA[i].fire)
		{
			continue;
		}
		Ellipse(hdc,
			_bulletA[i].rc.left,
			_bulletA[i].rc.top,
			_bulletA[i].rc.right,
			_bulletA[i].rc.bottom);
	}

	


}

void ShootingGame::fireBulletA(void)
{
	for (int i = 0; i < 5; ++i)
	{
		if (_bulletA[i].fire)
		{
			continue;
		}

		_bulletA[i].fire = true;

		_bulletA[i].rc = RectMakeCenter
		(
			_playerBoxA[1].left, _playerBoxA[1].bottom + 10, 10, 10
		);
		break;
	}
}


void ShootingGame::fireBulletB(void)
{
	for (int i = 0; i < 5; ++i)
	{
		if (_bulletB[i].fire)
		{
			continue;
		}

		_bulletB[i].fire = true;

		_bulletB[i].rc = RectMakeCenter
		(
			_playerBoxB[1].left, _playerBoxB[1].bottom - 10, 10, 10
		);
		break;
	}
}

