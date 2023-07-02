#pragma once

// ���, �̵�, ����, ���� ��� �ִ� ���
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

