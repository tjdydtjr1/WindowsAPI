#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("6�� 9�� ���� : ������ �׸���");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ���� X,Y ��ǥ
struct LineXY
{
	int m_x;
	int m_y;
};


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
	//����1.������ ���
	//	- �������� ������ó�� ����� �´�.
	//	- ����� �������� ������ �������� �� ���� ȿ������ �������
	//	�� Ư�� �迭�� ������ ����� ����.

	HDC hdc;
	PAINTSTRUCT ps;

	LineXY first[5] = { {493, 250}, {165, 450}, {290, 100}, {430, 450}, {106, 250} };

	switch (iMessage)
	{
	case WM_CREATE:

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Ellipse(hdc, 100, 100, 500, 500);
		MoveToEx(hdc, 106, 250, NULL);
		for (int i = 0; i < 5; ++i)
		{
			LineTo(hdc, first[i].m_x, first[i].m_y);
		}

		// =====================================================
		for (int i = 0; i < 395; ++i)
		{
			SetPixel(hdc, 106 + i, 249, RGB(255, 0, 0));
		}

		for (int i = 0; i < 200; ++i)
		{
			SetPixel(hdc, first[1].m_x, first[1].m_y, RGB(0,255,0));
		}

		// ������ ��ǥ
		/*LineTo(hdc, 493, 250);
		LineTo(hdc, 165, 450);
		LineTo(hdc, 290, 100);
		LineTo(hdc, 430, 450);
		LineTo(hdc, 106, 250);
		*/
		
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
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
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
