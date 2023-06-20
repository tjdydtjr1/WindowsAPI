#include "Stdafx.h"
#include "ShootingEx.h"

HRESULT ShootingEx::init(void)
{
	GameNode::init();

	_playerRc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2 + 200, 40, 40);
	_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 60, 20);
	_hp = 3;
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		_enemy[i].rc = RectMakeCenter(
			RND->getFromIntTo(20, WINSIZE_X - 20),
			-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
			50, 50);
		_enemy[i].speed = RND->getFromIntTo(2, 4);
		_enemy[i].die = false;
	}

	return S_OK;
}

void ShootingEx::release(void)
{
	GameNode::release();

}

void ShootingEx::update(void)
{
	GameNode::update();

	// 키를 누른다는 이벤트를 통해 파생 코드들이 발생 => 필수 조건문
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && WINSIZE_X > _playerRc.right)
	{
		_playerRc.left += PLAYER_SPEED;
		_playerRc.right += PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && 0 < _playerRc.left)
	{
		_playerRc.left -= PLAYER_SPEED;
		_playerRc.right -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && 0 < _playerRc.top)
	{
		_playerRc.top -= PLAYER_SPEED;
		_playerRc.bottom -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && WINSIZE_Y > _playerRc.bottom)
	{
		_playerRc.top += PLAYER_SPEED;
		_playerRc.bottom += PLAYER_SPEED;
	}

	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		if (_enemy[i].die)
		{
			continue;
		}

		if (collisionCheck(_enemy[i].rc, _playerRc))
		{
			_enemy[i].rc = RectMakeCenter(
				RND->getFromIntTo(20, WINSIZE_X - 20),
				-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
				50, 50);
			--_hp;
		}

		if (collisionCheck(_enemy[i].rc, _bullet[0].rc))
		{
			HDC hdc;
			hdc = GetDC(_hWnd);
			TextOut(hdc, 400, 400, "test", strlen("test"));
			_enemy[i].rc = RectMakeCenter(
				RND->getFromIntTo(20, WINSIZE_X - 20),
				-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
				50, 50);
			_enemy[i].die = true;
			ReleaseDC(_hWnd, hdc);
		}
		else
		{
			_enemy[i].rc.top += _enemy[i].speed;
			_enemy[i].rc.bottom += _enemy[i].speed;
		}
		if (_enemy[i].rc.top > WINSIZE_Y)
		{
			_enemy[i].rc = RectMakeCenter(
				RND->getFromIntTo(20, WINSIZE_X - 20),
				-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
				50, 50);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		// 플레이어 적과 달리 총알은 메모리 사용량이 많기 때문에
		// 메모리를 스택에서 사용후 제거한다.
		fireBullet();
	}

	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (!_bullet[i].fire) continue;
		_bullet[i].rc.top -= 14;
		_bullet[i].rc.bottom -= 14;

		if (_bullet[i].rc.bottom < 0)
			_bullet[i].fire = false;
	}

	
}

void ShootingEx::render(HDC hdc)
{
	DrawRectMake(hdc, _playerRc);
	
	if (_hp == 3)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
		brush = (HBRUSH)::SelectObject(hdc, brush);
		_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 60, 20);
		DrawRectMake(hdc, _hpBox);

		DeleteObject(brush);
	}
	else if (_hp == 2)
	{
		_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 60, 20);
		DrawRectMake(hdc, _hpBox);
		HBRUSH brush = CreateSolidBrush(RGB(255, 150, 0));
		brush = (HBRUSH)::SelectObject(hdc, brush);
		_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 40, 20);

		DrawRectMake(hdc, _hpBox);

		DeleteObject(brush);
	}
	else if(_hp == 1)
	{
		_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 60, 20);
		DrawRectMake(hdc, _hpBox);
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		brush = (HBRUSH)::SelectObject(hdc, brush);
		_hpBox = RectMake(_playerRc.left - 10, _playerRc.bottom, 20, 20);

		DrawRectMake(hdc, _hpBox);

		DeleteObject(brush);
	}
	else
	{
		TextOut(hdc, 350, 400, "게임 종료", strlen("게임 종료"));
		_playerRc = RectMakeCenter(1000,1000, 40, 40);

	}
	
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	brush = (HBRUSH)::SelectObject(hdc, brush);
	for (int i = 0; i < ENEMY_MAX; ++i)
	{
		if (_enemy[i].die) continue;
		Rectangle(hdc,
			_enemy[i].rc.left,
			_enemy[i].rc.top,
			_enemy[i].rc.right,
			_enemy[i].rc.bottom);
	}

	DeleteObject(brush);

	brush = CreateSolidBrush(RGB(255, 20, 20));
	brush = (HBRUSH)::SelectObject(hdc, brush);
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (!_bullet[i].fire)
		{
			continue;
		}
		Ellipse(hdc,
			_bullet[i].rc.left,
			_bullet[i].rc.top,
			_bullet[i].rc.right,
			_bullet[i].rc.bottom);
	}
	DeleteObject(brush);

}

void ShootingEx::fireBullet(void)
{
	for (int i = 0; i < BULLET_MAX; ++i)
	{
		if (_bullet[i].fire)
		{
			continue;
		}

		_bullet[i].fire = true;

		_bullet[i].rc = RectMakeCenter
		(
			_playerRc.left + (_playerRc.right - _playerRc.left) / 2,
			_playerRc.top + (_playerRc.bottom - _playerRc.top) / 2 - 24,
			10, 10
		);
		break;
	}
}

bool ShootingEx::collisionCheck(RECT rc1, RECT rc2)
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
