
#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("�� Ƣ���");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ���� ����
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
		
		//   ��            �簢��
		
		switch (state)
		{
			// Right
		case 0:
			// ���ʿ��� ž���� �ö�Դ� ���
			if(temp == 3)
			{
				// �ð���� ����
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
					// ���� ������� ���� ����
					temp = 0;
					// ���� ������� �̵�
					state = 1;
				}
			}
			// �����ʿ��� ž���� �ö󰡴� ���
			else
			{
				// �ݽð� ���� ���� ��
				temp = 0;
				state = 2;
			}
			break;
			// Bottom
		case 1:
			// ž���� ���������� �Դ� ���
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
			// �����ʿ��� �Ʒ��� ���� ���
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
			// �Ʒ����� �������� ���� ���
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
		wsprintf(Text, "��    => �� : %d, �� : %d , �� : %d , �Ʒ� : %d", ellipse.left, ellipse.right, ellipse.top, ellipse.bottom);
		TextOut(hdc, 10, 10, Text, strlen(Text));
		wsprintf(Text, "�簢�� =>    �� : %d, �� : %d , �� : %d , �Ʒ� : %d", rc.left, rc.right, rc.top, rc.bottom);
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

