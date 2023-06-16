#pragma once

#define MOLE_ARR 9

class MoleGame
{
private:
	RECT _rc[MOLE_ARR];
	POINT _mouseXY;
	bool _state;
public:
	// Rect ��ǥ ����
	void setRect(RECT* rc, int startX, int startY);
	
	// Rect �迭 ��ǥ ��������
	RECT getRect(int idx) { return _rc[idx]; }
	

	void setState(bool state) { _state = state; }
	bool getState() { return _state; }

	bool checkXY(RECT* rc, int mouseX, int mouseY);

	// �⺻ Rect ��ġ
	void printRect(HDC hdc, RECT* rc, int n);
	// �⺻ Ÿ�� ��ġ
	void printEllipse(HDC hdc, RECT* rc, int n);
	
	MoleGame() {}
	~MoleGame() {}

};

