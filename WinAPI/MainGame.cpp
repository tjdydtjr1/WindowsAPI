#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
}

void MainGame::update(void)
{
	GameNode::update();

	
}

void MainGame::render(HDC hdc)
{
}
