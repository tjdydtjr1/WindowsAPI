#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)
#include "MoleGame.h"
#include "Example_Mole.h"

class MainGame : public GameNode
{
private:
	// ==============================================
	//MoleGame* _mole;
	// ==============================================
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {  }
	~MainGame() {  }

};

