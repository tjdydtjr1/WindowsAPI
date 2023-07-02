#pragma once

// 대기, 이동, 점프, 벽을 잡고 있는 모션
class Ryno
{
public:
	RECT _collisionBox;

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

	Ryno() {}
	~Ryno() {}

};

