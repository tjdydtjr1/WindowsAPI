#include "Stdafx.h"
#include "Ryno.h"

void Ryno::rynoStay()
{
}
	

void Ryno::rynoMove()
{
}

void Ryno::rynoJump()
{
}

void Ryno::rynoWall()
{

}

void Ryno::rynoSkill()
{

}

void Ryno::stayRender(HDC hdc, int frameX, int frameY)
{
	IMAGEMANAGER->frameRender("ryno_stay", hdc, _collisionBox.left, _collisionBox.top, frameX, frameY, 300, 300);
}

void Ryno::moveRender(HDC hdc, int frameX, int frameY)
{
	
	IMAGEMANAGER->frameRender("ryno_move", hdc, _collisionBox.left, _collisionBox.top, frameX, frameY, 300, 300);

}

void Ryno::wallRender(HDC hdc, int frameX, int frameY)
{
	IMAGEMANAGER->frameRender("ryno_wall", hdc, _collisionBox.left, _collisionBox.top, frameX, frameY, 300, 300);
}

void Ryno::jumpRender(HDC hdc, int frameX, int frameY)
{
	IMAGEMANAGER->frameRender("ryno_jump", hdc, _collisionBox.left, _collisionBox.top, frameX, frameY, 300, 300);
}
