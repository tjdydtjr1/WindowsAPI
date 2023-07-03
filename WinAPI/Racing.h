#pragma once

#define BASE_SPEED 5
#define ENEMY_MAX 5



class Racing
{
private:
	RECT _player;

	int	   	 _speed;
	bool 	 _isDie;
	bool	 _isSkill;

public:
	void setSpeed(int speed) { _speed = speed; }
	int getSpeed() { return _speed; }
	void setDie(bool die) { _isDie = die; }
	bool getDie() { return _isDie; }
	void setSkill(bool skill) { _isSkill = skill; }
	bool getSkill() { return _isSkill; }

	void setPlayerBox(int left, int right)
	{
		_player.left = left;
		_player.right = right;
	}

	RECT getPlayerBox() { return _player; }

	// 충돌 체크
	bool collisionCheck(RECT* rc1, RECT* rc2)
	{
		RECT temp;
		return IntersectRect(&temp, rc1, rc2);
	}

	// 방어막
	void absolute(HDC hdc, RECT rc)
	{
		DrawEllipseMake(hdc, rc);
		if (_isDie)
		{
			_isDie = false;
		}
	}

	// 홍해가르기
	RECT carDivide(RECT rc)
	{
		if (WINSIZE_X / 2 < rc.right)
		{
			rc.left = 100;
			rc.right = rc.left + 100;
		}
		else if (WINSIZE_X / 2 > rc.right)
		{
			rc.left = WINSIZE_X - 200;
			rc.right = rc.left + 100;
		}
		
		return rc;
	}

	void printSpeedLine(HDC hdc)
	{
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		hPen = (HPEN)::SelectObject(hdc, hPen);
		LineMake(hdc, 125, WINSIZE_Y - 85,
			cosf((_speed - 210) * PI / 180.0f) * 70 + 125,
			sinf((_speed - 210) * PI / 180.0f) * 70 + (WINSIZE_Y - 85));
		DeleteObject(hPen);
	}
	
	Racing()
		: _player{0}
		, _speed(0)
		, _isDie(false)
		, _isSkill(false)
	{
		_player = RectMake(WINSIZE_X / 2, WINSIZE_Y - 100, 100, 100);
	}
	~Racing() {}

};

class Enemy
{
private:
	RECT _enemy[ENEMY_MAX];
	bool _isCreate;

public:
	void setCreate(bool create) { _isCreate = create; }
	bool getCreate() { return _isCreate; }

	void setEnemyBox(int left, int top, int idx)
	{
		_enemy[idx] = RectMake(left, top, 100, 100);
	}

	void setMoveBox(int top, int bottom, int idx)
	{
		_enemy[idx].top = top;
		_enemy[idx].bottom = bottom;
	}

	RECT getEnemyBox(int idx) { return _enemy[idx]; }


	Enemy()
		: _enemy{0}
	{}
	~Enemy() {}

};