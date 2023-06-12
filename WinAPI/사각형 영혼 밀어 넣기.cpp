
#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("06.12 과제 : 사각형 영혼 밀어 넣기 ");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 전역 변수


RECT rcA;
RECT rcB;
RECT rcC;

bool rect = true;

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

	switch (iMessage)
	{
	case WM_CREATE:
		rcA = RectMake(100, 200, 100, 100);
		rcB = RectMake(400, 200, 100, 100);
		//rcC = RectInnerCenter(&rcA, &rcA, 50, 50);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		if (rect)
		{
			rcC = RectMakeCenter(rcA.left + 50 , rcA.top + 50, 50, 50);
		}
		else if (rect == false)
		{
			rcC = RectMakeCenter(rcB.left + 50, rcB.top + 50, 50, 50);
		}
		DrawRectMake(hdc, rcA);
		DrawRectMake(hdc, rcB);
		DrawRectMake(hdc, rcC);

		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			
			if (rect)
			{
				if (rcA.top <= rcB.bottom
					&& rcA.left < rcB.right
					&& rcA.right > rcB.left
					&& rcA.bottom >= rcB.top)
				{
					rect = false;
					rcA.top += 15;
					rcA.bottom += 15;
				}
				else
				{
					rcA.top += -5;
					rcA.bottom += -5;
				}
			}
			else if (rect == false)
			{
				if (rcB.top <= rcA.bottom
					&& rcB.left < rcA.right
					&& rcB.right > rcA.left
					&& rcB.bottom >= rcA.top)
				{
					rect = true;
					rcB.top += 15;
					rcB.bottom += 15;
				}
				else
				{
					rcB.top += -5;
					rcB.bottom += -5;
				}
			}
			InvalidateRect(hWnd, NULL, true);


			break;
		case VK_DOWN:
			
			
			if (rect)
			{
				if (rcA.top <= rcB.bottom
					&& rcA.left < rcB.right
					&& rcA.right > rcB.left
					&& rcA.bottom >= rcB.top)
				{
					rect = false;
					rcA.bottom += -15;
					rcA.top += -15;
				}
				else
				{
					rcA.bottom += 5;
					rcA.top += 5;
				}
			}
			else if (rect == false)
			{
				if (rcB.top <= rcA.bottom
					&& rcB.left < rcA.right
					&& rcB.right > rcA.left
					&& rcB.bottom >= rcA.top)
				{
					rect = true;
					rcB.bottom += -15;
					rcB.top += -15;
				}
				else
				{
					rcB.bottom += 5;
					rcB.top += 5;
				}
			
			}

			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_LEFT:

			if (rect)
			{
				if (rcB.top < rcA.bottom
					&& rcA.left <= rcB.right
					&& rcA.right >= rcB.left
					&& rcB.bottom > rcA.top)
				{
					rect = false;
					rcA.left += 15;
					rcA.right += 15;
				}
				else
				{
					rcA.left += -5;
					rcA.right += -5;
				}
				
			}
			else if (rect == false)
			{
				if (rcA.top < rcB.bottom
					&& rcA.left <= rcB.right
					&& rcA.right >= rcB.left
					&& rcA.bottom > rcB.top)
				{
					rect = true;
					rcB.left += 15;
					rcB.right += 15;
				}
				else
				{
					rcB.left += -5;
					rcB.right += -5;
				}
				
			}

			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_RIGHT:
			
			if (rect)
			{
				if (rcB.top < rcA.bottom
					&& rcA.left <= rcB.right
					&& rcA.right >= rcB.left
					&& rcB.bottom > rcA.top)
				{
					rect = false;
					rcA.right += -15;
					rcA.left += -15;
				}
				else
				{
					rcA.right += 5;
					rcA.left += 5;
				}
				
			}
			else if (rect == false)
			{
				if (rcA.top < rcB.bottom
					&& rcA.left <= rcB.right
					&& rcA.right >= rcB.left
					&& rcA.bottom > rcB.top)
				{
					rect = true;
					rcB.right += -15;
					rcB.left += -15;
				}
				else
				{
					rcB.right += 5;
					rcB.left += 5;
				}
			}

			InvalidateRect(hWnd, NULL, true);

			break;

		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}