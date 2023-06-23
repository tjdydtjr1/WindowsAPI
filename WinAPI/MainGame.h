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


struct STAR
{
	int x;
	int y;
};

class MainGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plgImage;
	GImage* _plgImageA;
	
	RECT _rc;

	float _radian;
	float _degree;

	// 시간 관련 구조체
	SYSTEMTIME _st;
	HPEN _currentStarPen;
	STAR _star[5];
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {  }
	~MainGame() {  }

};

