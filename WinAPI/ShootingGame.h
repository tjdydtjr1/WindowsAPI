#pragma once
#include "GameNode.h"

#define VK_WKEY 0x57
#define VK_SKEY 0x53
#define PLAYER_SPEED 5


struct _tagBullet
{
	RECT rc;
	bool fire;
};

class Player
{
private:
	// hp
	int _hp;
	// mp
	int _mp;
	// 플레이어 좌표
	POINT _player;
	// 
	bool _die;
	bool _fire;
	bool _skillA;
	bool _skillB;

public:
	void setHp(int hp) { _hp = hp; }
	void setMp(int mp) { _mp = mp; }
	void setFire(bool fire) { _fire = fire; }
	void setPlayerXY(int x, int y) { _player.x = x; _player.y = y; }
	void setDie(bool die) { _die = die; }
	void setSkillA(bool skill) { _skillA = skill; }
	void setSkillB(bool skill) { _skillB = skill; }

	int getHp() { return _hp; }
	int getMp() { return _mp; }
	POINT getPlayerXY() { return _player; }
	bool getFire() { return _fire; }
	bool getDie() { return _die; }
	bool getSkillA() { return _skillA; }
	bool getSkillB() { return _skillB; }

	Player()
		: _hp(3)
		, _mp(0)
		, _player{0}
		, _fire(false)
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
	
	_tagBullet _bulletA[5];
	_tagBullet _bulletB[5];

	RECT _hpBar[2];
	RECT _mpBar[2];
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);


	void fireBulletA(void);
	void fireBulletB(void);

	bool collisionCheck(RECT rc1, RECT rc2);

	ShootingGame() {}
	~ShootingGame() {}

};

