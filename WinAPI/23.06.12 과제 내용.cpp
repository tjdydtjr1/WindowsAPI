/*
과제1. 사각형 영혼 밀어 넣기
- 시작은 큰 사각형 2개와 작은 사각형 1개

- 내가 움직일 수 있는 사각형 안에는 작은 사각형이 들어 있다.

- 사각형을 움직이면 작은 사각형 역시 움직이는 버전 1개 / 움직이는 않는 버전 1개
ㄴ 총 2가지 버전
ㄴ 예외처리 : 작은 사각형은 큰 사각형을 벗어날 수 없다.

- 큰 사각형끼리 충돌이 되면 작은 사각형은 충돌이 된 반대편 사각형으로 이동한다.

핵심은 움직일 수 있는 주도권은 작은 사각형을 가지고 있는 "큰 사각형"

예외 처리 : 큰 사각형끼리의 모서리에 대한 정밀도를 예외 처리한다.
ㄴ  모서리 부분 겹치면 뚫고 들어감 (소수점)

*/


#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT(" ");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}