#pragma once
#include "GameNode.h"
// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)

#define _USE_MATH_DEFINES	// math헤더가 무겁기 때문에 쓸만한것만 가져온다.
#include <math.h>
// 상수화
#define PI 3.1415926535f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)


class MainGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;

	// 프레임 이미지
	GImage* Attack_1;
	GImage* Attack_2;
	GImage* Attack_3;


	RECT _rc;
	// 알파 값
	int _alphaA;
	// 프레임 돌릴 카운트
	int _count;
	// 프레임 이미지 인덱스
	int _index;
	// 왼쪽 체크
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

