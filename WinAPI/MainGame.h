#pragma once
#include "GameNode.h"
#include "Ryno.h"
// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)

enum class Vec
{
	UP,			// 위
	DOWN,		// 아래
	LEFT,		// 좌
	RIGHT		// 우
};

enum class State
{

	STAY,		// 대기
	MOVE,		// 이동
	RUN,		// 달리기
	JUMP,		// 점프
	WALL,		// 벽잡기
	ATTACK,		// 공격
	SKILL		// 스킬
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

