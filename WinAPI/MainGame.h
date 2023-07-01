#pragma once
#include "GameNode.h"
#include "Ryno.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)

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

	int _up;
	int _down;

	int _alphaA;
	int _count;
	bool _isAlphaIncrese;
	int _idxX;
	int _idxY;
	RECT _rc;
	bool _isRynoMove;

	int _upCount;

	RECT _collisionBox;
	RECT _temp;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {  }
	~MainGame() {  }

};

