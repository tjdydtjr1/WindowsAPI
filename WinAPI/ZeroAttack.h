#pragma once
#include "GameNode.h"
class ZeroAttack : public GameNode
{
	// ������ �̹���
	GImage* Attack_1;
	GImage* Attack_2;
	GImage* Attack_3;


	RECT _rc;
	// ���� ��
	int _alphaA;
	// ������ ���� ī��Ʈ
	int _count;
	// ������ �̹��� �ε���
	int _index;
	// ���� üũ
	bool _isLeft;

	bool _isAlphaIncrese;

	int _motion;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	ZeroAttack() {}
	~ZeroAttack() {}

};

