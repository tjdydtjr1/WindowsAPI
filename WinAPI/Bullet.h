#pragma once
#include "GameNode.h"

#define MAX_BULLET 100
#define PI		3.1415926535f
#define MOVE_SPEED 3


struct bullet
{
	RECT rc;
	bool fire;
	POINT xy;
	int r;
};

class Bullet : public GameNode
{
private:
	POINT _berral;
	bullet _bullet[MAX_BULLET];
	int _theta;
	int _speed;
	int _idx;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void fireBullet();

	Bullet() {}
	~Bullet() {}

};

