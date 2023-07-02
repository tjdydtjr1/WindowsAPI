#pragma once
#include "GameNode.h"
#include "Ryno.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)

#define GRAVITY -10.0f

enum class Vec
{
	UP,			// ��
	DOWN,		// �Ʒ�
	LEFT,		// ��
	RIGHT		// ��
};

enum class State
{

	STAY,		// ���
	MOVE,		// �̵�
	RUN,		// �޸���
	JUMP,		// ����
	WALL,		// �����
	ATTACK,		// ����
	SKILL		// ��ų
};

class MainGame : public GameNode
{
private:
	Ryno* _ryno;
	State _state;
	Vec _vec;


	int _alphaA;
	bool _isAlphaIncrese;
	
	int _upDown;
	int _count;
	int _idxX;
	int _idxY;
	RECT _rc;
	bool _isRynoMove;


	RECT _bottomCollisionBox;
	RECT _wallBox;

	RECT _temp;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {  }
	~MainGame() {  }

};

