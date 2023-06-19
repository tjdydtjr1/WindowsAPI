#pragma once
#include "GameNode.h"

#define OBJECT_MAX 30


class CreditGame : public GameNode
{
	RECT _player[2];
	RECT _object[OBJECT_MAX];
	RECT _startBox;
	bool _die[OBJECT_MAX];
	int _time;
	bool _collision;
	int start;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	CreditGame() {}
	~CreditGame() {}
};

