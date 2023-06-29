#pragma once
#include "GameNode.h"
class ZeroAttack : public GameNode
{
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

	ZeroAttack() {}
	~ZeroAttack() {}

};

