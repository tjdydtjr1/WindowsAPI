#pragma once
#include "GameNode.h"

class Player
{
private:
	// hp
	int _hp;
	// mp
	int _mp;
	// ÃÑ¾Ë ÁÂÇ¥
	POINT _bullet;
	// ÇÃ·¹ÀÌ¾î ÁÂÇ¥
	POINT _player;
	// 
	bool _die;
	
	bool _skillA;
	bool _skillB;

public:
	void setHp(int hp) { _hp = hp; }
	void setMp(int mp) { _mp = mp; }
	void setBulletXY(int x, int y) { _bullet.x = x; _bullet.y = y; }
	void setPlayerXY(int x, int y) { _player.x = x; _player.y = y; }
	void setDie(bool die) { _die = die; }
	void setSkillA(bool skill) { _skillA = skill; }
	void setSkillB(bool skill) { _skillB = skill; }

	int getHp() { return _hp; }
	int getMp() { return _mp; }
	POINT getBulletXY() { return _bullet; }
	POINT getPlayerXY() { return _player; }
	bool getDie() { return _die; }
	bool getSkillA() { return _skillA; }
	bool getSkillB() { return _skillB; }

	Player()
		: _hp(3)
		, _mp(0)
		, _bullet{0}
		, _player{0}
		, _die(false)
		, _skillA(false)
		, _skillB(false)
	{}
	~Player() {}
};

class ShootingGame : public GameNode
{
private:
	Player _playerA;
	Player _playerB;

	RECT _playerBoxA[3];
	RECT _playerBoxB[3];
	
	RECT _hpBar[2];
	RECT _mpBar[2];
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	ShootingGame() {}
	~ShootingGame() {}

};

