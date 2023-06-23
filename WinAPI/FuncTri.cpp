#include "Stdafx.h"
#include "FuncTri.h"

HRESULT FuncTri::init(void)
{
	GameNode::init();
	
	_second = 6;

	_sec.x = cosf((_second - 90) * PI / 180.0f) * 250 + WINSIZE_X / 2;
	_sec.y = sinf((_second - 90) * PI / 180.0f) * 250 + WINSIZE_Y / 2;

	_min.x = cosf((_second - 90) * PI / 180.0f) * 170 + WINSIZE_X / 2;
	_min.y = sinf((_second - 90) * PI / 180.0f) * 170 + WINSIZE_Y / 2;

	_h.x = cosf((_second - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_h.y = sinf((_second - 90) * PI / 180.0f) * 100 + WINSIZE_Y / 2;

	_ellipse = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 600, 600);

	return S_OK;
}

void FuncTri::release(void)
{
	GameNode::release();
}

void FuncTri::update(void)
{
	GameNode::update();
	GetLocalTime(&_st);
	_st.wSecond;
	_st.wMinute;
	_st.wHour;

	_second = 6;
	_minute = 6;
	_hour = 6;

	_sec.x = cosf((_st.wSecond * _second - 90) * PI / 180.0f) * 250 + WINSIZE_X / 2;
	_sec.y = sinf((_st.wSecond * _second - 90) * PI / 180.0f) * 250 + WINSIZE_Y / 2;

	_min.x = cosf((_st.wMinute * _minute - 90) * PI / 180.0f) * 170 + WINSIZE_X / 2;
	_min.y = sinf((_st.wMinute * _minute - 90) * PI / 180.0f) * 170 + WINSIZE_Y / 2;

	_h.x = cosf((_st.wHour * _hour - 90) * PI / 180.0f) * 100 + WINSIZE_X / 2;
	_h.y = sinf((_st.wHour * _hour - 90) * PI / 180.0f) * 100 + WINSIZE_Y / 2;
}

void FuncTri::render(HDC hdc)
{
	char text[128];
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
	pen = (HPEN)::SelectObject(hdc, pen);
	

	DrawEllipseMake(hdc, _ellipse);

	pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pen = (HPEN)::SelectObject(hdc, pen);

	LineMake(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, _sec.x, _sec.y);
	LineMake(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, _min.x, _min.y);
	LineMake(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, _h.x, _h.y);
	


	for (int i = 1; i <= 12; ++i)
	{
		wsprintf(text, "%d", i);
		TextOut(hdc, cosf((i * 30 - 90) * PI / 180.0f) * 320 + WINSIZE_X / 2,
			sinf((i * 30 - 90) * PI / 180.0f) * 320 + WINSIZE_Y / 2,text,strlen(text));
	}

	DeleteObject(pen);

}