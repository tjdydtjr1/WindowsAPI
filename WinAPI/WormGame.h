#pragma once
#include "GameNode.h"

#define MAX_WORM 50
#define PI 3.14159265358979f
#define MOVE_SPEED 10


//struct Worm
//{
//	// ������ġ
//	int m_startX;
//	int m_startY;
//	// ����ٲٱ� �� ������ ��ġ
//	int m_destX;
//	int m_destY;
//	// ���� ����
//	int m_degreeX;
//	int m_degreeY;
//	// �ε��� �ѹ�
//	int m_idx;
//	// ��ü ����
//	RECT m_rc;
//	// ������ �ٲ������
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

