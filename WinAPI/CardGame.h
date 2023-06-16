#pragma once
#include "GameNode.h"

class CardGame : public GameNode
{
private:
	int m_dia[10];
	int m_space[10];
	RECT rc[20];
	bool m_check;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void setCheck(bool check) { m_check = check; }
	bool getCheck() { return m_check; }
	// 카드 좌표
	void setRect(RECT* rc, int n , int x, int y);

	// 카드 생성
	void printRect(HDC hdc, RECT* rc, int n);
	void printText(HDC hdc, RECT* rc, int n);
	// 
	void checkCard(HDC hdc, RECT rc, int mouseX, int mouseY);
	CardGame() {};
	~CardGame() {};

};

