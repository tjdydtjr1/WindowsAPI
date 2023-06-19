#include "Stdafx.h"
#include "BulletShot.h"

HRESULT BulletShot::init(void)
{
	GameNode::init();
	_player[0] = RectMake(400, 700, 30, 30);
	_player[1] = RectMake(400, 730, 30, 30);
	
	_bullet = RectMake(_player[0].right + 10, _player[0].top, 15, 15);
	_bulletVec.push_back(_bullet);
	_iterVec = _bulletVec.begin();
	_isFire = false;

	return S_OK;
}

void BulletShot::release(void)
{
	GameNode::release();
}

void BulletShot::update(void)
{
	GameNode::update();

	if (_bullet.top > 10 && _isFire)
	{
		_bullet.top -= 3;
		_bullet.bottom -= 3;
	}
	else
	{
		_bulletVec.push_back(_bullet);
		_bullet = RectMake(_player[0].right + 10, _player[0].top, 15, 15);
		_isFire = false;
	}

	// 왼쪽 방향키 플레이어 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player[0].left -= 3;
		_player[0].right -= 3;
		_player[1].left -= 3;
		_player[1].right -= 3;

	}
	// 오른쪽 방향키 플레이어 이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player[0].left += 3;
		_player[0].right += 3;
		_player[1].left += 3;
		_player[1].right += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		_isFire = true;
	}
	
}

void BulletShot::render(HDC hdc)
{
	// 플레이어
	DrawEllipseMake(hdc, _player[0]);
	DrawRectMake(hdc, _player[1]);
	LineMove(hdc, _player[1].left, _player[1].top, _player[1].left - 10, _player[1].top + 10);
	LineMove(hdc, _player[1].left, _player[1].bottom, _player[1].left - 10, _player[1].bottom + 10);
	LineMove(hdc, _player[1].right, _player[1].top, _player[1].right + 20, _player[1].top - 20);
	LineMove(hdc, _player[1].right, _player[1].bottom, _player[1].right + 10, _player[1].bottom + 10);
	if (_isFire)
	{
		DrawEllipseMake(hdc, _bullet);
	}
	
	/*if (_isFire)
	{
		for (_iterVec; _iterVec != _bulletVec.end(); ++_iterVec)
		{
			DrawEllipseMake(hdc, *(_iterVec));
		}
	}*/

}
