#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)


class MainGame : public GameNode
{
private:
	int _alphaA;
	int _count;
	bool _isAlphaIncrese;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {  }
	~MainGame() {  }

};

