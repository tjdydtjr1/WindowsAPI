/*
����1. �簢�� ��ȥ �о� �ֱ�
- ������ ū �簢�� 2���� ���� �簢�� 1��

- ���� ������ �� �ִ� �簢�� �ȿ��� ���� �簢���� ��� �ִ�.

- �簢���� �����̸� ���� �簢�� ���� �����̴� ���� 1�� / �����̴� �ʴ� ���� 1��
�� �� 2���� ����
�� ����ó�� : ���� �簢���� ū �簢���� ��� �� ����.

- ū �簢������ �浹�� �Ǹ� ���� �簢���� �浹�� �� �ݴ��� �簢������ �̵��Ѵ�.

�ٽ��� ������ �� �ִ� �ֵ����� ���� �簢���� ������ �ִ� "ū �簢��"

���� ó�� : ū �簢�������� �𼭸��� ���� ���е��� ���� ó���Ѵ�.
��  �𼭸� �κ� ��ġ�� �հ� �� (�Ҽ���)

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