#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES	// math헤더가 무겁기 때문에 쓸만한것만 가져온다.
#include <math.h>
// 상수화
#define PI 3.1415926535f

// 각도 표기 -> 라디안 표기 변환
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

