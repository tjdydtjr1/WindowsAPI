#pragma once
class Racing
{
private:
	RECT _player;

	int	   	 _speed;
	bool 	 _isDie;
	bool	 _isSkill;
	int		 _score;

public:
	void setSpeed(int speed) { _speed = speed; }
	int getSpeed() { return _speed; }
	void setDie(bool die) { _isDie = die; }
	bool getDie() { return _isDie; }
	void setScore(int score) { _score = score; }
	int getScore() { return _score; }
	void setSkill(bool skill) { _isSkill = skill; }
	bool getSkill() { return _isSkill; }

	void setPlayerBox(int x, int y)
	{
		_player = RectMake(x, y, 100, 100);
	}
	RECT getPlayerBox() { return _player; }

	// 충돌 체크
	bool collisionCheck(RECT* rc1, RECT* rc2)
	{
		RECT temp;
		return IntersectRect(&temp, rc1, rc2);
	}

	// 방어막
	bool absolute(RECT* rc)
	{
		if (_isDie)
		{
			_isDie = false;
		}
	}

	// 홍해가르기
	RECT* carDivide(RECT* rc)
	{
		if (WINSIZE_X / 2 < rc->right)
		{
			rc->left = 100;
			rc->right = rc->left + 100;
		}
		else if (WINSIZE_X / 2 > rc->right)
		{
			rc->left = WINSIZE_X - 200;
			rc->right = rc->left + 100;
		}

		return rc;
	}

	void printSpeedLine(HDC hdc)
	{
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		hPen = (HPEN)::SelectObject(hdc, hPen);
		LineMake(hdc, 100, WINSIZE_Y - 85,
			cosf((_speed - 210) * PI / 180.0f) * 70 + 100,
			sinf((_speed - 210) * PI / 180.0f) * 70 + (WINSIZE_Y - 85));
		DeleteObject(hPen);
	}
	
	Racing()
		: _player{0}
		, _speed(0)
		, _isDie(false)
		, _isSkill(false)
		, _score(0)
	{}
	~Racing() {}

};

class Enemy
{
	RECT _enemy;
public:
	void setEnemyBox(int x, int y)
	{
		_enemy = RectMake(x, y, 100, 100);
	}

	RECT getEnemyBox() { return _enemy; }


	Enemy()
		: _enemy{0}
	{}
	~Enemy() {}

};