#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)


// ���� ����
// 80���� ���� �̹����� STL X => �ִϸ��̼�ȿ���� ���� �ؽ�ó�� ���� ���� ����ؾ��Ѵ�.
// MAX? => �迭 => STL ��뵵 �����ϱ�

class MainGame : public GameNode
{
private:
	

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {  }
	~MainGame() {  }

};

