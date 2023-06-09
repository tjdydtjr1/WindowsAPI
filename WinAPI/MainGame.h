#pragma once
#include "GameNode.h"
// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)
#include "StartScene.h"
#include "SecondScene.h"


class MainGame : public GameNode
{
private:
	StartScene* _start;
	SecondScene* _second;

	GameNode* _currentScene;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame()
		: _currentScene(nullptr)
	{
	}
	~MainGame() {  }

};

