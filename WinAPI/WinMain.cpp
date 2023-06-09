// WinmAin

#pragma region WinAPI
/*
=> API

- 운영체제가 응용 프로그램 개발을 위해 제공하는 함수의 집합
- 명령어의 집합으로 어플리케이션 프로그램에서 오퍼레이팅 시스템의 기본적인 기능을
  사용할 필요가 있을 경우 API에서 명령어 호출이 진행된다.

EX)                 WinMain을 통해 시동
하드웨어 --------- 운영체제 (Windows) -------------------응용 프로그램
( API 함수 )     <- 운영체제가 API 호출을 통해 알려줌     <- 장치들 정보 요청

-> 장점
- 운영체제가 같으면 같은 기능의 집합을 사용하기에 
  확장성, 연동성 및 유지보수면에서 유리하다. (윈도우즈 != 리눅스)
- 운영체제에 종속되기 때문에 개발 확장성이 아주 좋다. (게임)
=> Windows API 가 Root가 되어 외부 라이브러리로 가져와 부족한 기능을 채울 수 있다.

-> 단점
- 플랫폼에 고착화
  ㄴ C 언어 개발

=> API 구조
- 크게 진입점과 메세지 루프, Windows Procedure로 나뉜다.

*/
#pragma endregion


// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

//#include "framework.h"
//#include "WinAPI.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>

// 전역 변수
/*
=> 인스턴스
- 윈도우 OS가 현재 실행되고 있는 프로그램을 확인하기 위한 값
- 기본적으로 같은 프로그램이면 같은 인스턴스 값을 가진다.
- 클래스가 메모리에 실제로 구현된 실체
ㄴ 실행되고 있는 각각의 프로그램들
*/
HINSTANCE _hInstance;
// 윈도우 핸들 (윈도우 창)
HWND _hWnd;
// TEXT _T 준수모드를 끄면 빨간 줄 사라짐
// 윈도우 타이틀
LPTSTR _lpszClass = TEXT("Windows API");
//TCHAR* pszString = _T("Windows API");
int danX = 10;
int danY = 100;
int Y = 0;

int dan = 1;
char test[30];
int name = 0;



/*
유니코드 : 모든 언어 2Byte 처리
멀티바이트 : 영어 1Byte 한글 2Byte -> 영어에 최적화

=> TCHAR
- TCHAR형은 프로젝트의 문자셋 설정에 따라 자동적으로 char 또는 wchar_t로 Type_Casting
  되는 중간 매크로 자료형
- 멀티 바이트와 유니 코드 환경에서 별도의 수정 작업 없이 프로그램을 구동하기 위해서는
  TCHAR형으로 문자열을 표현할 것을 추천

- 일반적으로 윈도우 응용 프로그램에서 문자열 상수를 쓰기 위해서는 중간 설정에 따라
  char* 또는 wchar_t*로 변환해주는 _T 매크로를 이용해야 한다.

*/

/*
LPSTR           -> Long Pointer   = char*
LPCSTR          -> Constant       = const char*
LPCTSTR         -> t_string       = const tchar*
*/
#define MAX_LOADSTRING 100

// 전역 변수:
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:

// 콜백 함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/*
hInstance         : 프로그램 인스턴스 핸들
hPrevInstance     : 이전에 실행된 인스턴스 핸들 
lpszCmdParam      : 명령형으로 입력된 프로그램 인수
nCmdShow          : 프로그램이 시작될 형태 (최소화 / 크기 등등)
*/
// 진입점
/*
// 문자셋
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       TCHAR*     lpszCmdParam,
                       int       nCmdShow)
*/

// 사각형 중심점에 만들기
RECT RectMakeCenter(int x, int y, int width, int height)
{
    RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

    return rc;
}

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
    wndClass.lpszClassName = _lpszClass;
    // 메뉴 이름 => NULL 사용하지 않겠다.
    wndClass.lpszMenuName = NULL;
    // 윈도우 스타일 (다시 그리기 정보)
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // 1-2. 윈도우 클래스 등록
    RegisterClass(&wndClass);

    // 1-3. 화면에 보여줄 윈도우 창 생성
    _hWnd = CreateWindow
    (
        _lpszClass,                 // 윈도우 클래스 식별자
        _lpszClass,                 // 윈도우 타이틀 바 이름
        WS_EX_OVERLAPPEDWINDOW,     // 윈도우 스타일 (게임은 계속 그려짐)
        400,                        // 윈도우 화면 x 좌표
        100,                        // 윈도우 화면 y 좌표
        800,                        // 윈도우 화면 가로 크기
        800,                        // 윈도우 화면 세로 크기
        NULL,                       // 부모 윈도우 -> GetDesktopWindow
        (HMENU)NULL,                // 메뉴 핸들
        hInstance,                  // 인스턴스 지정
        NULL                        // 윈도의 자식 윈도우를 생성하면 지정하고 그렇지 않다면 NULL
                                    // ㄴ 필요에 의해서 사용하기도 하지만 지금은 NULL (창 여러개 가능)
    );

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

    RECT rc = { 100,100,200,200 };
 
    switch (iMessage)
    {
    case WM_CREATE:             // 생성자 
        break;

    case WM_PAINT:              // 출력에 관한 모든것을 담당한다. (문자, 그림, 도형등 화면에 보이는 모든것)
       
        hdc = BeginPaint(hWnd, &ps);
        SetPixel(hdc, 300, 200, RGB(255, 0, 0));

        for (int i = 0; i < 10000; ++i)
        {
            SetPixel(hdc, rand() % 800, rand() % 800, RGB(rand() % 255, rand() % 255, rand() % 255));
        }

        // 원 그리기
        Ellipse(hdc, 300, 100, 200, 200);
        // 사각형 그리기
        Rectangle(hdc, 100, 100, 200, 200);
        // 확장성을 위한 변수를 사용하자.
        Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

 
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
    // 윈도우 프로시저에서 처리되지 않은 나머지 메세지를 처리해 준다.
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


