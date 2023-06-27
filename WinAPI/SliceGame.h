#pragma once
#include "GameNode.h"

class SliceGame : public GameNode
{
private:
	GImage* _bgImage;
	RECT _rc[9];
	RECT _switch;

	int _check[9];
	int _idx;
	int _temp;

	int _test[9];

	RECT _swapRc;
	int _swap;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	SliceGame()
		: _check{0}
		, _swap(8)
	{}
	~SliceGame() {}



};

