#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("6월 9일 과제 : 사각형 이동");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int left = 0;
int top = 0;
int right = 0;
int bottom = 0;

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
	RECT rc = { 200,200, 300,300 };
	
	switch (iMessage)
	{
	case WM_CREATE:
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Rectangle(hdc, rc.left + left, rc.top + top, rc.right + right, rc.bottom + bottom);
		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
	{
	
		switch (wParam)
		{
		case VK_UP:
			if (rc.top + top < 10)
			{
				break;
			}

			hdc = GetDC(hWnd);
			top -= 10;
			bottom -= 10;
			InvalidateRect(hWnd, NULL, true);
			
			ReleaseDC(hWnd, hdc);
			break;
		case VK_DOWN:
			if (rc.bottom + bottom > 750)
			{
				break;
			}
			hdc = GetDC(hWnd);
			top += 10;
			bottom += 10;
			InvalidateRect(hWnd, NULL, true);
			ReleaseDC(hWnd, hdc);

			break;
		case VK_LEFT:
			if (rc.left + left < 10)
			{
				break;
			}
			hdc = GetDC(hWnd);
			left -= 10;
			right -= 10;
			InvalidateRect(hWnd, NULL, true);
			ReleaseDC(hWnd, hdc);
			break;
		case VK_RIGHT:
			if (rc.right + right > 780)
			{
				break;
			}
			hdc = GetDC(hWnd);
			left += 10;
			right += 10;
			InvalidateRect(hWnd, NULL, true);
			ReleaseDC(hWnd, hdc);
			break;

		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
		default:
			break;
		}
	}
	default:
		break;
	
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
