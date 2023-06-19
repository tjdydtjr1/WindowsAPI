#pragma once
#include "GameNode.h"
class CrocodileGame : public GameNode
{
private:
	RECT _tooth[8];
	int _idx;
	bool _isDie;
	char text[128];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);


	CrocodileGame() {}
	~CrocodileGame() {}

};

