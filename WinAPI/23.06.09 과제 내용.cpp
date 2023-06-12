/*
과제1. 오망성 출력
- 오망성을 마법진처럼 만들어 온다.
- 양식은 자유지만 본인이 생각했을 때 가장 효율적인 방법으로
ㄴ 특히 배열은 무조건 사용해 본다.

과제2. 애플 로고 출력
- SetPixel을 이용해서 만든다.
- 효율적인 반복문

과제3. 사각형 이동
- 방향키를 통해 사각형을 움직인다.
- 예외 처리 : 사각형은 화면 밖으로 나갈 수 없다. ( 우측은 아직 안잡혀있어서 조금 나감)

과제4. 사각형 2개 움직이기
- 총 사각형 갯수 : 2개
- 하나는 움직일 수 있는 사각형 / 다른 하나는 움직일 수 없는 사각형
- 움직일 수 없는 사각형을 움직일 수 있는 사각형이 밀어낼 수 있으면 된다.
- 예외 처리 : 사각형은 화면 밖으로 나갈 수 없다. ( 우측은 아직 안잡혀있어서 조금 나감)
- 2개의 사각형을 초기 위치로 돌리는 기능도 추가한다.

충돌 함수 사용 금지

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

