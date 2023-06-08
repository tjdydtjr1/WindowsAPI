// WinmAin

#pragma region WinAPI
/*
=> API

- �ü���� ���� ���α׷� ������ ���� �����ϴ� �Լ��� ����
- ��ɾ��� �������� ���ø����̼� ���α׷����� ���۷����� �ý����� �⺻���� �����
  ����� �ʿ䰡 ���� ��� API���� ��ɾ� ȣ���� ����ȴ�.

EX)                 WinMain�� ���� �õ�
�ϵ���� --------- �ü�� (Windows) -------------------���� ���α׷�
( API �Լ� )     <- �ü���� API ȣ���� ���� �˷���     <- ��ġ�� ���� ��û

-> ����
- �ü���� ������ ���� ����� ������ ����ϱ⿡ 
  Ȯ�强, ������ �� ���������鿡�� �����ϴ�. (�������� != ������)
- �ü���� ���ӵǱ� ������ ���� Ȯ�强�� ���� ����. (����)
=> Windows API �� Root�� �Ǿ� �ܺ� ���̺귯���� ������ ������ ����� ä�� �� �ִ�.

-> ����
- �÷����� ����ȭ
  �� C ��� ����

=> API ����
- ũ�� �������� �޼��� ����, Windows Procedure�� ������.

*/
#pragma endregion


// WinAPI.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

//#include "framework.h"
//#include "WinAPI.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>

// ���� ����
/*
=> �ν��Ͻ�
- ������ OS�� ���� ����ǰ� �ִ� ���α׷��� Ȯ���ϱ� ���� ��
- �⺻������ ���� ���α׷��̸� ���� �ν��Ͻ� ���� ������.
- Ŭ������ �޸𸮿� ������ ������ ��ü
�� ����ǰ� �ִ� ������ ���α׷���
*/
HINSTANCE _hInstance;
// ������ �ڵ� (������ â)
HWND _hWnd;
// TEXT _T �ؼ���带 ���� ���� �� �����
// ������ Ÿ��Ʋ
LPTSTR _lpszClass = TEXT("Windows API");
//TCHAR* pszString = _T("Windows API");
int danX = 10;
int danY = 100;
int Y = 0;

int dan = 1;
char test[30];
int name = 0;

RECT rect;

/*
�����ڵ� : ��� ��� 2Byte ó��
��Ƽ����Ʈ : ���� 1Byte �ѱ� 2Byte -> ��� ����ȭ

=> TCHAR
- TCHAR���� ������Ʈ�� ���ڼ� ������ ���� �ڵ������� char �Ǵ� wchar_t�� Type_Casting
  �Ǵ� �߰� ��ũ�� �ڷ���
- ��Ƽ ����Ʈ�� ���� �ڵ� ȯ�濡�� ������ ���� �۾� ���� ���α׷��� �����ϱ� ���ؼ���
  TCHAR������ ���ڿ��� ǥ���� ���� ��õ

- �Ϲ������� ������ ���� ���α׷����� ���ڿ� ����� ���� ���ؼ��� �߰� ������ ����
  char* �Ǵ� wchar_t*�� ��ȯ���ִ� _T ��ũ�θ� �̿��ؾ� �Ѵ�.

*/

/*
LPSTR           -> Long Pointer   = char*
LPCSTR          -> Constant       = const char*
LPCTSTR         -> t_string       = const tchar*
*/
#define MAX_LOADSTRING 100

// ���� ����:
// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:

// �ݹ� �Լ�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/*
hInstance         : ���α׷� �ν��Ͻ� �ڵ�
hPrevInstance     : ������ ����� �ν��Ͻ� �ڵ� 
lpszCmdParam      : ��������� �Էµ� ���α׷� �μ�
nCmdShow          : ���α׷��� ���۵� ���� (�ּ�ȭ / ũ�� ���)
*/
// ������
/*
// ���ڼ�
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       TCHAR*     lpszCmdParam,
                       int       nCmdShow)
*/

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpszCmdParam,
                     int       nCmdShow)
{
    // �ν��Ͻ��� ���� ������ ��´�.
    _hInstance = hInstance;

    /*
    - WinMain�� ����
    1. ������ â�� ���� �� ȭ�鿡 ����
     �� ȭ�鿡 â�� ���� ���ؼ��� 4������ ��� ó���ؾ� �Ѵ�.

    2. �޼��� ����
    */

    // 1-1. ������â ����ü ���� �� �ʱ�ȭ
    // WNDCLASS : �� ����ü�� �������� �ü������ ������ ������ ����ϱ� ���ؼ�
    //            Ŀ������ �����츦 �ĺ��� �� �ִ� ���� ���� ����ϴ� ������ �����Ѵ�.
    WNDCLASS wndClass;

    // Ŭ���� ���� �޸� : ������ �������� ���� �Ҵ� X
    wndClass.cbClsExtra = 0;
    // ������ ���� �޸� : �����찡 ���ʿ��� �޸𸮸� �����ϱ� ������ �Ҵ� X
    wndClass.cbWndExtra = 0;
    // ��׶��� :                                  �Ͼ������ ��׶��带 �׸��ڴ�.
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    // ���콺 Ŀ�� : ���� ���콺 Ŀ�� ��� ���
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    // â ������ : ���α׷��� ������
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    // �����츦 �ҿ��� ���α׷��� �ĺ��� ����
    wndClass.hInstance = hInstance;
    // ������ ���ν��� : 
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    // Ŭ���� �̸�(�ĺ��� ����) : ������ ���� Ŭ���� �̸�
    wndClass.lpszClassName = _lpszClass;
    // �޴� �̸� => NULL ������� �ʰڴ�.
    wndClass.lpszMenuName = NULL;
    // ������ ��Ÿ�� (�ٽ� �׸��� ����)
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // 1-2. ������ Ŭ���� ���
    RegisterClass(&wndClass);

    // 1-3. ȭ�鿡 ������ ������ â ����
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

    // 1-4. ȭ�鿡 ������â �����ֱ�
    ShowWindow(_hWnd, nCmdShow);

    // ���� ������Ʈ (�ܱ� / ����)������Ʈ ó�� �ؾ� �Ѵ�.
    //UpdateWindow(_hWnd);

    // 2. �޼��� ����
    // MSG : �ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
    MSG message;
    
    // ������Ʈ�� �ݵ�� ȣ���ؾ� �� ������Ʈ �� �޸𸮸� ������� ��
    //ZeroMemory(&message, sizeof(message));
    

    /*
    * ******************* ������ ���� ������ ���´�.
    * �޼��� ���� ���� , 1 2 ���� ���� Ȱ�� ó
    => �޼��� ���� ����
    1. GetMessage (������ �ƴ� �÷����� ����)
    �� �޼����� ������ �� ���� �� ���� �����ִ� �Լ� (���)
    �� GetMessage�� �޼��� ť�κ��� �ϳ��� �޼����� �������� ������ �����Ѵ�.
    �� ��, �޼��� ť�� ��� ���� ���(�߻��� �޼��� X) �޼����� ���ö� ���� ����Ѵ�.

    2. PeekMessage (������ �⺻������ PeekMessage ���)
    �� �޼����� ������ ��ȯ �Ǵ� �Լ�
    */
    
    // �⺻���� PeekMessage ���
    // ���⿡ ���� Ÿ�̸Ӹ� ž���ؾ��� c++�� ����
    while (true)
    {
        // PM_REMOVE = 1�� 16������ �ٲ���� int���� �ʹ� ũ�� ����
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

    // OS�� �����ϱ� ���� MSG�� �ִ�.
    while (GetMessage(&message, 0, 0, 0))
    {
        // Ű���� �ʼ� �Լ�
        TranslateMessage(&message);
        // ���ν����� ���Ϸ� �����ϴ� �޼��� �Լ�
        DispatchMessage(&message);
    }

    /*
    TranslateMessage
    �� Ű������ �Է� �޼��� ó���� ���
    �� �Էµ� Ű�� ���� Ű���� Ȯ�� �� �빮�� Ȥ�� �ҹ���, �ѱ� / ���������� ����
       WM_CHAR �޼����� �߻� ��Ų��.
    
    DispatchMessage
    �� ������ ���ν������� ���޵� �޼����� ���� ������� ������ �ش�.

    */
    return message.wParam;
}
// =====================================================================
// CALLBACK �Լ�
// �����Ϸ��� ������ �۵� (���α׷� �̻� �� ��ȣ�� ����)
// �Ǽ��� �־ ���α׷��� �۵��� �� �ִ�. => 1. ��Ÿ 2. ���� ����


/*
hWnd : ��� �����쿡�� �߻��� �޼������� ����
iMessage : �޼��� ���� ��ȣ
wPARAM : unsigned int -> ���콺 ��ư�� ����, Ű���� ���� Ű�� ���¸� ����
lPARAM :  unsigned long -> ���콺 Ŭ�� ��ǥ�� ����
*/
// ������ ���ν���
// ��а��� �̰� switch�� �ȿ� �ڵ��Ѵ�. Ŭ���� x �Լ��� ����Ѵ�.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    /*
    => Window Procedure
    �� �޼����� �ü���� ���� -> ������ �ü���� ȣ��ǰ� ���ش�.
    �� WinMain()�� �ƴ� �ü���� ���� ȣ���� �Ǵ� �ݹ�(Callback) �Լ�
    �� �����츦 ������ �� �ݵ�� ������ ����� �Ѵ�.
    
    - ����ؾ� �Ұ� ������ ���ν��� ���ο����� �����쿡�� �߻��� ��� �޼�����
      ó���ϴ°��� �ƴ϶� Ư�� �޼������� ó���ϰ� ������ �޼����� 
      DefWindowProc �Լ��� ó���ϵ��� ������ �����ϴ°� �Ϲ����̴�.

    - �� ������ �ݵ�� ����Ұ�
    */

    // �ڵ� DC => GDI(�׷��� ����̹� �������̽�)�� �׻� ��������
    // GDI(ȸ��x) => GDI+ (GDI �������� -> jpg,png ��밡�� ȸ���� ������ ��������� ����)
    // �� BMP (��Ʈ��) -> �����찡 ���� ��ȣ�ϴ� ��������
    // DW -> Drp
    
    // WinAPI �ʼ�
    HDC hdc;
    // ����Ʈ ����ü
    PAINTSTRUCT ps;

    //char str[] = "�׷�";
    /*
    char[] : ���� ����
    char*  : ���� �Ұ���
    */

    switch (iMessage)
    {
    case WM_CREATE:             // ������ 
        break;

    case WM_PAINT:              // ��¿� ���� ������ ����Ѵ�. (����, �׸�, ������ ȭ�鿡 ���̴� ����)
        
        /*
        strcpy(x, y) : y�� x�� ����
        strcat(x, y) : x ���ڿ� + y ���ڿ�
        strlen(x, y) : ���ڿ� ����
        strcmp(x, y) : �� ���ڿ��� ������ Ȯ��
        �� x, y ���� => 0 ����
        �� x < y     => -1 ����
        �� x > y     => 1 ����

        ��Ƽ����Ʈ      �����ڵ�       �����Ϸ��� �˾Ƽ�
        strcpy      -> wcscpy   ->    _tcscpy       => ����
        strcat      -> wcscat   ->    _tcscat       => �̾������
        strlen      -> wcslen   ->    _tcslen       => ����
        strcmp      -> wcscmp   ->    _tcscmp       => ��
        strtok      -> wcstok   ->    _tcstok       => �ڸ���
        strchr      -> wcschr   ->    _tcschr       => ���� ã��
        strstr      -> wcsstr   ->    _tcsstr       => ���ڿ� ã��
        */
        // ��ī��Ʈ ��ǥ(���ϴ�) != ������ ��ǥ��(�»��)

        //// TextOut : ���� ���(hdc, x, y, ���ڿ�, ���ڿ� ����)
        //TextOut(hdc, 300, 300, "������ �ʹ� ��մ�", strlen("������ �ʹ� ��մ�"));
        //// �� strlen�� �Ҵ���� �޸𸮿� ���ε� �� ���ڿ����� NULL���� ������ ���ڿ� ����
        //
        //// ���ڿ� ���ڻ� ����
        //SetTextColor(hdc, RGB(255, 0, 0));
        //TextOut(hdc, 300, 400, "���� �� �� ���ּ���.", strlen("���� �� �� ���ּ���."));

        hdc = BeginPaint(hWnd, &ps);
       /* MoveToEx(hdc, 10, 10, NULL);
        LineTo(hdc, 20, 10);

        MoveToEx(hdc, 400, 400, NULL);
        LineTo(hdc, 200, 200);
*/
        EndPaint(hWnd, &ps);
        break;

        // ���콺 ���ʹ�ư�� ������ �� �޼��� �߻�
    case WM_LBUTTONDOWN:
        // WM_PAINT�� �ƴϱ⿡ GetDC�� ����Ͽ� �����´�.
        hdc = GetDC(hWnd);
    /*    ++dan;
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
        // �̸�
        //++name;
        //if (name == 1)
        //{
        //    // ��
        //    MoveToEx(hdc, 100, 150, NULL);
        //    LineTo(hdc, 10, 250);

        //    MoveToEx(hdc, 50, 200, NULL);
        //    LineTo(hdc, 100, 250);

        //    MoveToEx(hdc, 60, 200, NULL);
        //    LineTo(hdc, 120, 200);

        //    MoveToEx(hdc, 120, 130, NULL);
        //    LineTo(hdc, 120, 270);
        //}
        //else if (name == 2)
        //{
        //    // ��
        //    MoveToEx(hdc, 200, 130, NULL);
        //    LineTo(hdc, 201, 130);


        //    MoveToEx(hdc, 260, 160, NULL);
        //    LineTo(hdc, 260, 180);

        //    LineTo(hdc, 250, 190);
        //    LineTo(hdc, 240, 200);
        //    LineTo(hdc, 220, 200);
        //    LineTo(hdc, 200, 180);
        //    LineTo(hdc, 200, 160);
        //    LineTo(hdc, 220, 140);
        //    LineTo(hdc, 240, 140);
        //    LineTo(hdc, 260, 160);

        //    MoveToEx(hdc, 240, 200, NULL);
        //    LineTo(hdc, 240, 220);
        //    MoveToEx(hdc, 220, 200, NULL);
        //    LineTo(hdc, 220, 220);
        //    MoveToEx(hdc, 160, 220, NULL);
        //    LineTo(hdc, 300, 220);

        //    MoveToEx(hdc, 260, 260, NULL);
        //    LineTo(hdc, 260, 280);

        //    LineTo(hdc, 250, 290);
        //    LineTo(hdc, 240, 300);
        //    LineTo(hdc, 220, 300);
        //    LineTo(hdc, 200, 280);
        //    LineTo(hdc, 200, 260);
        //    LineTo(hdc, 220, 240);
        //    LineTo(hdc, 240, 240);
        //    LineTo(hdc, 260, 260);
        //}
        //else if (name == 3)
        //{
        //    // ��
        //    MoveToEx(hdc, 400, 150, NULL);
        //    LineTo(hdc, 310, 250);

        //    MoveToEx(hdc, 350, 200, NULL);
        //    LineTo(hdc, 400, 250);

        //    MoveToEx(hdc, 460, 200, NULL);
        //    LineTo(hdc, 400, 200);

        //    MoveToEx(hdc, 460, 130, NULL);
        //    LineTo(hdc, 460, 270);

        //    MoveToEx(hdc, 350, 300, NULL);
        //    LineTo(hdc, 470, 300);
        //    LineTo(hdc, 470, 350);
        //}
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
        // U
        MoveToEx(hdc, 100, 100, NULL);
        LineTo(hdc, 100, 150);
        LineTo(hdc, 105, 153);
      
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 105 + i, 153);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 110 + i, 154);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 115 + i, 153);
        }
        for (int i = 0; i < 5; ++i)
        {
            LineTo(hdc, 120 + i, 152);
        }
        MoveToEx(hdc, 125, 152, NULL);
        LineTo(hdc, 125, 100);
      ///////
        
        // n
        MoveToEx(hdc, 140, 150, NULL);
        LineTo(hdc, 140, 120);
        LineTo(hdc, 170, 120);
        LineTo(hdc, 170, 150);
        MoveToEx(hdc, 180, 120, NULL);
        LineTo(hdc, 180, 150);

        //r
        MoveToEx(hdc, 180, 125, NULL);
       
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 180 + i, 125);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 185 + i, 124);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 190 + i, 123);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 195 + i, 124);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 200 + i, 125);
        }
        ///
        // e
        MoveToEx(hdc, 210, 125, NULL);
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 215 + i, 125);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 220 + i, 124);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 225 + i, 125);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 230 + i, 126);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 235 + i, 127);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 240 + i, 130);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 240 + i, 132);
        }
        for (int i = 0; i < 3; ++i)
        {
            LineTo(hdc, 240 + i, 130 + i);
        }
        LineTo(hdc, 240, 140);
        LineTo(hdc, 210, 140);
        LineTo(hdc, 210, 125);
        LineTo(hdc, 210, 150);
        LineTo(hdc, 215, 155);
        LineTo(hdc, 235, 155);

        // a
        MoveToEx(hdc, 280, 140, NULL);
        LineTo(hdc, 280, 144);
        LineTo(hdc, 280, 150);
        LineTo(hdc, 275, 155);
        LineTo(hdc, 270, 156);
        LineTo(hdc, 265, 157);
        LineTo(hdc, 270, 157);
        LineTo(hdc, 265, 158);
        LineTo(hdc, 260, 158);
        LineTo(hdc, 255, 156);
        LineTo(hdc, 250, 155);
        LineTo(hdc, 252, 150);
        LineTo(hdc, 250, 152);
        LineTo(hdc, 250, 150);
        LineTo(hdc, 250, 148);
        LineTo(hdc, 253, 146);
        LineTo(hdc, 253, 144);
        LineTo(hdc, 253, 142);
        LineTo(hdc, 256, 142);
        LineTo(hdc, 260, 141);
        LineTo(hdc, 265, 141);
        LineTo(hdc, 270, 140);
        LineTo(hdc, 275, 139);
        LineTo(hdc, 280, 139);
        LineTo(hdc, 280, 135);
        LineTo(hdc, 280, 140);
        LineTo(hdc, 278, 145);
        LineTo(hdc, 280, 144);
        LineTo(hdc, 280, 130);
        LineTo(hdc, 278, 129);
        LineTo(hdc, 277, 128);
        LineTo(hdc, 275, 126);
        LineTo(hdc, 270, 124);
        LineTo(hdc, 265, 123);
        LineTo(hdc, 260, 123);


        // l
        MoveToEx(hdc, 300, 123, NULL);
        LineTo(hdc, 300, 160);

        // E
        MoveToEx(hdc, 320, 120, NULL);
        LineTo(hdc, 350, 120);
        MoveToEx(hdc, 320, 120, NULL);
        LineTo(hdc, 320, 140);
        LineTo(hdc, 350, 140);
        MoveToEx(hdc, 320, 140, NULL);
        LineTo(hdc, 320, 160);
        MoveToEx(hdc, 320, 160, NULL);
        LineTo(hdc, 350, 160);

        // n
        MoveToEx(hdc, 360, 160, NULL);
        LineTo(hdc, 360, 125);
        LineTo(hdc, 365, 120);
        LineTo(hdc, 370, 119);
        LineTo(hdc, 375, 118);
        LineTo(hdc, 380, 119);
        LineTo(hdc, 385, 120);
        LineTo(hdc, 390, 122);
        LineTo(hdc, 390, 160);

        // g
        MoveToEx(hdc, 415, 120, NULL);
        LineTo(hdc, 430, 120);
        MoveToEx(hdc, 415, 120, NULL);
        LineTo(hdc, 410, 122);
        LineTo(hdc, 405, 124);
        LineTo(hdc, 405, 130);
        LineTo(hdc, 410, 134);
        LineTo(hdc, 415, 135);
        LineTo(hdc, 420, 136);
        LineTo(hdc, 425, 137);
        LineTo(hdc, 435, 137);
        LineTo(hdc, 435, 145);
        LineTo(hdc, 430, 146);
        LineTo(hdc, 430, 148);
        LineTo(hdc, 420, 150);
        LineTo(hdc, 415, 150);
        LineTo(hdc, 410, 150);
        MoveToEx(hdc, 415, 120, NULL);
        LineTo(hdc, 430, 120);
        LineTo(hdc, 435, 125);
        LineTo(hdc, 435, 128);
        LineTo(hdc, 435, 130);
        LineTo(hdc, 435, 135);
        LineTo(hdc, 435, 150);

        // i
        MoveToEx(hdc, 450, 125, NULL);
        LineTo(hdc, 450, 160);
        MoveToEx(hdc, 450, 120, NULL);

        for (int i = 0; i < 10; ++i)
        {
            LineTo(hdc, 445 + i, 120);
        }

        // n

        //
        // ����� DC ����
        ReleaseDC(hWnd, hdc);
        break;

    case WM_RBUTTONDOWN:
        /*dan -= 2;
        InvalidateRect(hWnd, NULL, true);
        PostMessage(hWnd, WM_PAINT, 0, 0);
        PostMessage(hWnd, WM_LBUTTONDOWN, 0, 0);*/

        // �̸�
        /*name -= 2;
        InvalidateRect(hWnd, NULL, true);
        PostMessage(hWnd, WM_PAINT, 0, 0);
        PostMessage(hWnd, WM_LBUTTONDOWN, 0, 0);*/




        break;

    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_LEFT:
           
            break;
        case VK_RIGHT:
            break;
        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;

        }
        break;

    case WM_DESTROY:            // �Ҹ���
        PostQuitMessage(0);     // �� �Լ��� �޼��� ť�� Quit �޼����� ������ ������ �Ѵ�.
                                // ��, Quit �޼����� �����ϴ� ���� GetMessage �Լ��� FALSE�� ��ȯ������
                                // �޼��� ������ ���� �ȴ�.
        
        return 0;
    }
    // ������ ���ν������� ó������ ���� ������ �޼����� ó���� �ش�.
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


