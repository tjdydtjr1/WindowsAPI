#pragma once
#include "GameNode.h"

class SliceGame : public GameNode
{
private:
	GImage* _bgImage;
	RECT _rc[9];
	RECT _result[9];

	int _rndIdx[9];
	int _checkIdx[9];
	int _idx;
	int _temp;

	int _swap;

	int _count;
	int _alpha;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	//bool rectEqual(RECT _rc1, RECT _rc2);


	SliceGame()
		: _rndIdx{0}
		, _swap(8)
		, _count(0)
	{}
	~SliceGame() {}



};

