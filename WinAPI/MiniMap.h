#pragma once
#include "GameNode.h"

#define MOVE_SPEED 4.0f

class MiniMap : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _miniMap;
	GImage* _testImage;


	RECT _rc;
	RECT _miniRc;

	RECT _testRc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);



	MiniMap(){}
	~MiniMap() {}

};

