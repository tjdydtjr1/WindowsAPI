#pragma once
#include "GameNode.h"

class MiniMap : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _miniMap;
	RECT _rc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);



	MiniMap(){}
	~MiniMap() {}

};

