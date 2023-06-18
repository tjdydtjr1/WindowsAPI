#pragma once

#define MOLE_ARR 9
#define TEXT_MAX 128

class MoleGame
{
private:
	RECT _rc[MOLE_ARR];
	POINT _mouseXY;
	bool _state;
	char _text[TEXT_MAX];
public:
	// 게임 기본틀 생성
	void printBaseGame(HDC hdc);
	// Rect 좌표 세팅
	void setRect(int startX, int startY);

	// Rect 배열 좌표 가져오기
	RECT getRect(int idx) { return _rc[idx]; }
	
	// 점수 설정
	void setScore(int score) { wsprintf(_text, "Score : %d", score); }
	char* getScroe() { return _text; }
	
	// 상태값 설정하기 ( 마우스 충돌 체크)
	void setState(bool state) { _state = state; }
	// 상태값 가져오기
	bool getState() { return _state; }

	// 사각형 충돌체범위와 마우스 좌표 범위
	bool checkXY(int mouseX, int mouseY);

	// 기본 Rect 배치
	void printRect(HDC hdc);
	// 기본 타원 배치
	void printEllipse(HDC hdc);

	// 랜덤하게 나올 위치
	void printMole(HDC hdc);
	
	MoleGame()
		: _state(false)
	{}
	~MoleGame() {}

};

/*
state = false
random => 3초마다 true로 변경

-> true상태일 때 마우스 클릭 가능
기본 사각형 충돌체 각 좌표 = 마우스 xy 좌표 같으면
-> 상태값 변경 => state = false

기본틀 사각형 -> 원으로 표시 -> true일때 색상 변경



*/