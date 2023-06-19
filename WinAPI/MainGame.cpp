#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();

	// ===================================================================================
	// 객체 생성
	//_mole = new MoleGame;

	// 기본 좌표값 세팅
	//_mole->setRect(100, 100);
	// ===================================================================================

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	// ===================================================================================

	// 객체 할당 해제
	//SAFE_DELETE(_mole);
	// ===================================================================================

}

void MainGame::update(void)
{
	GameNode::update();
}

void MainGame::render(HDC hdc)
{
	// ===================================================================================

	//// 점수판
	//_mole->setScore(_mole->getScore());
	//_mole->printScore(hdc);

	//// 기본 사각형 틀 생성
	//_mole->printBaseGame(hdc);
	//
	//// 보류
	////_mole->printRect(hdc, 9);

	//// 나올 위치 원 생성
	//_mole->printEllipse(hdc);

	//if (!_mole->getState())
	//{
	//	_mole->printMole(hdc);
	//}
	//
	// ===================================================================================

}

