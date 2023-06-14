#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };


#define MAX_LOADSTRING 100

// �ݹ� �Լ�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowSize(int x, int y, int width, int height);

int centerX;
int centerY;

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
    wndClass.lpszClassName = WINNAME;
    // �޴� �̸� => NULL ������� �ʰڴ�.
    wndClass.lpszMenuName = NULL;
    // ������ ��Ÿ�� (�ٽ� �׸��� ����)
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // 1-2. ������ Ŭ���� ���
    RegisterClass(&wndClass);

    // 1-3. ȭ�鿡 ������ ������ â ����
    _hWnd = CreateWindow
    (
        WINNAME,                         // ������ Ŭ���� �ĺ���
        WINNAME,                         // ������ Ÿ��Ʋ �� �̸�
        WINSTYLE,                        // ������ ��Ÿ�� (������ ��� �׷����ߵ�)
        WINSTART_X,                      // ������ ȭ�� x ��ǥ
        WINSTART_Y,                      // ������ ȭ�� y ��ǥ
        WINSIZE_X,                       // ������ ȭ�� ���� ũ��
        WINSIZE_Y,                       // ������ ȭ�� ���� ũ��
        NULL,                            // �θ� ������ -> GetDesktopWindow
        (HMENU)NULL,                     // �޴� �ڵ�
        hInstance,                       // �ν��Ͻ� ����
        NULL                             // ������ �ڽ� �����츦 �����ϸ� �����ϰ� �׷��� �ʴٸ� NULL
                                         // �� �ʿ信 ���ؼ� ����ϱ⵵ ������ ������ NULL (â ������ ����)
    );

    // Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ����ֱ� ����
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

    // ������â ���� ��
    // ====================================================================================
    // 
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

    static POINT pt = { 0, 0 };
    char strPT[128];

    switch (iMessage)
    {
    case WM_CREATE:             // ������ 
        centerX = WINSIZE_X / 2;
        centerY = WINSIZE_Y / 2;
        break;

    case WM_PAINT:              // ��¿� ���� ������ ����Ѵ�. (����, �׸�, ������ ȭ�鿡 ���̴� ����)
       
        hdc = BeginPaint(hWnd, &ps);

        // wsprintf() : ���� -> ���ڿ� ���
        wsprintf(strPT, "X : %d       y : %d", pt.x, pt.y);
        TextOut(hdc, 10, 10, strPT, strlen(strPT));
        
        Rectangle(hdc, centerX, centerY, 100, 100);

        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);

        InvalidateRect(hWnd, NULL, true);


        break;
    case WM_LBUTTONDOWN:
        centerX = RND->getInt(WINSIZE_X);
        centerY= RND->getInt(WINSIZE_Y);
        InvalidateRect(hWnd, NULL, true);
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

// Ŭ���̾�Ʈ â ������
void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0, width, height };

    // ���� ������ ũ�� ����
    // AdjustWindowRect() : RECT ����ü , ������ ��Ÿ��, �޴� ����
    AdjustWindowRect(&rc, WINSTYLE, false);

    // cx, cy : ���� ��ǥ
    // ���� RECT�� ������ ������ ������ ����
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left), (rc.bottom - rc.top), // ���� ��ǥ
        SWP_NOZORDER | SWP_NOMOVE);  
    // ������ �ɼ� ZORDER : �̹��� ��ħ ó��
    // NOZORDER : ���� ��� �켱��
}

