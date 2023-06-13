
#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

RECT rc = { 0 };
RECT rc2 = { 0 };
POINT mousePT = { 0,0 };
POINT movePT = { 0,0 };
bool bLButton = false;

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
	wndClass.lpszClassName = WINMYNAME("사각형 드래그 이동");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		WINMYNAME("사각형 드래그 이동"),
		WINMYNAME("사각형 드래그 이동"),
		WS_EX_OVERLAPPEDWINDOW,
		WINSTART_X,
		WINSTART_Y,
		WINSIZE_X,
		WINSIZE_Y,
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
	char mouseXY[128];

	switch (iMessage)
	{
	case WM_CREATE:
		rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		wsprintf(mouseXY, "X 좌표 : %d   Y 좌표 : %d   LBUTTON : %d", mousePT.x, mousePT.y,bLButton);
		TextOut(hdc, 10, 10, mouseXY, strlen(mouseXY));
		DrawRectMake(hdc, rc);

		EndPaint(hWnd, &ps);
		break;
		
	case WM_MOUSEMOVE:
		// 마우스 좌표 갱신
		mousePT.x = LOWORD(lParam);
		mousePT.y = HIWORD(lParam);

		if (bLButton)
		{
			// 이동할 사각형 좌표 변경
			rc.left = rc2.left + (mousePT.x - movePT.x);
			rc.right = rc2.right + (mousePT.x - movePT.x);
			rc.top = rc2.top + (mousePT.y - movePT.y);
			rc.bottom = rc2.bottom + (mousePT.y - movePT.y);
		}

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_LBUTTONDOWN:
	
		if (!bLButton)
		{
			// 현재 마우스 좌표 저장
			movePT.x = mousePT.x;
			movePT.y = mousePT.y;
			
			// 현재 사각형 좌표 저장
			rc2.left = rc.left;
			rc2.top = rc.top;
			rc2.right = rc.right;
			rc2.bottom = rc.bottom;
		}

		if (rc.left < mousePT.x && rc.right > mousePT.x
			&& rc.top < mousePT.y && rc.bottom > mousePT.y)
		{
			bLButton = true;
		}
		
		break;
	case WM_LBUTTONUP:
		bLButton = false;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_KEYDOWN:
	{
	case VK_ESCAPE:
		PostMessage(hWnd, WM_DESTROY, 0, 0);
		break;
	}
	break;
	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

