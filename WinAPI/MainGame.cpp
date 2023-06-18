#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

	// ===================================================================================
	// ��ü ����
	_mole = new MoleGame;

	// �⺻ ��ǥ�� ����
	_mole->setRect(100, 100);

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	// ��ü �Ҵ� ����
	SAFE_DELETE(_mole);
}

void MainGame::update(void)
{
	GameNode::update();
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_mole->checkXY(_ptMouse.x, _ptMouse.y);
	}

	/*if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		rc.top -= 3;
		rc.bottom -= 3;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		rc.left -= 3;
		rc.right -= 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		rc.left += 3;
		rc.right += 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		rc.top += 3;
		rc.bottom += 3;

	}*/
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		rc.top -= 3;
		rc.bottom -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		rc.left -= 3;
		rc.right -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		rc.left += 3;
		rc.right += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		rc.top += 3;
		rc.bottom += 3;
	}
}

void MainGame::render(HDC hdc)
{
	// ������
	_mole->setScore(_mole->getScore());
	_mole->printScore(hdc);

	// �⺻ �簢�� Ʋ ����
	_mole->printBaseGame(hdc);
	
	// ����
	//_mole->printRect(hdc, 9);

	// ���� ��ġ �� ����
	_mole->printEllipse(hdc);

	if (!_mole->getState())
	{
		_mole->printMole(hdc);
	}
	

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}


}

