
#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("공 튀기기");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 전역 변수
static RECT rc = RectMake(100, 100, 200, 200);
static RECT ellipse = RectMake(150, 150, 30, 30);
int speed = 1;

bool test = true;
int state = 0;
int temp = 3;

HDC hdc;
PAINTSTRUCT ps;

char Text[128];


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

		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		
		//   원            사각형
		
		switch (state)
		{
			// Right
		case 0:
			// 왼쪽에서 탑으로 올라왔던 경우
			if(temp == 3)
			{
				// 시계방향 진행
				if (ellipse.right < rc.right)
				{
					ellipse.left += speed;
					ellipse.right += speed;
					ellipse.top += speed;
					ellipse.bottom += speed;
					Sleep(10);
				}
				else
				{
					// 현재 진행방향 상태 저장
					temp = 0;
					// 다음 진행방향 이동
					state = 1;
				}
			}
			// 오른쪽에서 탑으로 올라가는 경우
			else
			{
				// 반시계 방향 진행 시
				temp = 0;
				state = 2;
			}
			break;
			// Bottom
		case 1:
			// 탑에서 오른쪽으로 왔던 경우
			if(temp == 2)
			{
				if (ellipse.bottom < rc.bottom)
				{
					ellipse.left -= speed;
					ellipse.right -= speed;
					ellipse.top += speed;
					ellipse.bottom += speed;
					Sleep(10);
				}
				else
				{
					temp = 1;
					state = 2;
				}
			}
			else
			{
				temp = 1;
				state = 1;
			}
			break;
			// Left
		case 2:
			// 오른쪽에서 아래로 오는 경우
			if(temp == 1)
			{
				if (ellipse.left > rc.left)
				{
					ellipse.left -= speed;
					ellipse.right -= speed;
					ellipse.top -= speed;
					ellipse.bottom -= speed;
					Sleep(10);
				}
				else
				{
					temp = 2;
					state = 3;
				}
			}
			else
			{
				temp = 2;
				state = 1;
			}
			break;
			// Top
		case 3:
			// 아래에서 왼쪽으로 가는 경우
			if(temp == 0)
			{
				if (ellipse.top > rc.top)
				{
					ellipse.left += speed;
					ellipse.right += speed;
					ellipse.top -= speed;
					ellipse.bottom -= speed;
					Sleep(10);
				}
				else
				{
					temp = 3;
					state = 0;
				}
			}
			else
			{
				temp = 3;
				state = 1;
			}
			break;
		default:
			break;
		}

		/*if (test)
		{
			if (ellipse.right == rc.right)
			{
			}
			if (ellipse.bottom < rc.bottom && ellipse.right < rc.right)
			{
				
				ellipse.left += speedX;
				ellipse.right += speedX;
				ellipse.top += speedY;
				ellipse.bottom += speedY;
				
				Sleep(100);
			}
			else if (ellipse.right < rc.right)
			{
				ellipse.bottom += speedY;
				ellipse.left -= speedX;
				
				Sleep(100);

			}
			else if (ellipse.bottom >= rc.bottom)
			{
				test = false;
			}
		}
		else if (!test)
		{
			if(ellipse.top > rc.top)
			{
				ellipse.left -= speedX;
				ellipse.right -= speedX;
				ellipse.top -= speedY;
				ellipse.bottom -= speedY;
				Sleep(100);
			}
			else if (ellipse.top <= rc.top)
			{
				test = true;
			}
		}*/

		InvalidateRect(_hWnd, NULL, true);


	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	

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

		case VK_HOME:
			Sleep(3000);
		default:
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		speed += 1;

		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_RBUTTONDOWN:
		if (speed != 0 )
		{
			speed -= 1;
		}
		
		InvalidateRect(hWnd, NULL, true);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		wsprintf(Text, "원    => 좌 : %d, 우 : %d , 위 : %d , 아래 : %d", ellipse.left, ellipse.right, ellipse.top, ellipse.bottom);
		TextOut(hdc, 10, 10, Text, strlen(Text));
		wsprintf(Text, "사각형 =>    좌 : %d, 우 : %d , 위 : %d , 아래 : %d", rc.left, rc.right, rc.top, rc.bottom);
		TextOut(hdc, 10, 30, Text, strlen(Text));

		DrawRectMake(hdc, rc);
		DrawEllipseMake(hdc, ellipse);
		EndPaint(hWnd, &ps);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

