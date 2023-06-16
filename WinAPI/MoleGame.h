#pragma once

#define MOLE_ARR 9

class MoleGame
{
private:
	RECT _rc[MOLE_ARR];
	POINT _mouseXY;
	bool _state;
public:
	// Rect 좌표 세팅
	void setRect(RECT* rc, int startX, int startY);
	
	// Rect 배열 좌표 가져오기
	RECT getRect(int idx) { return _rc[idx]; }
	

	void setState(bool state) { _state = state; }
	bool getState() { return _state; }

	bool checkXY(RECT* rc, int mouseX, int mouseY);

	// 기본 Rect 배치
	void printRect(HDC hdc, RECT* rc, int n);
	// 기본 타원 배치
	void printEllipse(HDC hdc, RECT* rc, int n);
	
	MoleGame() {}
	~MoleGame() {}

};

