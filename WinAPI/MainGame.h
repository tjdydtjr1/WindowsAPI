#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)
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

