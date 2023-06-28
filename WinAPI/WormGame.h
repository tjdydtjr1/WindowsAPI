#pragma once
#include "GameNode.h"

#define MAX_WORM 50
#define PI 3.14159265358979f
#define MOVE_SPEED 10


//struct Worm
//{
//	// 시작위치
//	int m_startX;
//	int m_startY;
//	// 방향바꾸기 전 마지막 위치
//	int m_destX;
//	int m_destY;
//	// 진행 각도
//	int m_degreeX;
//	int m_degreeY;
//	// 인덱스 넘버
//	int m_idx;
//	// 몸체 생성
//	RECT m_rc;
//	// 방향이 바뀌었는지
//	bool isKeyInput;
//
//};

struct Worm
{
	RECT m_rc;
	POINT m_xy;
};


class WormGame : public GameNode
{
private:
	GImage* _bgImage;
	Worm _worm[MAX_WORM];

	RECT _rc;
	POINT _xy;
	int _theta;
	int _test;

	
	POINT _speed;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
};

