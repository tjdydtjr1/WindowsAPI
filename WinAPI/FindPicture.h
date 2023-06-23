#pragma once
#include "GameNode.h"

class FindPicture : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plgImage;
	GImage* _plgImageA;

	RECT _rc;
	RECT _timeBar;
	RECT _findPicture[5];
	int _time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	FindPicture() {}
	~FindPicture() {}

};

