#include "Stdafx.h"
#include "ShootingGame.h"

HRESULT ShootingGame::init(void)
{
	GameNode::init();
	
	// 플레이어 초기 위치
	_playerA.setPlayerXY(50, 400);
	_playerB.setPlayerXY(750, 400);

	_playerBoxA[0] = RectMakeCenter(_playerA.getPlayerXY().x, _playerA.getPlayerXY().y, 50, 50);
	_playerBoxA[1] = RectMakeCenter(_playerA.getPlayerXY().x + 50, _playerA.getPlayerXY().y + 25, 50, 20);
	
	_playerBoxB[0] = RectMakeCenter(_playerB.getPlayerXY().x, _playerB.getPlayerXY().y, 50, 50);
	_playerBoxA[1] = RectMakeCenter(_playerA.getPlayerXY().x - 50, _playerA.getPlayerXY().y + 25, 50, 20);



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
	
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
	
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		
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

}
