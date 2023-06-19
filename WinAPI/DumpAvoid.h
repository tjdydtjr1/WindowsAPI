#pragma once
#include "GameNode.h"

#define OBJECT_MAX 30


class DumpAvoid : public GameNode
{
	RECT _player[2];
	RECT _object[OBJECT_MAX];
	RECT _startBox;
	POINT _arrow[3];
	bool _isDie;
	int _time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	DumpAvoid() {}
	~DumpAvoid() {}
};

