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
	RECT _rc;

	int _countA, _countB;
	int _alphaA, _alphaB;
	int _alphaNum;

	bool _isAlphaIncrese;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {  }
	~MainGame() {  }

};

