#pragma once
#include "GameNode.h"
// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)
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

