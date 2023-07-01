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
	_idxX = 0;
	_rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 500, 500);
	_isRynoMove = true;
	_vec = Vec::RIGHT;

	_up = 0;
	_down = 0;

	_upCount = 0;

	_collisionBox = RectMake(0, WINSIZE_Y - 100, WINSIZE_X, 100);

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
		//_state = State::WALL;

	}
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if(!(_state == State::JUMP))
		_state = State::MOVE;
		_vec = Vec::LEFT;
		_ryno->_collisionBox.left -= 5;
		_ryno->_collisionBox.right -= 5;

	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (!(_state == State::JUMP))
		_state = State::MOVE;
		_vec = Vec::RIGHT;
		_ryno->_collisionBox.left += 5;
		_ryno->_collisionBox.right += 5;

	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_vec = Vec::UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vec = Vec::DOWN;
	}
	

	++_count;
	
	switch (_vec)
	{
	case Vec::UP:
		if (_count % 3 == 0)
		{
			++_up;
			if (_up > 4)
			{
				_up = 0;
			}
		}
		break;
	case Vec::DOWN:
		if (_count % 3 == 0)
		{
			--_up;
			if (_up < 0)
			{
				_up = 4;
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
		if (_ryno->_collisionBox.bottom < WINSIZE_Y)
		{
			_ryno->_collisionBox.top = _collisionBox.top - 180;
			_ryno->_collisionBox.bottom = _collisionBox.top;

		}
		else if (_upCount >= 0 && _upCount < 100)
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
		
		}
		
		

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
		
		_ryno->wallRender(getMemDC(), 0, _up);
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

	//DrawRectMake(getMemDC(), _collisionBox);
	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

