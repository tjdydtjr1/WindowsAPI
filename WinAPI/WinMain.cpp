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
    
    // 1-2. 윈도우 클래스 등록
    RegisterClass(&wndClass);


// 전체화면 사용시
#ifdef FULLSCREEN
    // 디아비스 모드 구조체 (하면 디스플레이 관련 구조체)
    DEVMODE dm;

    ZeroMemory(&dm, sizeof(DEVMODE));
    dm.dmSize = sizeof(DEVMODE);
    dm.dmBitsPerPel = 32;               // 32비트 트루 컬러
    dm.dmPanningWidth = 1920;           // 가로
    dm.dmPelsHeight = 1080;             // 세로
    dm.dmDisplayFrequency = 60;         // 주사율 (재생 빈도 60Hz)

    // 필드 설정
    dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

    if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
    {
        ChangeDisplaySettings(&dm, 0);
    }

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

#else
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
#endif

    // 클라이언트 영역의 사이즈를 정확히 잡아주기 위해
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

    // 윈도우창 세팅 끝
    // ====================================================================================
    // 
    // 1-4. 화면에 윈도우창 보여주기
    ShowWindow(_hWnd, nCmdShow);
    
    if (FAILED(_mg->init()))
    {
        return 0;
    }
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

    //// OS와 소통하기 위해 MSG가 있다.
    //while (GetMessage(&message, 0, 0, 0))
    //{
    //    // 키보드 필수 함수
    //    TranslateMessage(&message);
    //    // 프로시져와 단일로 소통하는 메세지 함수
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

