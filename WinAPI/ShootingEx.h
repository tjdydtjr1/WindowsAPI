#pragma once
#include "GameNode.h"


// ���� ����
#define BULLET_MAX 5
#define PLAYER_SPEED 5
// 80���� ���� �̹����� STL X => �ִϸ��̼�ȿ���� ���� �ؽ�ó�� ���� ���� ����ؾ��Ѵ�.
#define ENEMY_MAX 30   
// MAX? => �迭 => STL ��뵵 �����ϱ�

struct tagBullet
{
	RECT rc;
	bool fire;
};

struct tagEnemy
{
	RECT rc;
	int speed;
	bool die;
};

class ShootingEx : public GameNode
{
private:
	tagBullet _bullet[BULLET_MAX];
	tagEnemy _enemy[ENEMY_MAX];

	RECT _playerRc;
	RECT _hpBox;
	int _hp;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);


	void fireBullet(void);
	bool collisionCheck(RECT rc1, RECT rc2);

	ShootingEx() {}
	~ShootingEx() {}

};

