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
#include "Stdafx.h"

// ���� ����
/*
=> �ν��Ͻ�
- ������ OS�� ���� ����ǰ� �ִ� ���α׷��� Ȯ���ϱ� ���� ��
- �⺻������ ���� ���α׷��̸� ���� �ν��Ͻ� ���� ������.
- Ŭ������ �޸𸮿� ������ ������ ��ü
�� ����ǰ� �ִ� ������ ���α׷���
*/

RECT rc;

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

    return message.wParam;
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

 
    switch (iMessage)
    {
    case WM_CREATE:             // ������ 
        rc = RectMakeCenter( 400, 400, 100, 100 );
        break;

    case WM_PAINT:              // ��¿� ���� ������ ����Ѵ�. (����, �׸�, ������ ȭ�鿡 ���̴� ����)
       
        hdc = BeginPaint(hWnd, &ps);
        Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
        //DrawRectMake(hdc, rc);

 
        EndPaint(hWnd, &ps);
        break;

    case WM_LBUTTONDOWN:
       

        break;
    case WM_RBUTTONDOWN:
    
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

    case WM_DESTROY:            
        PostQuitMessage(0);     
                                
        return 0;
    }
    // ������ ���ν������� ó������ ���� ������ �޼����� ó���� �ش�.
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


