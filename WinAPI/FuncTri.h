#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES	// math����� ���̱� ������ �����Ѱ͸� �����´�.
#include <math.h>
// ���ȭ
#define PI 3.1415926535f

// ���� ǥ�� -> ���� ǥ�� ��ȯ
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)


struct SEC
{
	int x;
	int y;
};


class FuncTri : public GameNode
{
	float _radian;
	float _degree;

	RECT _ellipse;
	SEC _sec;
	SEC _min;
	SEC _h;
	SYSTEMTIME _st;

	int _seta;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	FuncTri() {}
	~FuncTri() {}

};

