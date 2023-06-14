#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("무작위 도형 출력");

// 전역 변수
// 마우스 좌표
POINT mousePT = { 0 };

int polygon = 0;
int width = 0;
int height = 0;
int x = 60;
int y = 90;
int choice = 0;
char Text[128];

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdParam, int nCmdShow)
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
		srand(time(NULL));
		width = rand() % WINSTART_X + 1;
		height = rand() % WINSIZE_Y + 1;
		polygon = rand() % 6 + 3;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
		default:
			break;
		}
		break;
	case WM_MOUSEMOVE:
		mousePT.x = LOWORD(lParam);
		mousePT.y = HIWORD(lParam);
		
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_LBUTTONDOWN:
		choice = RND->getInt(4);
		width = rand() % WINSTART_X + 1;
		height = rand() % WINSIZE_Y + 1;
		polygon = rand() % 5 + 3;
		
			InvalidateRect(hWnd, NULL, true);
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		wsprintf(text, "X 좌표 : %d   Y 좌표 : %d", mousePT.x, mousePT.y);
		TextOut(hdc, 10, 10, text, strlen(text));

		switch (choice)
		{
			// 사각형
		case 0:
			wsprintf(Text, "사각형");
			RectangleMake(hdc, mousePT.x, mousePT.y, width, height);
			
			break;
			// 원
		case 1:
			wsprintf(Text, "원");
			EllipseMake(hdc, mousePT.x, mousePT.y, width, height);
			break;
			// 삼각형
		case 2:
			wsprintf(Text, "삼각형");
			TriangleMake(hdc, mousePT.x, mousePT.y, width, height);
			break;
			// 다각형
		case 3:
			wsprintf(Text, "다각형");
			switch (polygon)
			{
			case 3:
				MoveToEx(hdc, mousePT.x, mousePT.y, NULL);
				LineTo(hdc, width, height);
				for (int i = 1; i <= 3; ++i)
				{
					LineTo(hdc, width - (x * i), height - (y * i));
				}
				LineTo(hdc, mousePT.x, mousePT.y);

				break;
			case 4:
				MoveToEx(hdc, mousePT.x, mousePT.y, NULL);
				LineTo(hdc, width, height);
				for (int i = 1; i <= 4; ++i)
				{
					LineTo(hdc, width - (x * i), height - (y * i));
				}
				LineTo(hdc, mousePT.x, mousePT.y);

				break;
			case 5:
				MoveToEx(hdc, mousePT.x, mousePT.y, NULL);
				LineTo(hdc, width, height);
				for (int i = 1; i <= 5; ++i)
				{
					LineTo(hdc, width - (x * i), height - (y * i));
				}
				LineTo(hdc, mousePT.x, mousePT.y);

				break;
			case 6:
				MoveToEx(hdc, mousePT.x, mousePT.y, NULL);
				LineTo(hdc, width, height);
				for (int i = 1; i <= 6; ++i)
				{
					LineTo(hdc, width - (x * i), height - (y * i));
				}
				LineTo(hdc, mousePT.x, mousePT.y);

				break;
			case 7:
				MoveToEx(hdc, mousePT.x, mousePT.y, NULL);
				LineTo(hdc, width, height);
				for (int i = 1; i <= 7; ++i)
				{
					LineTo(hdc, width - (x * i), height - (y * i));
				}
				LineTo(hdc, mousePT.x, mousePT.y);

				break;
			}
			break;
		}

		TextOut(hdc, mousePT.x - 20, mousePT.y - 20, Text, strlen(Text));
		EndPaint(hWnd, &ps);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
