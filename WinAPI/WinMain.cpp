#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };


#define MAX_LOADSTRING 100

// 콜백 함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowSize(int x, int y, int width, int height);

int centerX;
int centerY;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpszCmdParam,
                     int       nCmdShow)
{
    // 인스턴스를 전역 변수에 담는다.
    _hInstance = hInstance;

    /*
    - WinMain의 역할
    1. 윈도우 창을 세팅 후 화면에 띄우기
     ㄴ 화면에 창을 띄우기 위해서는 4가지를 모두 처리해야 한다.

    2. 메세지 루프
    */

    // 1-1. 윈도우창 구조체 선언 및 초기화
    // WNDCLASS : 이 구조체는 윈도우즈 운영체제에서 윈도우 생성을 명령하기 위해서
    //            커스텀한 윈도우를 식별할 수 있는 정보 등을 기록하는 역할을 수행한다.
    WNDCLASS wndClass;

    // 클래스 여분 메모리 : 게임은 동적으로 관리 할당 X
    wndClass.cbClsExtra = 0;
    // 윈도우 여분 메모리 : 윈도우가 불필요한 메모리를 점유하기 때문에 할당 X
    wndClass.cbWndExtra = 0;
    // 백그라운드 :                                  하얀색으로 백그라운드를 그리겠다.
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    // 마우스 커서 : 현재 마우스 커서 모양 사용
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    // 창 아이콘 : 프로그램의 아이콘
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    // 윈도우를 소요한 프로그램의 식별자 정보
    wndClass.hInstance = hInstance;
    // 윈도우 프로시져 : 
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    // 클래스 이름(식별자 정보) : 아이콘 옆의 클래스 이름
    wndClass.lpszClassName = WINNAME;
    // 메뉴 이름 => NULL 사용하지 않겠다.
    wndClass.lpszMenuName = NULL;
    // 윈도우 스타일 (다시 그리기 정보)
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // 1-2. 윈도우 클래스 등록
    RegisterClass(&wndClass);

    // 1-3. 화면에 보여줄 윈도우 창 생성
    _hWnd = CreateWindow
    (
        WINNAME,                         // 윈도우 클래스 식별자
        WINNAME,                         // 윈도우 타이틀 바 이름
        WINSTYLE,                        // 윈도우 스타일 (게임은 계속 그려져야됨)
        WINSTART_X,                      // 윈도우 화면 x 좌표
        WINSTART_Y,                      // 윈도우 화면 y 좌표
        WINSIZE_X,                       // 윈도우 화면 가로 크기
        WINSIZE_Y,                       // 윈도우 화면 세로 크기
        NULL,                            // 부모 윈도우 -> GetDesktopWindow
        (HMENU)NULL,                     // 메뉴 핸들
        hInstance,                       // 인스턴스 지정
        NULL                             // 윈도의 자식 윈도우를 생성하면 지정하고 그렇지 않다면 NULL
                                         // ㄴ 필요에 의해서 사용하기도 하지만 지금은 NULL (창 여러개 가능)
    );

    // 클라이언트 영역의 사이즈를 정확히 잡아주기 위해
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

    // 윈도우창 세팅 끝
    // ====================================================================================
    // 
    // 1-4. 화면에 윈도우창 보여주기
    ShowWindow(_hWnd, nCmdShow);

    // 단일 프로젝트 (단기 / 과제)업데이트 처리 해야 한다.
    //UpdateWindow(_hWnd);

    // 2. 메세지 루프
    // MSG : 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
    MSG message;
    
    // 업데이트시 반드시 호출해야 됨 업데이트 후 메모리를 날려줘야 함
    //ZeroMemory(&message, sizeof(message));
    

    /*
    * ******************* 무조건 면접 질문에 나온다.
    * 메세지 루프 종류 , 1 2 번의 차이 활용 처
    => 메세지 루프 종류
    1. GetMessage (게임이 아닌 플랫폼에 유리)
    ㄴ 메세지를 꺼내올 수 있을 때 까지 멈춰있는 함수 (대기)
    ㄴ GetMessage는 메세지 큐로부터 하나의 메세지를 가져오는 역할을 수행한다.
    ㄴ 단, 메세지 큐가 비어 있을 경우(발생한 메세지 X) 메세지가 들어올때 까지 대기한다.

    2. PeekMessage (게임은 기본적으로 PeekMessage 사용)
    ㄴ 메세지가 없더라도 반환 되는 함수
    */
    
    // 기본적인 PeekMessage 방식
    // 여기에 고성능 타이머를 탑재해야함 c++은 가능
    while (true)
    {
        // PM_REMOVE = 1을 16진수로 바꿔놓음 int형은 너무 크기 때문
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

    // OS와 소통하기 위해 MSG가 있다.
    while (GetMessage(&message, 0, 0, 0))
    {
        // 키보드 필수 함수
        TranslateMessage(&message);
        // 프로시져와 단일로 소통하는 메세지 함수
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
    case WM_CREATE:             // 생성자 
        centerX = WINSIZE_X / 2;
        centerY = WINSIZE_Y / 2;
        break;

    case WM_PAINT:              // 출력에 관한 모든것을 담당한다. (문자, 그림, 도형등 화면에 보이는 모든것)
       
        hdc = BeginPaint(hWnd, &ps);

        // wsprintf() : 숫자 -> 문자열 출력
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
    // 윈도우 프로시저에서 처리되지 않은 나머지 메세지를 처리해 준다.
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// 클라이언트 창 사이즈
void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0, width, height };

    // 실제 윈도우 크기 조정
    // AdjustWindowRect() : RECT 구조체 , 윈도우 스타일, 메뉴 여부
    AdjustWindowRect(&rc, WINSTYLE, false);

    // cx, cy : 중점 좌표
    // 얻어온 RECT의 정보로 윈도우 사이즈 세팅
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left), (rc.bottom - rc.top), // 중점 좌표
        SWP_NOZORDER | SWP_NOMOVE);  
    // 렌더링 옵션 ZORDER : 이미지 겹침 처리
    // NOZORDER : 가장 상단 우선권
}

