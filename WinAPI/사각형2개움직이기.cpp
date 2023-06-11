#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("6월 9일 과제 : 사각형2개 움직이기");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

RECT rc = { 200,200, 300, 300 };
RECT rc2 = { 400, 200, 500, 300 };

int left = 0;
int top = 0;
int right = 0;
int bottom = 0;

int left2 = 0;
int top2 = 0;
int right2 = 0;
int bottom2 = 0;

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

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Rectangle(hdc, rc.left + left, rc.top + top, rc.right + right, rc.bottom + bottom);
		Rectangle(hdc, rc2.left + left2, rc2.top + top2, rc2.right + right2, rc2.bottom + bottom2);

		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
	{

		switch (wParam)
		{
		case VK_UP:
			if (rc.top + top < 10 && rc.top + top <= rc2.bottom + bottom2)
			{
				break;
			}
			if (rc2.top + top2 <= 10)
			{
				rc2.top = 10;
				top2 = 10;

				rc2.bottom = 110;
				bottom2 = 0;
			}
			
			if ((rc.top + top >= rc2.bottom + bottom2	// 상하단
				|| rc2.bottom + bottom2 >= rc.bottom + bottom)
				&& rc.right + right > rc2.left + left2  // 우측
				&& rc.left + left < rc2.right + right2) // 좌측
			{
				top2 -= 5;
				bottom2 -= 5;
			}

			top -= 5;
			bottom -= 5;

			InvalidateRect(hWnd, NULL, true);
			break;
		case VK_DOWN:
			if (rc.bottom + bottom > 750 || rc2.top + top2 > 750)
			{
				break;
			}
			
			if ((rc2.top + top2 <= rc.bottom + bottom	// 상하단
				|| rc2.bottom + bottom2 > rc.top + top)
				&& rc2.right + right2 > rc.left + left  // 우측
				&& rc2.left + left2 < rc.right + right) // 좌측
			{
				top2 += 5;
				bottom2 += 5;
			}
			
			top += 5;
			bottom += 5;
			InvalidateRect(hWnd, NULL, true);

			break;
		case VK_LEFT:
			if (rc.left + left < 10 || rc2.left < 10)
			{
				break;
			}

			if (rc2.right + right2 == rc.left + left
				&& rc2.top + top2 < rc.bottom + bottom
				&& rc2.bottom + bottom2 > rc.top + top
				)
			{
				left2 -= 5;
				right2 -= 5;
			}

			left -= 5;
			right -= 5;
			InvalidateRect(hWnd, NULL, true);
			break;
		case VK_RIGHT:
			if (rc.right + right > 780 || rc2.right > 780)
			{
				break;
			}
			
			if (rc.right + right >= rc2.left + left2
				&& rc.top + top < rc2.bottom + bottom2
				&& rc.bottom + bottom > rc2.top + top2
				)
			{
				left2 += 5;
				right2 += 5;
			}

			left += 5;
			right += 5;
			InvalidateRect(hWnd, NULL, true);
			
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
