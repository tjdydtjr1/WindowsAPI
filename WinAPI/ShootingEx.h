#pragma once
#include "GameNode.h"


// 설계 연습
#define BULLET_MAX 5
#define PLAYER_SPEED 5
// 80개의 단일 이미지는 STL X => 애니메이션효과로 인해 텍스처가 많이 들어가면 사용해야한다.
#define ENEMY_MAX 30   
// MAX? => 배열 => STL 사용도 생각하기

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

