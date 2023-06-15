#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("¾ó±¼ ±×¸®±â");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


RECT rc;
POINT xy = { 0 };


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmdShow)
{
	_hInstance = hInstance;

	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		_lpszClass,
		_lpszClass,
		WS_EX_OVERLAPPEDWINDOW,
		400,
		100,
		800,
		800,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL
	);

	ShowWindow(_hWnd, nCmdShow);

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	char text[128];

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		// ¿ÞÂÊ´«
		Ellipse(hdc, 160, 250, 290, 275);
		Arc(hdc, 355, 450, 380, 475, 355, 470, 370, 460);

		// ¿À¸¥ÂÊ ´«
		Ellipse(hdc, 412, 250, 550, 275);
		MoveToEx(hdc, 350, 400, NULL);
		Arc(hdc, 451, 246, 550, 280, 451, 246, 451, 280);
		//Arc(hdc, 550, 280, 498, 246, 509, 273, 498, 246);
		

		// ÄÚ
		Ellipse(hdc, 370, 460, 400, 470);
		Ellipse(hdc, 330, 460, 360, 470);
		LineTo(hdc, 330, 460);
		LineTo(hdc, 330, 470);
		MoveToEx(hdc, 380, 401, NULL);
		LineTo(hdc, 400, 461);


		// À±°û
		MoveToEx(hdc, 100, 342, NULL);
		LineTo(hdc, 114, 473);
		LineTo(hdc, 130, 531);
		LineTo(hdc, 135, 551);
		for (int i = 0; i < 50; ++i)
		{
			LineTo(hdc, 135 + (i / 2), 551 + i);
		}

		LineTo(hdc, 170, 620);
		
		LineTo(hdc, 180, 630);
		LineTo(hdc, 200, 640);
		LineTo(hdc, 220, 645);
		LineTo(hdc, 280, 670);
		LineTo(hdc, 340, 675);
		LineTo(hdc, 360, 670);
		LineTo(hdc, 400, 660);
		LineTo(hdc, 480, 640);
		LineTo(hdc, 550, 600);
		LineTo(hdc, 570, 580);
		LineTo(hdc, 600, 520);
		LineTo(hdc, 610, 450);
		LineTo(hdc, 620, 400);
		LineTo(hdc, 625, 370);
		LineTo(hdc, 636, 297);
		MoveToEx(hdc, 204, 248, NULL);

		for (int i = 0; i < 20; ++i)
		{
			LineTo(hdc, 204 - (i / 5), 250 + i);
		}
		LineTo(hdc, 204, 273);

		MoveToEx(hdc, 238, 248, NULL);
		for (int i = 0; i < 20; ++i)
		{
			LineTo(hdc, 238 + (i / 5), 250 + i);
		}
		LineTo(hdc, 238, 280);

		// ¿À¸¥ÂÊ ´«
		MoveToEx(hdc, 504, 250, NULL);
		LineTo(hdc, 506, 255);
		LineTo(hdc, 507, 257);
		LineTo(hdc, 508, 260);
		LineTo(hdc, 509, 262);
		LineTo(hdc, 508, 264);
		LineTo(hdc, 507, 266);
		LineTo(hdc, 506, 268);
		LineTo(hdc, 505, 275);

		// ¸Ó¸®Ä«¶ô
		MoveToEx(hdc, 100, 50, NULL);
		for(int i = 0; i < 250; i += 10)
		{
			Arc(hdc, 100 + i, 50, 200 + i, 250, 150 + i, 50 , 100 + i, 250 );
		}
		/*for (int i = 0; i < 500; i += 10)
		{
			Arc(hdc, 100 + i % 5, 50 + i / 3, 200 + i % 5, 250 + i / 3,  150 + i % 5, 50 + i / 3, 100 + i % 5, 250 + i / 3 );
		}*/
		for (int i = 250; i < 450; i += 10)
		{
			Arc(hdc, 100 + i, 50, 200 + i, 250, 200 + i, 250, 150 + i, 50);   // 150 50 100 250
		}
		/*for (int i = 250; i < 450; i += 10)
		{
			Arc(hdc, 100 + i % 5, 50 + i / 3, 200 + i % 5, 250 + i / 3, 150 + i % 5, 50 + i / 3, 100 + i % 5, 250 + i / 3);
		}*/

		// ¿ÞÂÊ ±Í
		Arc(hdc, 100, 350, 80, 300, 90, 300, 100, 340);


		// ÀÔ
		Arc(hdc, 300, 580, 450, 620, 300, 620, 450, 620);
		Arc(hdc, 450, 620, 300, 580, 450, 620, 300, 620);
		MoveToEx(hdc, 300, 600, NULL);
		LineTo(hdc, 450, 600);

		MoveToEx(hdc, 234, 651, NULL);
		LineTo(hdc, 234, 800);
		MoveToEx(hdc, 479, 639, NULL);
		LineTo(hdc, 479, 800);


		// ¸¶¿ì½º ÁÂÇ¥
		wsprintf(text, "x : %d , y : %d", xy.x, xy.y);
		TextOut(hdc, 10, 10, text, strlen(text)); 

		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		xy.x = LOWORD(lParam);
		xy.y = HIWORD(lParam);

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
		if (wParam)
		{
			PostMessage(hWnd, WM_DESTROY, 0, 0);
		}
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

