#pragma once
#include "GameNode.h"


enum CURRENT_RECT
{
	CURRENT_RECT_A, CURRENT_RECT_B,
	CURRENT_RECT_C, CURRENT_RECT_D,
	CURRENT_RECT_E, CURRENT_RECT_F,
	CURRENT_RECT_G, CURRENT_RECT_H,
	CURRENT_RECT_NULL
};

class Example_Mole : public GameNode
{
private:
	CURRENT_RECT _currentRect;
	// 공통된것 아니면 따로 둬서 코드의 가독성을 늘린다.
	RECT _rc[8];
	int _index;				// 두더지 인덱스
	int _count;				// 타이머용 카운트
	int _time;				// 랜덤시간 변수
	int _score;				// 점수

	bool _bIsSelected;
	bool _bIsOnceCheck;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Example_Mole() {}
	~Example_Mole() {}

};

