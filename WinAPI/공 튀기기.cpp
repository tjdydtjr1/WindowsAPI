
#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("공 튀기기");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 전역 변수
static RECT rc = RectMake(100, 100, 200, 200);
static RECT ellipse = RectMake(150, 150, 30, 30);
int speedX = 0;
int speedY = 0;

bool test = false;

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
	while (true)
	{
		// PM_REMOVE = 1을 16진수로 바꿔놓음 int형은 너무 크기 때문
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		
		if (test)
		{
			if (ellipse.bottom < rc.bottom)
			{
				ellipse.left += 1;
				ellipse.right += 1;
				ellipse.top += 1;
				ellipse.bottom += 1;
				InvalidateRect(_hWnd, NULL, true);
				Sleep(10);
			}
		}
		
		else if ()
		{
			ellipse.left -= 1;
			ellipse.right -= 1;
			ellipse.top -= 1;
			ellipse.bottom -= 1;
			InvalidateRect(_hWnd, NULL, true);
			Sleep(10);
		}
		

	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			rc.bottom -= 50;
			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_DOWN:
			rc.bottom += 50;
			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_RIGHT:
			rc.right += 50;
			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_LEFT:
			rc.right -= 50;
			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		default:
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		speedX += 10;
		speedY += 10;

		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_RBUTTONDOWN:
		if (speedX != 0 && speedY != 0)
		{
			speedX -= 10;
			speedY -= 10;
		}
		
		InvalidateRect(hWnd, NULL, true);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		

		DrawRectMake(hdc, rc);
		DrawEllipseMake(hdc, ellipse);
		EndPaint(hWnd, &ps);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

