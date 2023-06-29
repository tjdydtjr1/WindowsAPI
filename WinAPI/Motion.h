#pragma once
#include "GameNode.h"

enum EMotion
{
	MOVE = 1,
	OUTER,
	STING,
	QUICKSTING,
	DIAGONALSTING,
	JUMP,
	CL,
};

class Motion : public GameNode
{

	// 프레임 이미지
	GImage* _bgImage;
	// 스타트
	GImage* _startImage;
	// 좌우 이동
	GImage* _move;
	// 겉옷 
	GImage* _outer;
	// 찌르기
	GImage* _sting;
	// 빠르게 찌르기
	GImage* _quickSting;
	// 대각선 찌르기
	GImage* _diagonalSting;

	// 점프 공격
	GImage* _jump;

	// 클라이막스
	GImage* _cl;

	char text[128];

	bool _isStart;
	RECT _startBox;

	RECT _moveBox;
	RECT _outerBox;
	RECT _stingBox;
	RECT _quickStingBox;
	RECT _diagonalStingBox;
	RECT _jumpBox;
	RECT _clBox;
	
	// 알파 값
	int _alphaA;
	// 프레임 돌릴 카운트
	int _count;
	// 프레임 이미지 인덱스
	int _index;
	// 왼쪽 체크
	bool _isLeft;

	bool _isAlphaIncrese;

	int _outerCount;
	int _stingCount;
	int _quickStingCount;
	int _diagonalStingCount;
	int _jumpCount;
	int _clCount;

	// 스위치용
	int _motion;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Motion() {}
	~Motion() {}

};

