#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();

	// ===================================================================================
	// ��ü ����
	//_mole = new MoleGame;

	// �⺻ ��ǥ�� ����
	//_mole->setRect(100, 100);
	// ===================================================================================

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	// ===================================================================================

	// ��ü �Ҵ� ����
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

	//// ������
	//_mole->setScore(_mole->getScore());
	//_mole->printScore(hdc);

	//// �⺻ �簢�� Ʋ ����
	//_mole->printBaseGame(hdc);
	//
	//// ����
	////_mole->printRect(hdc, 9);

	//// ���� ��ġ �� ����
	//_mole->printEllipse(hdc);

	//if (!_mole->getState())
	//{
	//	_mole->printMole(hdc);
	//}
	//
	// ===================================================================================

}

