#pragma once
#include "GameNode.h"

using std::vector;
class BulletShot : public GameNode
{
private:
	RECT _player[2];
	RECT _bullet;
	vector<RECT> _bulletVec;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	BulletShot() {}
	~BulletShot() {}

};

