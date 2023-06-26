#pragma once
#include "GameNode.h"

class SliceGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage _plImage[9];
	RECT _rc[9];
	RECT _switch;


	int _check[9];
	int _idx;
	int _temp;

	int _countA, _countB;
	int _alphaA, _alphaB;
	int _alphaNum;

	bool _isAlphaIncrese;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	SliceGame()
		: _check{0}
	{}
	~SliceGame() {}



};

