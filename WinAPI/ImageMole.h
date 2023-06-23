#pragma once
#include "GameNode.h"

#define MOLE_ARR 9
#define TEXT_MAX 255

class ImageMole : public GameNode
{
private:
	RECT _rc[MOLE_ARR];
	POINT _mouseXY;
	bool _state;
	char _text[TEXT_MAX];
	int _score;
	int _idx;
	GImage* _bgImage;
	GImage* _moleImage;

	


public:
	// 게임 기본틀 생성
	void printBaseGame(HDC hdc);
	// Rect 좌표 세팅
	void setRect(int startX, int startY);

	// Rect 배열 좌표 가져오기
	RECT getRect(int idx) { return _rc[idx]; }

	// 점수 설정
	//void setScore(int score) { _score = score; }
	void setScore(int score) { _score = score; }
	int getScore() { return _score; }
	void printScore(HDC hdc)
	{
		wsprintf(_text, "Score : %d", _score);
		TextOut(hdc, 600, 10, _text, strlen(_text));
	}


	// 상태값 설정하기 ( 마우스 충돌 체크)
	void setState(bool state) { _state = state; }
	// 상태값 가져오기
	bool getState() { return _state; }

	// 사각형 충돌체범위와 마우스 좌표 범위
	bool checkXY(long mouseX, long mouseY);

	// 기본 Rect 배치
	void printRect(HDC hdc);
	// 기본 타원 배치
	void printEllipse(HDC hdc);

	// 랜덤하게 나올 위치
	void printMole(HDC hdc);
	
	
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	ImageMole()
		: _state(false)
		, _text{ 0 }
		, _score(0) 
	{}
	~ImageMole() {}

};

