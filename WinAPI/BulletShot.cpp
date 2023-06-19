#include "Stdafx.h"
#include "BulletShot.h"

HRESULT BulletShot::init(void)
{
	GameNode::init();
	_player[0] = RectMake(400, 700, 30, 30);
	_player[1] = RectMake(400, 730, 30, 30);
	_bullet = RectMake(_player[1].left, _player[1].top, 15, 15);
	return S_OK;
}

void BulletShot::release(void)
{
	GameNode::release();
}

void BulletShot::update(void)
{
	GameNode::update();


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
	DrawEllipseMake(hdc, _bullet);
	LineMove(hdc, _player[1].right, _player[1].bottom, _player[1].right + 10, _player[1].bottom + 10);
}
