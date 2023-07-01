#pragma once

// 대기, 이동, 점프, 벽을 잡고 있는 모션
class Ryno
{
public:
	RECT _collisionBox;
	int _moveSpeed;
	int _jumpSpeed;

public:
	void rynoStay();
	void rynoMove();
	void rynoJump();
	void rynoWall();
	void rynoSkill();

	void stayRender(HDC hdc, int frameX, int frameY);
	void moveRender(HDC hdc, int frameX, int frameY);
	void wallRender(HDC hdc, int frameX, int frameY);
	void jumpRender(HDC hdc, int frameX, int frameY);

	Ryno() 
	{
		_collisionBox = RectMakeCenter(WINSIZE_X / 4, WINSIZE_Y / 2, 300, 300);
		_moveSpeed = 5;
		_jumpSpeed = 5;
	}
	~Ryno() {}

};

