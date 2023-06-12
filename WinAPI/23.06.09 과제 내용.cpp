/*
����1. ������ ���
- �������� ������ó�� ����� �´�.
- ����� �������� ������ �������� �� ���� ȿ������ �������
�� Ư�� �迭�� ������ ����� ����.

����2. ���� �ΰ� ���
- SetPixel�� �̿��ؼ� �����.
- ȿ������ �ݺ���

����3. �簢�� �̵�
- ����Ű�� ���� �簢���� �����δ�.
- ���� ó�� : �簢���� ȭ�� ������ ���� �� ����. ( ������ ���� �������־ ���� ����)

����4. �簢�� 2�� �����̱�
- �� �簢�� ���� : 2��
- �ϳ��� ������ �� �ִ� �簢�� / �ٸ� �ϳ��� ������ �� ���� �簢��
- ������ �� ���� �簢���� ������ �� �ִ� �簢���� �о �� ������ �ȴ�.
- ���� ó�� : �簢���� ȭ�� ������ ���� �� ����. ( ������ ���� �������־ ���� ����)
- 2���� �簢���� �ʱ� ��ġ�� ������ ��ɵ� �߰��Ѵ�.

�浹 �Լ� ��� ����

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

