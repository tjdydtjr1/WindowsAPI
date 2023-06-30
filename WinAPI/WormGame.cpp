#include "Stdafx.h"
#include "WormGame.h"

HRESULT WormGame::init(void)
{
	GameNode::init();
	_theta = 30;
	_xy.x =  WINSIZE_X / 2;
	_xy.y =  WINSIZE_Y - 100;

	_rc = RectMakeCenter(_xy.x, _xy.y, 50, 50);

	// =============================================================================

	// 초기 위치
	for (int i = 0; i < MAX_WORM; ++i)
	{
		_worm[i].m_xy.x = WINSIZE_X / 2;
		_worm[i].m_xy.y = WINSIZE_Y - 100;

		_worm[i].m_rc = RectMakeCenter(_worm[i].m_xy.x, _worm[i].m_xy.y, 50, 50);
	}
	
	// 각도에 따른 이동
	_speed.x = cosf((_theta - 90) * PI / 180.f) * MOVE_SPEED;
	_speed.y = sinf((_theta - 90) * PI / 180.f) * MOVE_SPEED;

	return S_OK;
}

void WormGame::release(void)
{
	GameNode::release();
}

void WormGame::update(void)
{
	GameNode::update();
	
	_rc = RectMakeCenter(_xy.x, _xy.y, 50, 50);
	
	// 방향 수정
	_speed.x = cosf((_theta - 90) * PI / 180.f) * MOVE_SPEED;
	_speed.y = sinf((_theta - 90) * PI / 180.f) * MOVE_SPEED;
	
	// 방향, 속도 증가
	_xy.x += _speed.x;
	_xy.y += _speed.y;



	for (int i = 0; i < MAX_WORM; ++i)
	{
		_worm[i].m_xy.x += _speed.x;
		_worm[i].m_xy.y += _speed.y;

		_worm[i].m_rc = RectMakeCenter(_worm[i].m_xy.x, _worm[i].m_xy.y, 50, 50);
	}

	// x > y 45도 이하
	// x < y 45도 이상
	if (_rc.left < 10)
	{
		_theta = (180 - _theta * 2);
		//_theta = 30;
	}
	else if (_rc.right >= WINSIZE_X)
	{
		_theta = -(180 - _theta * 2);

	}
	 if (_rc.top <= 10)
	{
		 _theta = -(180 - _theta * 2);

		 if (0 < _theta && _theta < 30)
		 {
			 
		 }
		 else if (30 < _theta && _theta < 60)
		 {

		 }
		 else if (60 < _theta && _theta < 90)
		 {

		 }
	}
	else if (_rc.bottom >= WINSIZE_Y)
	{
		 _theta = (180 - _theta * 2);

	}
	
/*	_rc.left		 -= _test;
	_rc.right		 -= _test;
	_rc.top			-= _xy.y / (_xy.x + _test) * 2;
	_rc.bottom		 -= _xy.y / (_xy.x + _test) * 2;*/

	// speed 값에서 speedx, speedy
	/*_rc.left -= _test;
	_rc.right -= _test;
	_rc.top -= _xy.y * _test / (_xy.x * _test);
	_rc.bottom -= _xy.y * _test / (_xy.x * _test);*/

	/*_rc.left -= _test;
	_rc.right -= _test;
	_rc.top -= _test + _xy.x / _xy.x;
	_rc.bottom -= _test + _xy.x / _xy.x;*/

	/*for (int i = 0; i < MAX_WORM; ++i)
	{
		_worm[i].m_rc.left	 -= _test;
		_worm[i].m_rc.right  -= _test;
		_worm[i].m_rc.top	 -= _worm[i].m_xy.y / (_worm[i].m_xy.x + _test) * 2;
		_worm[i].m_rc.bottom -= _worm[i].m_xy.y / (_worm[i].m_xy.x + _test) * 2;

	}*/
	
	
	// 방향키로 각도 조절
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_theta += 5;
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_theta -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		//
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		//
	}
}

void WormGame::render(HDC hdc)
{
	HDC memDC = this->getBackBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =====================================================================
	
	
	// 각도 표시
	char test[128];
	wsprintf(test, "%d", _theta);
	TextOut(memDC, 10, 10, test, strlen(test));

	// 테스트
	DrawEllipseMake(memDC, _rc);

	// 지렁이
	for (int i = 0; i < MAX_WORM; ++i)
	{
		DrawEllipseMake(memDC, _worm[i].m_rc);
	}


	this->getBackBuffer()->render(hdc, 0, 0);

}
