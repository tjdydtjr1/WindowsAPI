
#include "Stdafx.h"


HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 시간
std::chrono::milliseconds timeMilli;

// 사각형 4개
RECT rcA = { 0 };
RECT rcB = { 0 };
RECT rcC = { 0 };
RECT rcD = { 0 };

// 각 사각형 좌표 저장
RECT rc_1 = { 0 };
RECT rc_2 = { 0 };
RECT rc_3 = { 0 };
RECT rc_4 = { 0 };

// 마우스 좌표
POINT mousePT = { 0,0 };
POINT movePT = { 0,0 };
bool bRcA = false;
bool bRcB = false;
bool bRcC = false;
bool bRcD = false;

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
	wndClass.lpszClassName = WINMYNAME("사각형 4단 밀기");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		WINMYNAME("사각형 4단 밀기"),
		WINMYNAME("사각형 4단 밀기"),
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

	switch (iMessage)
	{
	case WM_CREATE:
		// 초기 좌표값
		rcA = RectMake(100, 300, 100, 100);
		rcB = RectMake(300, 100, 100, 100);
		rcC = RectMake(300, 500, 100, 100);
		rcD = RectMake(500, 500, 100, 100);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
	
		DrawRectMake(hdc, rcA);
		DrawRectMake(hdc, rcB);
		DrawRectMake(hdc, rcC);
		DrawRectMake(hdc, rcD);
		TextOut(hdc, RECTCENTER_X(rcA), RECTCENTER_Y(rcA), "A", strlen("A"));
		TextOut(hdc, RECTCENTER_X(rcB), RECTCENTER_Y(rcB), "B", strlen("B"));
		TextOut(hdc, RECTCENTER_X(rcC), RECTCENTER_Y(rcC), "C", strlen("C"));
		TextOut(hdc, RECTCENTER_X(rcD), RECTCENTER_Y(rcD), "D", strlen("D"));


		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		// 마우스 좌표
		mousePT.x = LOWORD(lParam);
		mousePT.y = HIWORD(lParam);

		// ================================================================
		// 사각형 이동
		if (bRcA)
		{
			// 이동할 사각형 좌표 변경
			rcA.left = rc_1.left + (mousePT.x - movePT.x);
			rcA.right = rc_1.right + (mousePT.x - movePT.x);
			rcA.top = rc_1.top + (mousePT.y - movePT.y);
			rcA.bottom = rc_1.bottom + (mousePT.y - movePT.y);

			
		}
		else if (bRcB)
		{
			// 이동할 사각형 좌표 변경
			rcB.left = rc_2.left + (mousePT.x - movePT.x);
			rcB.right = rc_2.right + (mousePT.x - movePT.x);
			rcB.top = rc_2.top + (mousePT.y - movePT.y);
			rcB.bottom = rc_2.bottom + (mousePT.y - movePT.y);

			
		}
		else if (bRcC)
		{
			// 이동할 사각형 좌표 변경
			rcC.left = rc_3.left + (mousePT.x - movePT.x);
			rcC.right = rc_3.right + (mousePT.x - movePT.x);
			rcC.top = rc_3.top + (mousePT.y - movePT.y);
			rcC.bottom = rc_3.bottom + (mousePT.y - movePT.y);

			
		}
		else if (bRcD)
		{
			// 이동할 사각형 좌표 변경
			rcD.left = rc_4.left + (mousePT.x - movePT.x);
			rcD.right = rc_4.right + (mousePT.x - movePT.x);
			rcD.top = rc_4.top + (mousePT.y - movePT.y);
			rcD.bottom = rc_4.bottom + (mousePT.y - movePT.y);

			
		}

		// ================================================================
		// 윈도우 창 안벗어나게 예외처리
		if (rcA.left < WINMINSIZE_LEFT)
		{
			rcA.left = WINMINSIZE_LEFT + 10;
			rcA.right = rcA.left + 100;
		}
		else if (rcA.right > WINMINSIZE_RIGHT)
		{
			rcA.right = WINMINSIZE_RIGHT - 10;
			rcA.left = rcA.right - 100;
		}

		if (rcA.top < WINMINSIZE_TOP)
		{
			rcA.top = WINMINSIZE_TOP + 10;
			rcA.bottom = rcA.top + 100;
		}
		else if (rcA.bottom > WINMINSIZE_BOTTOM)
		{
			rcA.bottom = WINMINSIZE_BOTTOM - 10;
			rcA.top = rcA.bottom - 100;
		}
		
		if (rcB.left < WINMINSIZE_LEFT)
		{
			rcB.left = WINMINSIZE_LEFT + 10;
			rcB.right = rcB.left + 100;
		}
		else if (rcB.right > WINMINSIZE_RIGHT)
		{
			rcB.right = WINMINSIZE_RIGHT - 10;
			rcB.left = rcB.right - 100;
		}

		if (rcB.top < WINMINSIZE_TOP)
		{
			rcB.top = WINMINSIZE_TOP + 10;
			rcB.bottom = rcB.top + 100;
		}
		else if (rcB.bottom > WINMINSIZE_BOTTOM)
		{
			rcB.bottom = WINMINSIZE_BOTTOM - 10;
			rcB.top = rcB.bottom - 100;
		}

		if (rcC.left < WINMINSIZE_LEFT)
		{
			rcC.left = WINMINSIZE_LEFT + 10;
			rcC.right = rcC.left + 100;
		}
		else if (rcC.right > WINMINSIZE_RIGHT)
		{
			rcC.right = WINMINSIZE_RIGHT - 10;
			rcC.left = rcC.right - 100;
		}

		if (rcC.top < WINMINSIZE_TOP)
		{
			rcC.top = WINMINSIZE_TOP + 10;
			rcC.bottom = rcC.top + 100;
		}
		else if (rcC.bottom > WINMINSIZE_BOTTOM)
		{
			rcC.bottom = WINMINSIZE_BOTTOM - 10;
			rcC.top = rcC.bottom - 100;
		}

		if (rcD.left < WINMINSIZE_LEFT)
		{
			rcD.left = WINMINSIZE_LEFT + 10;
			rcD.right = rcD.left + 100;
		}
		else if (rcD.right > WINMINSIZE_RIGHT)
		{
			rcD.right = WINMINSIZE_RIGHT - 10;
			rcD.left = rcD.right - 100;
		}

		if (rcD.top < WINMINSIZE_TOP)
		{
			rcD.top = WINMINSIZE_TOP + 10;
			rcD.bottom = rcD.top + 100;
		}
		else if (rcD.bottom > WINMINSIZE_BOTTOM)
		{
			rcD.bottom = WINMINSIZE_BOTTOM - 10;
			rcD.top = rcD.bottom - 100;
		}

		// ================================================================
		// 충돌 체크
		// A ->  UP
		if (rcA.top < rcB.bottom
			&& rcA.left < rcB.right
			&& rcA.right > rcB.left
			&& rcA.bottom > rcB.top)
		{
			rcB.top -= 1;
			rcB.bottom -= 1;
		}
		else if (rcA.top < rcC.bottom
			&& rcA.left < rcC.right
			&& rcA.right > rcC.left
			&& rcA.bottom > rcC.top)
		{
			rcC.top -= 1;
			rcC.bottom -= 1;
		}
		else if (rcA.top < rcD.bottom
			&& rcA.left < rcD.right
			&& rcA.right > rcD.left
			&& rcA.bottom > rcD.top)
		{
			rcB.top -= 1;
			rcB.bottom -= 1;
		}
		// A ->  DOWN
		if (rcA.top <= rcB.bottom
			&& rcA.left < rcB.right
			&& rcA.right > rcB.left
			&& rcA.bottom >= rcB.top)
		{
			rcB.top += 1;
			rcB.bottom += 1;
		}
		else if (rcA.top <= rcC.bottom
			&& rcA.left < rcC.right
			&& rcA.right > rcC.left
			&& rcA.bottom >= rcC.top)
		{
			rcC.top += 1;
			rcC.bottom += 1;
		}
		else if (rcA.top <= rcD.bottom
			&& rcA.left < rcD.right
			&& rcA.right > rcD.left
			&& rcA.bottom >= rcD.top)
		{
			rcD.top += 1;
			rcD.bottom += 1;
		}

		// A ->  RIGHT
		if (rcB.top < rcA.bottom
			&& rcA.left <= rcB.right
			&& rcA.right >= rcB.left
			&& rcB.bottom > rcA.top)
		{
			rcB.right += 1;
			rcB.left += 1;
		}
		else if (rcC.top < rcA.bottom
			&& rcA.left <= rcC.right
			&& rcA.right >= rcC.left
			&& rcC.bottom > rcA.top)
		{
			rcC.right += 1;
			rcC.left += 1;
		}
		else if (rcD.top < rcA.bottom
			&& rcA.left <= rcD.right
			&& rcA.right >= rcD.left
			&& rcD.bottom > rcA.top)
		{
			rcD.right += 1;
			rcD.left += 1;
		}

		// A ->  LEFT
		if (rcB.top < rcA.bottom
			&& rcA.left <= rcB.right
			&& rcA.right >= rcB.left
			&& rcB.bottom > rcA.top)
		{
			rcB.right -= 1;
			rcB.left -= 1;
		}
		else if (rcC.top < rcA.bottom
			&& rcA.left <= rcC.right
			&& rcA.right >= rcC.left
			&& rcC.bottom > rcA.top)
		{
			rcC.right -= 1;
			rcC.left -= 1;
		}
		else if (rcD.top < rcA.bottom
			&& rcA.left <= rcD.right
			&& rcA.right >= rcD.left
			&& rcD.bottom > rcA.top)
		{
			rcD.right -= 1;
			rcD.left -= 1;
		}


		InvalidateRect(hWnd, NULL, true);

		break;
	case WM_LBUTTONDOWN:
		// 이동 전 좌표 저장
		if (!bRcA)
		{
			// 현재 마우스 좌표 저장
			movePT.x = mousePT.x;
			movePT.y = mousePT.y;

			// 현재 사각형 좌표 저장
			rc_1.left = rcA.left;
			rc_1.top = rcA.top;
			rc_1.right = rcA.right;
			rc_1.bottom = rcA.bottom;
		}
		if (!bRcB)
		{
			// 현재 마우스 좌표 저장
			movePT.x = mousePT.x;
			movePT.y = mousePT.y;

			// 현재 사각형 좌표 저장
			rc_2.left = rcB.left;
			rc_2.top = rcB.top;
			rc_2.right = rcB.right;
			rc_2.bottom = rcB.bottom;
		}	
		if (!bRcC)
		{
			// 현재 마우스 좌표 저장
			movePT.x = mousePT.x;
			movePT.y = mousePT.y;

			// 현재 사각형 좌표 저장
			rc_3.left = rcC.left;
			rc_3.top = rcC.top;
			rc_3.right = rcC.right;
			rc_3.bottom = rcC.bottom;
		}	
		if (!bRcD)
		{
			// 현재 마우스 좌표 저장
			movePT.x = mousePT.x;
			movePT.y = mousePT.y;

			// 현재 사각형 좌표 저장
			rc_4.left = rcD.left;
			rc_4.top = rcD.top;
			rc_4.right = rcD.right;
			rc_4.bottom = rcD.bottom;
		}

		// ================================================================
		// 마우스 좌표에 맞는 Rect 클릭
		if (rcA.left < mousePT.x && rcA.right > mousePT.x
			&& rcA.top < mousePT.y && rcA.bottom > mousePT.y)
		{
			bRcA = true;
		}
		else if (rcB.left < mousePT.x && rcB.right > mousePT.x
			&& rcB.top < mousePT.y && rcB.bottom > mousePT.y)
		{
			bRcB = true;
		}
		else if (rcC.left < mousePT.x && rcC.right > mousePT.x
			&& rcC.top < mousePT.y && rcC.bottom > mousePT.y)
		{
			bRcC = true;
		}
		else if (rcD.left < mousePT.x && rcD.right > mousePT.x
			&& rcD.top < mousePT.y && rcD.bottom > mousePT.y)
		{
			bRcD = true;
		}
		break;
	case WM_LBUTTONUP:
		// 상태 초기화
		bRcA = false;
		bRcB = false;
		bRcC = false;
		bRcD = false;
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

