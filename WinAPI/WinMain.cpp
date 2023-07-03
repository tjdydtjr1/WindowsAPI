#include "Stdafx.h"
#include "MainGame.h"
 

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };


#define MAX_LOADSTRING 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


void setWindowSize(int x, int y, int width, int height);

MainGame* _mg;
//Motion* _mg;


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpszCmdParam,
                     int       nCmdShow)
{
    _mg = new MainGame;
  // _mg = new Motion;

    _hInstance = hInstance;
    WNDCLASS wndClass;

    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    wndClass.lpszClassName = WINNAME;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    
    // 1-2. ������ Ŭ���� ���
    RegisterClass(&wndClass);


// ��üȭ�� ����
#ifdef FULLSCREEN
    // ��ƺ� ��� ����ü (�ϸ� ���÷��� ���� ����ü)
    DEVMODE dm;

    ZeroMemory(&dm, sizeof(DEVMODE));
    dm.dmSize = sizeof(DEVMODE);
    dm.dmBitsPerPel = 32;               // 32��Ʈ Ʈ�� �÷�
    dm.dmPanningWidth = 1920;           // ����
    dm.dmPelsHeight = 1080;             // ����
    dm.dmDisplayFrequency = 60;         // �ֻ��� (��� �� 60Hz)

    // �ʵ� ����
    dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

    if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
    {
        ChangeDisplaySettings(&dm, 0);
    }

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

#else
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
#endif

    // Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ����ֱ� ����
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

    // ������â ���� ��
    // ====================================================================================
    // 
    // 1-4. ȭ�鿡 ������â �����ֱ�
    ShowWindow(_hWnd, nCmdShow);
    
    if (FAILED(_mg->init()))
    {
        return 0;
    }
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

    //// OS�� �����ϱ� ���� MSG�� �ִ�.
    //while (GetMessage(&message, 0, 0, 0))
    //{
    //    // Ű���� �ʼ� �Լ�
    //    TranslateMessage(&message);
    //    // ���ν����� ���Ϸ� �����ϴ� �޼��� �Լ�
    //    DispatchMessage(&message);
    //}



    _mg->release();

    UnregisterClass(WINNAME, hInstance);

    return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    
    return _mg->MainProc(hWnd, iMessage, wParam, lParam);

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

