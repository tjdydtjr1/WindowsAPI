#include "Stdafx.h"
#include "Bullet.h"


HRESULT Bullet::init(void)
{
	GameNode::init();


	return S_OK;
}

void Bullet::release(void)
{
	GameNode::release();
}

void Bullet::update(void)
{
	GameNode::update();
}

void Bullet::render(HDC hdc)
{
}
