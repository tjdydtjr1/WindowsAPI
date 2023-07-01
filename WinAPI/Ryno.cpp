#include "Stdafx.h"
#include "Ryno.h"

void Ryno::rynoStay()
{
	//IMAGEMANAGER->addFrameImage("ryno_stay", "Resources/Images/Object/Ryno/ryno_stay_base.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ryno_stay", "Resources/Images/Object/Ryno/test.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
}
	

void Ryno::rynoMove()
{
	IMAGEMANAGER->addFrameImage("ryno_move", "Resources/Images/Object/Ryno/ryno_move_LR.bmp", 600, 100, 6, 2, true, RGB(255, 0, 255));
}

void Ryno::rynoJump()
{
	IMAGEMANAGER->addFrameImage("ryno_wall", "Resources/Images/Object/Ryno/ryno_jump_LR.bmp", 600, 200, 6, 2, true, RGB(255, 0, 255));
}

void Ryno::rynoWall()
{
	IMAGEMANAGER->addFrameImage("ryno_jump", "Resources/Images/Object/Ryno/ryno_wall_LR.bmp", 200, 400, 2, 4, true, RGB(255, 0, 255));

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
