#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)

#define _USE_MATH_DEFINES	// math����� ���̱� ������ �����Ѱ͸� �����´�.
#include <math.h>
// ���ȭ
#define PI 3.1415926535f

// ���� ǥ�� -> ���� ǥ�� ��ȯ
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)


class MainGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;

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

	MainGame() {  }
	~MainGame() {  }

};

