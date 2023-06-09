/*
* 06.08
����1. ������ â �����

- �ð��� 10��

- ���н� ���� 7��

���� ����. ��Ʈ�� ������ ���´�.

- Callback Function, DC, GetDC / Release DC, <- ��� void ������, ��������Ʈ, DC������ ������ ������ Ż��
BeginPaint / EndPaint, WM_PAINT , PAINTSTRUCT
*/

/*
06.09
����1. ������
- ����ó�� �ʼ� : �������� ���� (1�� ���� x / 9�� �̻� x)

- ���콺 ���� Ŭ���� ���� �� 1�ܾ� �����, �� Ŭ���� �ϸ� 1�ܾ� ��������.
�� 3�ܾ� �����Ѵ�.

����2. WinAPI ���

- MoveToEx() + LineTo()�� �̿��Ѵ�.
* ���� ���� �Լ� ��� ����
�ݺ��� �� ����ϱ�

- 1. �ڱ� �̸� ��� (�ѱ�)
- 2. Unreal Engine  (����)

- ���콺 ������ ������ �ѱ��ھ� ����� �Ǹ� �� Ŭ���� �ϸ� �ѱ��ھ� ��������.

- ���� â ũ�� ���� ���� �̻��� ������� �ؿ´�.

���� ����
- SetTimer
- KillTimer
- InvalidateRect

*/


#include <Windows.h>
#include <tchar.h>

int name = 0;
int dan = 1;

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("WindowAPI");

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
        _lpszClass,                 // ������ Ŭ���� �ĺ���
        _lpszClass,                 // ������ Ÿ��Ʋ �� �̸�
        WS_EX_OVERLAPPEDWINDOW,     // ������ ��Ÿ�� (������ ��� �׷���)
        400,                        // ������ ȭ�� x ��ǥ
        100,                        // ������ ȭ�� y ��ǥ
        800,                        // ������ ȭ�� ���� ũ��
        800,                        // ������ ȭ�� ���� ũ��
        NULL,                       // �θ� ������ -> GetDesktopWindow
        (HMENU)NULL,                // �޴� �ڵ�
        hInstance,                  // �ν��Ͻ� ����
        NULL                        // ������ �ڽ� �����츦 �����ϸ� �����ϰ� �׷��� �ʴٸ� NULL
                                    // �� �ʿ信 ���ؼ� ����ϱ⵵ ������ ������ NULL (â ������ ����)
    );
    
    MSG message;

    ShowWindow(_hWnd, nCmdShow);

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
    }

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
    case WM_PAINT:              // ��¿� ���� ������ ����Ѵ�. (����, �׸�, ������ ȭ�鿡 ���̴� ����)
        hdc = BeginPaint(hWnd, &ps);
    case WM_LBUTTONDOWN:
        // WM_PAINT�� �ƴϱ⿡ GetDC�� ����Ͽ� �����´�.
        hdc = GetDC(hWnd);
        /* ++dan;
         danX = 10;
         danY = 85;
         Y = 0;
         if (dan < 2)
         {
             dan = 1;
             return 0;
         }
         else if (dan > 9)
         {
             dan = 8;
         }

         for (int i = 2; i <= dan; ++i)
         {

             if (i >= 5 && i < 8)
             {
                 if (i == 5)
                 {
                     danX = 10;
                 }
                 Y = 160;
             }
             else if (i >= 8)
             {
                 if (i == 8)
                 {
                     danX = 10;
                 }
                 Y = 320;
             }

             for (int j = 1; j < 10; ++j)
             {
                 sprintf_s(test, "%d x %d = %d", i, j, i * j);
                 TextOut(hdc, danX, (danY + Y), test, strlen(test));
                 danY += 15;
             }
             danX += 120;
             danY = 85;
         }*/
         // //�̸�
        ++name;
        switch (name)
        {
        case 3:
            // ��
            MoveToEx(hdc, 400, 150, NULL);
            LineTo(hdc, 310, 250);

            MoveToEx(hdc, 350, 200, NULL);
            LineTo(hdc, 400, 250);

            MoveToEx(hdc, 460, 200, NULL);
            LineTo(hdc, 400, 200);

            MoveToEx(hdc, 460, 130, NULL);
            LineTo(hdc, 460, 270);

            MoveToEx(hdc, 350, 300, NULL);
            LineTo(hdc, 470, 300);
            LineTo(hdc, 470, 350);

        case 2:
            // ��
            MoveToEx(hdc, 200, 130, NULL);
            LineTo(hdc, 201, 130);


            MoveToEx(hdc, 260, 160, NULL);
            LineTo(hdc, 260, 180);

            LineTo(hdc, 250, 190);
            LineTo(hdc, 240, 200);
            LineTo(hdc, 220, 200);
            LineTo(hdc, 200, 180);
            LineTo(hdc, 200, 160);
            LineTo(hdc, 220, 140);
            LineTo(hdc, 240, 140);
            LineTo(hdc, 260, 160);

            MoveToEx(hdc, 240, 200, NULL);
            LineTo(hdc, 240, 220);
            MoveToEx(hdc, 220, 200, NULL);
            LineTo(hdc, 220, 220);
            MoveToEx(hdc, 160, 220, NULL);
            LineTo(hdc, 300, 220);

            MoveToEx(hdc, 260, 260, NULL);
            LineTo(hdc, 260, 280);

            LineTo(hdc, 250, 290);
            LineTo(hdc, 240, 300);
            LineTo(hdc, 220, 300);
            LineTo(hdc, 200, 280);
            LineTo(hdc, 200, 260);
            LineTo(hdc, 220, 240);
            LineTo(hdc, 240, 240);
            LineTo(hdc, 260, 260);
        case 1:
            // ��
            MoveToEx(hdc, 100, 150, NULL);
            LineTo(hdc, 10, 250);

            MoveToEx(hdc, 50, 200, NULL);
            LineTo(hdc, 100, 250);

            MoveToEx(hdc, 60, 200, NULL);
            LineTo(hdc, 120, 200);

            MoveToEx(hdc, 120, 130, NULL);
            LineTo(hdc, 120, 270);
        default:
            break;
        }
        /*for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 260 - i, 160);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 255 - i, 158);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 250 - i, 156);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 245 - i, 154);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 240 - i, 152);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 235 - i, 150);
        }*/

        //Unreal Engine
    //++name;
    //switch (name)
    //{

    //case 11:
    //    // n
    //    MoveToEx(hdc, 470, 125, NULL);
    //    LineTo(hdc, 470, 160);
    //    LineTo(hdc, 470, 125);
    //    LineTo(hdc, 475, 124);
    //    LineTo(hdc, 480, 123);
    //    LineTo(hdc, 485, 124);
    //    LineTo(hdc, 490, 125);
    //    LineTo(hdc, 495, 126);
    //    LineTo(hdc, 495, 160);

    //    MoveToEx(hdc, 510, 125, NULL);
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 515 + i, 125);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 520 + i, 124);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 525 + i, 125);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 530 + i, 126);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 535 + i, 127);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 540 + i, 130);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 540 + i, 132);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 540 + i, 130 + i);
    //    }
    //    LineTo(hdc, 540, 140);
    //    LineTo(hdc, 510, 140);
    //    LineTo(hdc, 510, 125);
    //    LineTo(hdc, 510, 150);
    //    LineTo(hdc, 515, 155);
    //    LineTo(hdc, 535, 155);
    //case 10:

    //    // i
    //    MoveToEx(hdc, 450, 125, NULL);
    //    LineTo(hdc, 450, 160);
    //    MoveToEx(hdc, 450, 120, NULL);

    //    for (int i = 0; i < 10; ++i)
    //    {
    //        LineTo(hdc, 445 + i, 120);
    //    }

    //case 9:
    //    // g
    //    MoveToEx(hdc, 415, 120, NULL);
    //    LineTo(hdc, 430, 120);
    //    MoveToEx(hdc, 415, 120, NULL);
    //    LineTo(hdc, 410, 122);
    //    LineTo(hdc, 405, 124);
    //    LineTo(hdc, 405, 130);
    //    LineTo(hdc, 410, 134);
    //    LineTo(hdc, 415, 135);
    //    LineTo(hdc, 420, 136);
    //    LineTo(hdc, 425, 137);
    //    LineTo(hdc, 435, 137);
    //    LineTo(hdc, 435, 145);
    //    LineTo(hdc, 430, 146);
    //    LineTo(hdc, 430, 148);
    //    LineTo(hdc, 420, 150);
    //    LineTo(hdc, 415, 150);
    //    LineTo(hdc, 410, 150);
    //    MoveToEx(hdc, 415, 120, NULL);
    //    LineTo(hdc, 430, 120);
    //    LineTo(hdc, 435, 125);
    //    LineTo(hdc, 435, 128);
    //    LineTo(hdc, 435, 130);
    //    LineTo(hdc, 435, 135);
    //    LineTo(hdc, 435, 150);

    //case 8:
    //    // n
    //    MoveToEx(hdc, 360, 160, NULL);
    //    LineTo(hdc, 360, 125);
    //    LineTo(hdc, 365, 120);
    //    LineTo(hdc, 370, 119);
    //    LineTo(hdc, 375, 118);
    //    LineTo(hdc, 380, 119);
    //    LineTo(hdc, 385, 120);
    //    LineTo(hdc, 390, 122);
    //    LineTo(hdc, 390, 160);


    //case 7:
    //    // E
    //    MoveToEx(hdc, 320, 120, NULL);
    //    LineTo(hdc, 350, 120);
    //    MoveToEx(hdc, 320, 120, NULL);
    //    LineTo(hdc, 320, 140);
    //    LineTo(hdc, 350, 140);
    //    MoveToEx(hdc, 320, 140, NULL);
    //    LineTo(hdc, 320, 160);
    //    MoveToEx(hdc, 320, 160, NULL);
    //    LineTo(hdc, 350, 160);

    //case 6:
    //    // l
    //    MoveToEx(hdc, 300, 123, NULL);
    //    LineTo(hdc, 300, 160);



    //case 5:
    //    // a
    //    MoveToEx(hdc, 280, 140, NULL);
    //    LineTo(hdc, 280, 144);
    //    LineTo(hdc, 280, 150);
    //    LineTo(hdc, 275, 155);
    //    LineTo(hdc, 270, 156);
    //    LineTo(hdc, 265, 157);
    //    LineTo(hdc, 270, 157);
    //    LineTo(hdc, 265, 158);
    //    LineTo(hdc, 260, 158);
    //    LineTo(hdc, 255, 156);
    //    LineTo(hdc, 250, 155);
    //    LineTo(hdc, 252, 150);
    //    LineTo(hdc, 250, 152);
    //    LineTo(hdc, 250, 150);
    //    LineTo(hdc, 250, 148);
    //    LineTo(hdc, 253, 146);
    //    LineTo(hdc, 253, 144);
    //    LineTo(hdc, 253, 142);
    //    LineTo(hdc, 256, 142);
    //    LineTo(hdc, 260, 141);
    //    LineTo(hdc, 265, 141);
    //    LineTo(hdc, 270, 140);
    //    LineTo(hdc, 275, 139);
    //    LineTo(hdc, 280, 139);
    //    LineTo(hdc, 280, 135);
    //    LineTo(hdc, 280, 140);
    //    LineTo(hdc, 278, 145);
    //    LineTo(hdc, 280, 144);
    //    LineTo(hdc, 280, 130);
    //    LineTo(hdc, 278, 129);
    //    LineTo(hdc, 277, 128);
    //    LineTo(hdc, 275, 126);
    //    LineTo(hdc, 270, 124);
    //    LineTo(hdc, 265, 123);
    //    LineTo(hdc, 260, 123);
    //case 4:
    //    // e
    //    MoveToEx(hdc, 210, 125, NULL);
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 215 + i, 125);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 220 + i, 124);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 225 + i, 125);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 230 + i, 126);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 235 + i, 127);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 240 + i, 130);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 240 + i, 132);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 240 + i, 130 + i);
    //    }
    //    LineTo(hdc, 240, 140);
    //    LineTo(hdc, 210, 140);
    //    LineTo(hdc, 210, 125);
    //    LineTo(hdc, 210, 150);
    //    LineTo(hdc, 215, 155);
    //    LineTo(hdc, 235, 155);

    //case 3:
    //    //r
    //    MoveToEx(hdc, 180, 125, NULL);

    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 180 + i, 125);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 185 + i, 124);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 190 + i, 123);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 195 + i, 124);
    //    }
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        LineTo(hdc, 200 + i, 125);
    //    }
    //    ///

    //case 2:
    //    // n
    //    MoveToEx(hdc, 140, 150, NULL);
    //    LineTo(hdc, 140, 120);
    //    LineTo(hdc, 170, 120);
    //    LineTo(hdc, 170, 150);
    //    MoveToEx(hdc, 180, 120, NULL);
    //    LineTo(hdc, 180, 150);
    //
    //case 1:
    //    // U

    //    MoveToEx(hdc, 100, 100, NULL);
    //    LineTo(hdc, 100, 150);
    //    LineTo(hdc, 105, 153);

    //    for (int i = 0; i < 5; ++i)
    //    {
    //        LineTo(hdc, 105 + i, 153);
    //    }
    //    for (int i = 0; i < 5; ++i)
    //    {
    //        LineTo(hdc, 110 + i, 154);
    //    }
    //    for (int i = 0; i < 5; ++i)
    //    {
    //        LineTo(hdc, 115 + i, 153);
    //    }
    //    for (int i = 0; i < 5; ++i)
    //    {
    //        LineTo(hdc, 120 + i, 152);
    //    }
    //    MoveToEx(hdc, 125, 152, NULL);
    //    LineTo(hdc, 125, 100);
    //    ///////
    //default:
    //    break;
    //}
ReleaseDC(hWnd, hdc);
break;

        EndPaint(hWnd, &ps);
        break;
         case WM_RBUTTONDOWN:
             /* dan -= 2;
              InvalidateRect(hWnd, NULL, true);
              PostMessage(hWnd, WM_PAINT, 0, 0);
              PostMessage(hWnd, WM_LBUTTONDOWN, 0, 0);*/

              // �̸�
             name -= 2;
             InvalidateRect(hWnd, NULL, true);
             PostMessage(hWnd, WM_PAINT, 0, 0);
             PostMessage(hWnd, WM_LBUTTONDOWN, 0, 0);

             break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}