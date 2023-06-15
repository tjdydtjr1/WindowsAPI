#pragma once
#include "GameNode.h"

class CardGame : public GameNode
{
private:
	int m_dia[10];
	int m_space[10];
	RECT rc[20];
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void setRect(RECT* rc, int n , int x, int y);
	void printRect(HDC hdc, RECT* rc, int n);
	void checkCard(RECT* rc, int x, int y);

	CardGame() {};
	~CardGame() {};

};

