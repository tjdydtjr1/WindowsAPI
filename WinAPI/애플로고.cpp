#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("6�� 9�� ���� : ���÷ΰ� �׸���");

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
	HDC hdc;
	PAINTSTRUCT ps;
	
	switch (iMessage)
	{
	case WM_CREATE:
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 100, 100, 600, 700);
		
		// ��� ����
		MoveToEx(hdc, 100, 200, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 100 + i, RGB(0, 128, 0));
			}
		}
		LineTo(hdc, 600, 200);

		// �ι�° ��������
		MoveToEx(hdc, 100, 300, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 200 + i, RGB(255, 180, 0));
			}
		}
		LineTo(hdc, 600, 300);

		// ����° ��Ȳ��
		MoveToEx(hdc, 100, 400, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 300 + i, RGB(255, 127, 0));
			}
		}
		LineTo(hdc, 600, 400);

		// �׹�° ������
		MoveToEx(hdc, 100, 500, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 400 + i, RGB(255, 0, 0));
			}
		}
		LineTo(hdc, 600, 500);

		// �ټ���° �����
		MoveToEx(hdc, 100, 600, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 500 + i, RGB(153, 50, 204));
			}
		}
		LineTo(hdc, 600, 600);

		// �������� �ϴû�
		MoveToEx(hdc, 100, 700, NULL);
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 500; ++j)
			{
				SetPixel(hdc, 100 + j, 600 + i, RGB(0, 180, 255));
			}
		}
		LineTo(hdc, 600, 700);
		
		// ��� �ĸԱ�
		Ellipse(hdc, 500, 200, 800, 500);

		// �ٱ��� �� ����
		for (int i = 0; i < 300; ++i)
		{
			for (int j = 0; j < 300; ++j)
			{
				SetPixel(hdc, 600 + j, 200 + i, RGB(255, 255, 255));
			}
		}
		////////////////////////////////////////////
	
		// ȣ �׸���
		//Arc(hdc, 50, 10, 150, 150, 200, 150, 150, 150);
		Arc(hdc, 100, 50, 600, 800, 200, 50, 100, 800);
		
		// ���� ���
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 120; ++j)
			{
				SetPixel(hdc, 100 + j - i, 100 + i, RGB(255, 255, 255));
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				SetPixel(hdc, 100 + j - i, 200 + i, RGB(255, 255, 255));
			}
		}
		// ���� �ϴ�
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 80; ++j)
			{
				SetPixel(hdc, 100 + j - i, 700 - i, RGB(255, 255, 255));
			}
		}
		// =========================================
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				SetPixel(hdc, 100 + j, 500 + i, RGB(255, 255, 255));
			}
		}

		/*for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				SetPixel(hdc, 100 + j, 520 + i, RGB(255, 255, 255));
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				SetPixel(hdc, 100 + j, 530 + i, RGB(255, 255, 255));
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				SetPixel(hdc, 100 + j, 540 + i, RGB(255, 255, 255));
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				SetPixel(hdc, 100 + j, 550 + i, RGB(255, 255, 255));
			}
		}*/
		//Ellipse(hdc, 100, 100, 400, 400);
		//Ellipse(hdc, 300, 100, 600, 400);

		
		// ��ǥ
		//Ellipse(hdc, 500, 200, 800, 500);
		EndPaint(hWnd, &ps);

		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		default:
			break;
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
