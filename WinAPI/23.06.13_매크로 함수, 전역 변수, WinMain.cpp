/*
// # 매크로 # (윈도우창 초기화)
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			400
#define WINSTART_Y			100
#define WINSIZE_X			800
#define WINSIZE_Y			800
// WS_CATION  : 타이틀바를 가지기 위한 옵션
// WS_SYSMENU : 제목 표시줄에 컨트롤 메뉴 상자 창
#define WINSTYLE			WS_CATION | WS_SYSMENU

// # 매크로 함수 # -> 한줄이 원칙이나 '\' 역슬래쉬를 사용하여 이을 수 있다.
// ㄴ 클래스에서 동적할당된 부분 해제
#define SAFE_DELETE(p)			{if(p){delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}



// # 전역 변수 # - 데이터 영역
// ㄴ 전체 프로젝트의 전역 변수로 접근이 가능하기에 사용하는데 유의해야 한다.
// EX) Player Inven
// extern 키워드는 다른 헤더 / cpp에서 변수를 공유해서 쓰기 위해 사용한다.
// ㄴ 객체
// 기본적으로 전역 변수는 키워드를 생략해도 기본적으로 extern화 되는 경우가 많다.
// 클래스 참조와 같은 경우 대상 객체를 명확하게 해줘야 extern화 할 수 있다 (nullptr도 안됨)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X 좌표와 Y 좌표를 평면의 좌표에 정의할 때 사용을 한다.
extern POINT			_ptMouse;

*/
/*
wsprintf() : 숫자 -> 문자열 출력

실제 윈도우 크기 조정
AdjustWindowRect() : RECT 구조체 , 윈도우 스타일, 메뉴 여부
AdjustWindowRect(&rc, WINSTYLE, false);

cx, cy : 중점 좌표
얻어온 RECT의 정보로 윈도우 사이즈 세팅
SetWindowPos(_hWnd, NULL, x, y,
(rc.right - rc.left), (rc.bottom - rc.top), // 중점 좌표
SWP_NOZORDER | SWP_NOMOVE);
렌더링 옵션 ZORDER : 이미지 겹침 처리
NOZORDER : 가장 상단 우선권

WinMain() 에서 함수나 객체로 만들지 않고 세팅값을 까놓은 이유
ㄴ 스택 메모리상에 WinMain 위로 여러가지 세팅하는 함수들을 한번만 설정하면 다시
ㄴ 부르지 않기 때문에 굳이 올려놓을 필요가 없다.

*/