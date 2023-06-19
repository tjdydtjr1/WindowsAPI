#pragma once
#include "GameNode.h"


enum CURRENT_RECT
{
	CURRENT_RECT_A, CURRENT_RECT_B,
	CURRENT_RECT_C, CURRENT_RECT_D,
	CURRENT_RECT_E, CURRENT_RECT_F,
	CURRENT_RECT_G, CURRENT_RECT_H,
	CURRENT_RECT_NULL
};

class Example_Mole : public GameNode
{
private:
	CURRENT_RECT _currentRect;
	// ����Ȱ� �ƴϸ� ���� �ּ� �ڵ��� �������� �ø���.
	RECT _rc[8];
	int _index;				// �δ��� �ε���
	int _count;				// Ÿ�̸ӿ� ī��Ʈ
	int _time;				// �����ð� ����
	int _score;				// ����

	bool _bIsSelected;
	bool _bIsOnceCheck;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Example_Mole() {}
	~Example_Mole() {}

};

