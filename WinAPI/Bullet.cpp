#include "Stdafx.h"
#include "Bullet.h"


HRESULT Bullet::init(void)
{
	GameNode::init();
	_theta = 6;
	_speed = 3;
	_idx = 0;
	
	return S_OK;
}

void Bullet::release(void)
{
	GameNode::release();
}

void Bullet::update(void)
{
	GameNode::update();

	_berral.x = cosf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_berral.y = sinf((_theta - 90) * PI / 180.0f) * 100 + WINSIZE_Y;

	
	// cosf(각도)*r + 600, sinf(각도)*r + 800 + speed;
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		// 총알 발사
		fireBullet();
		_bullet[_idx].xy.x = cosf((_theta - 90) * PI / 180.0f) * _bullet[_idx].r;
		_bullet[_idx].xy.y = sinf((_theta - 90) * PI / 180.0f) * _bullet[_idx].r;
		++_idx;

		/*if (!_bullet[_idx].fire)
		{
			_bullet[_idx].degree = _theta;
		}
		++_idx;*/
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_theta -= MOVE_SPEED;
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_theta += MOVE_SPEED;
	}
	
	for (int i = 0; i < MAX_BULLET; ++i)
	{
		if (!_bullet[i].fire)
		{
			continue;
		}

		/*_bullet[i].rc.left -= MOVE_SPEED;
		_bullet[i].rc.right -= MOVE_SPEED;
		_bullet[i].rc.top -= (_berral.y / (_berral.x + MOVE_SPEED)) * MOVE_SPEED;
		_bullet[i].rc.bottom -= (_berral.y / (_berral.x + MOVE_SPEED)) * MOVE_SPEED;*/

		//tan(_theta * PI / 180.0f)
		// _theta => 포신 각도			각도								반지름 증가
		/*if (_berral.x < WINSIZE_X / 2)
		{
			_bullet[i].rc.left -= MOVE_SPEED;
			_bullet[i].rc.right -= MOVE_SPEED;
			_bullet[i].rc.top -= (_berral.y / _berral.x + MOVE_SPEED) * MOVE_SPEED;
			_bullet[i].rc.bottom -= (_berral.y / _berral.x + MOVE_SPEED) * MOVE_SPEED;
		}
		else if (_berral.x > WINSIZE_X / 2)
		{
			_bullet[i].rc.left += MOVE_SPEED;
			_bullet[i].rc.right += MOVE_SPEED;
			_bullet[i].rc.top -= (_berral.y / _berral.x + MOVE_SPEED) * MOVE_SPEED;
			_bullet[i].rc.bottom -= (_berral.y / _berral.x + MOVE_SPEED) * MOVE_SPEED;

		}*/
	}
		//_bullet[i].rc.top -= _berral.y;
		//_bullet[i].rc.bottom -= _berral.y;



		/*_speed += 3;
		_bullet[i].rc.left	+= _berral.x + _speed;
		_bullet[i].rc.top	+= _berral.y + _speed;
		_bullet[i].rc.right += _berral.x + _speed;
		_bullet[i].rc.bottom += _berral.y + _speed;*/

		/*if (_berral.x > 0 && _berral.y > 0)
		{
			_bullet[i].rc.left -= MOVE_SPEED;
			_bullet[i].rc.top -= MOVE_SPEED;
			_bullet[i].rc.right -= MOVE_SPEED;
			_bullet[i].rc.bottom -= MOVE_SPEED;
		}
		else if (_berral.x < 0 && _berral.y < 0)
		{
			_bullet[i].rc.left += MOVE_SPEED;
			_bullet[i].rc.top += MOVE_SPEED;
			_bullet[i].rc.right += MOVE_SPEED;
			_bullet[i].rc.bottom += MOVE_SPEED;
		}*/

		/*_bullet[i].rc.left += tanf(_berral.x);
		_bullet[i].rc.top += tanf(_berral.y);
		_bullet[i].rc.right += tanf(_berral.x);
		_bullet[i].rc.bottom += tanf(_berral.y);*/

		/*if (_bullet[i].rc.left < WINSIZE_X)
		{
			_bullet[i].rc.left -= MOVE_SPEED;
			_bullet[i].rc.top -= MOVE_SPEED;
			_bullet[i].rc.right += MOVE_SPEED;
			_bullet[i].rc.bottom += MOVE_SPEED;
		}
		else if (_bullet[i].rc.top < WINSIZE_Y)
		{
			_bullet[i].rc.left += MOVE_SPEED;
			_bullet[i].rc.top += MOVE_SPEED;
			_bullet[i].rc.right += MOVE_SPEED;
			_bullet[i].rc.bottom += MOVE_SPEED;
		}
		else if (_bullet[i].rc.right > WINSIZE_X)
		{
			_bullet[i].rc.left -= MOVE_SPEED;
			_bullet[i].rc.top += MOVE_SPEED;
			_bullet[i].rc.right -= MOVE_SPEED;
			_bullet[i].rc.bottom += MOVE_SPEED;
		}
		else if (_bullet[i].rc.bottom > WINSIZE_Y)
		{
			_bullet[i].rc.left -= MOVE_SPEED;
			_bullet[i].rc.top -= MOVE_SPEED;
			_bullet[i].rc.right -= MOVE_SPEED;
			_bullet[i].rc.bottom -= MOVE_SPEED;
		}*/
	
}

void Bullet::render(HDC hdc)
{
	LineMake(hdc, WINSIZE_X / 2, WINSIZE_Y, _berral.x, _berral.y);
	EllipseMake(hdc, WINSIZE_X / 2 - 50, WINSIZE_Y - 50, 100, 100);
	
	for (int i = 0; i < MAX_BULLET; ++i)
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

}

void Bullet::fireBullet()
{
	for (int i = 0; i < MAX_BULLET; ++i)
	{
		if (_bullet[i].fire)
		{
			continue;
		}
		_bullet[i].fire = true;
		_bullet[i].rc = RectMake(_berral.x - 50, _berral.y - 50, 50, 50);
		break;
	}

}
