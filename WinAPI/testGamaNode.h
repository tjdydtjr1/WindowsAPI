#pragma once
class testGamaNode
{
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);


	LRESULT WinProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	testGameNode() {}
	~testGameNode() {}


};

