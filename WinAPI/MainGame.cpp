#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);

	_ryno = new Ryno;
	_state = State::STAY;
	
	IMAGEMANAGER->addFrameImage("ryno_stay", "Resources/Images/Object/Ryno/ryno_stay_base.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ryno_move", "Resources/Images/Object/Ryno/ryno_move_LR.bmp", 600, 200, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ryno_wall", "Resources/Images/Object/Ryno/ryno_wall_LR.bmp", 200, 400, 2, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ryno_jump", "Resources/Images/Object/Ryno/ryno_jump_LR.bmp", 600, 200, 6, 2, true, RGB(255, 0, 255));

	_alphaA = 0;
	_isAlphaIncrese = false;
	//_rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 500, 500);
	

	_idxX = 0;
	_isRynoMove = true;
	_vec = Vec::RIGHT;

	_upDown = 0;

	_bottomCollisionBox = RectMake(0, WINSIZE_Y - 100, WINSIZE_X, 100);
	_ryno->_collisionBox = RectMake(0, WINSIZE_Y - 400, 300, 300);
	_wallBox = RectMake(WINSIZE_X / 2 + 200, WINSIZE_Y / 3, 200, 600);

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_ryno);

}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		_state = State::JUMP;

		if (_state == State::WALL)
		{
			if (_ryno->_collisionBox.bottom >= _bottomCollisionBox.top)
			{
				_state = State::JUMP;
			}
			else
			{

			}
		}

	}
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		//if(!(_state == State::JUMP))
		_state = State::MOVE;
		_vec = Vec::LEFT;
		_ryno->_collisionBox.left -= 5;
		_ryno->_collisionBox.right -= 5;

	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		//if (!(_state == State::JUMP))
		_state = State::MOVE;
		_vec = Vec::RIGHT;
		_ryno->_collisionBox.left += 5;
		_ryno->_collisionBox.right += 5;

	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_vec = Vec::UP;

		if (_state == State::WALL)
		{
			_ryno->_collisionBox.bottom -= 2;
			_ryno->_collisionBox.top -= 2;
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vec = Vec::DOWN;
		if (_state == State::WALL)
		{
			_ryno->_collisionBox.bottom += 2;
			_ryno->_collisionBox.top += 2;
		}
	}

	++_count;
	

	/*if (_bottomCollisionBox.top <= _ryno->_collisionBox.bottom)
	{
		_state = State::STAY;
	}*/
	
	switch (_vec)
	{
	case Vec::UP:
		if (_count % 3 == 0)
		{
			++_upDown;
			if (_upDown > 4)
			{
				_upDown = 0;
			}
		}
		break;
	case Vec::DOWN:
		if (_count % 3 == 0)
		{
			--_upDown;
			if (_upDown < 0)
			{
				_upDown = 4;
			}
		}
		break;
	case Vec::LEFT:
		if (_count % 3 == 0)
		{
			--_idxX;
			_idxY = 1;
			if (_idxX < 0)
			{
				_idxX = 6;
			}
		}
		break;
	case Vec::RIGHT:
		if (_count % 3 == 0)
		{
		++_idxX;
		_idxY = 0;

		if (_idxX > 6)
		{
			_idxX = 0;
		}
	}
		break;
	default:
		break;
	}

	switch (_state)
	{
	case State::STAY:
		break;
	case State::MOVE:
		_ryno->rynoMove();
		break;
	case State::RUN:
		break;
	case State::WALL:
		_ryno->rynoWall();

		break;
	case State::JUMP:
		_ryno->rynoJump();
		if (_ryno->_collisionBox.bottom > WINSIZE_Y)
		{
			//_ryno->_collisionBox.top = _bottomCollisionBox.top - 180;
			//_ryno->_collisionBox.bottom = _bottomCollisionBox.top;
			_state = State::STAY;

		}
		else if (IntersectRect(&_temp, &_ryno->_collisionBox, &_wallBox))
		{
			_state = State::WALL;
		}
		/*else if (_upCount >= 0 && _upCount < 100)
		{
			++_upCount;
			_ryno->_collisionBox.top += _upCount;
			_ryno->_collisionBox.bottom += _upCount;
		}
		else if (_upCount > 100)
		{
			--_upCount;
			_ryno->_collisionBox.top += _upCount;
			_ryno->_collisionBox.bottom += _upCount;
		
		}*/
		
		

		break;
	case State::ATTACK:
		break;
	case State::SKILL:
		break;

	default:
		break;
	}


}


void MainGame::render(void)
{
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	
	//IMAGEMANAGER->alphaRender("데스 스페이스", getMemDC(), 0, 0, _alphaA);
	//DrawRectMake(getMemDC(), _rc);
	//IMAGEMANAGER->frameRender("ryno_move", getMemDC(), _ryno->_collisionBox.left , _ryno->_collisionBox.top, _idxX, _idxY , 300, 300);
	
	
	switch (_state)
	{
	case State::STAY:
		_ryno->stayRender(getMemDC(), _idxX, _idxY);
		break;
	case State::MOVE:
		_ryno->moveRender(getMemDC(), _idxX, _idxY);
		break;
	case State::RUN:
		break;
	case State::WALL:
		
		_ryno->wallRender(getMemDC(), 0, _upDown);
		break;
	case State::JUMP:
		_ryno->jumpRender(getMemDC(), _idxX, 0);
		break;
	case State::ATTACK:
		break;
	case State::SKILL:
		break;

	default:
		break;
	}

	DrawRectMake(getMemDC(), _bottomCollisionBox);
	DrawRectMake(getMemDC(), _wallBox);
	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

