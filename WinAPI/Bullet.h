#pragma once
#include "GameNode.h"

using std::vector;

struct a
{

};

class Bullet : public GameNode
{
private:


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);


	Bullet() {}
	~Bullet() {}

};

