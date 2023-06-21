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
	if (KEYMANAGER->isStayKeyDown(VK_HOME))
	{
		fireBulletA();
	}
	for (int i = 0; i < 5; ++i)
	{
		if (!_bulletA[i].fire)
		{
			continue;
		}
		_bulletA[i].rc.left += 10;
		_bulletA[i].rc.right += 10;

		if (collisionCheck(_bulletA[i].rc, _playerBoxB[0]) 
			|| collisionCheck(_bulletA[i].rc, _playerBoxB[1]))
		{
			_playerB.setHp(_playerB.getHp() - 1);
			
			_bulletA[i].rc = RectMakeCenter
			(
				_playerBoxA[1].left, _playerBoxA[1].bottom + 10, 10, 10
			);
		}

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
		_bulletB[i].rc.left -= 10;
		_bulletB[i].rc.right -= 10;

		if (collisionCheck(_bulletB[i].rc, _playerBoxA[0]) 
			|| collisionCheck(_bulletB[i].rc, _playerBoxA[1]))
		{
			_playerA.setHp(_playerA.getHp() - 1);
			_bulletA[i].rc = RectMakeCenter
			(
				_playerBoxB[1].left, _playerBoxB[1].bottom + 10, 10, 10
			);
		}

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

	if (_playerA.getHp() == 3)
	{
		HBRUSH brush_Green = CreateSolidBrush(RGB(0, 255, 0));
		brush_Green = (HBRUSH)::SelectObject(hdc, brush_Green);
		Rectangle(hdc, 50, 50, 400, 100);

		DeleteObject(brush_Green);
	}
	else if (_playerA.getHp() == 2)
	{
		HBRUSH brush_Blue = CreateSolidBrush(RGB(0, 0, 255));

		brush_Blue = (HBRUSH)::SelectObject(hdc, brush_Blue);
		Rectangle(hdc, 50, 50, 300, 100);
		DeleteObject(brush_Blue);

	}
	else if (_playerA.getHp() == 1)
	{
		HBRUSH brush_Red = CreateSolidBrush(RGB(255, 0, 0));

		brush_Red = (HBRUSH)::SelectObject(hdc, brush_Red);
		Rectangle(hdc, 50, 50, 100, 100);
		DeleteObject(brush_Red);
	}
	else
	{
		_hpBar[0] = RectMake(50, 50, 350, 50);
	}
	

	if (_playerB.getHp() == 3)
	{
		HBRUSH brush_Green = CreateSolidBrush(RGB(0, 255, 0));
		brush_Green = (HBRUSH)::SelectObject(hdc, brush_Green);
		Rectangle(hdc, 400, 50, 750, 100);

		DeleteObject(brush_Green);
	}
	else if (_playerB.getHp() == 2)
	{
		HBRUSH brush_Blue = CreateSolidBrush(RGB(0, 0, 255));

		brush_Blue = (HBRUSH)::SelectObject(hdc, brush_Blue);
		Rectangle(hdc, 400, 50, 600, 100);
		DeleteObject(brush_Blue);

	}
	else if (_playerB.getHp() == 1)
	{
		HBRUSH brush_Red = CreateSolidBrush(RGB(255, 0, 0));

		brush_Red = (HBRUSH)::SelectObject(hdc, brush_Red);
		Rectangle(hdc, 400, 50, 500, 100);
		DeleteObject(brush_Red);
	}
	else
	{
		_hpBar[1] = RectMake(400, 50, 350, 50);
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
			_playerBoxA[1].right, _playerBoxA[1].bottom + 10, 10, 10
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

bool ShootingGame::collisionCheck(RECT rc1, RECT rc2)
{
	if (rc1.left <= rc2.left &&
		rc1.right >= rc2.right &&
		rc1.bottom >= rc2.bottom &&
		rc1.top <= rc2.top)
	{
		return true;
	}
	return false;
}