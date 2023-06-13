/*
// # ��ũ�� # (������â �ʱ�ȭ)
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			400
#define WINSTART_Y			100
#define WINSIZE_X			800
#define WINSIZE_Y			800
// WS_CATION  : Ÿ��Ʋ�ٸ� ������ ���� �ɼ�
// WS_SYSMENU : ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â
#define WINSTYLE			WS_CATION | WS_SYSMENU

// # ��ũ�� �Լ� # -> ������ ��Ģ�̳� '\' ���������� ����Ͽ� ���� �� �ִ�.
// �� Ŭ�������� �����Ҵ�� �κ� ����
#define SAFE_DELETE(p)			{if(p){delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}



// # ���� ���� # - ������ ����
// �� ��ü ������Ʈ�� ���� ������ ������ �����ϱ⿡ ����ϴµ� �����ؾ� �Ѵ�.
// EX) Player Inven
// extern Ű����� �ٸ� ��� / cpp���� ������ �����ؼ� ���� ���� ����Ѵ�.
// �� ��ü
// �⺻������ ���� ������ Ű���带 �����ص� �⺻������ externȭ �Ǵ� ��찡 ����.
// Ŭ���� ������ ���� ��� ��� ��ü�� ��Ȯ�ϰ� ����� externȭ �� �� �ִ� (nullptr�� �ȵ�)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X ��ǥ�� Y ��ǥ�� ����� ��ǥ�� ������ �� ����� �Ѵ�.
extern POINT			_ptMouse;

*/
/*
wsprintf() : ���� -> ���ڿ� ���

���� ������ ũ�� ����
AdjustWindowRect() : RECT ����ü , ������ ��Ÿ��, �޴� ����
AdjustWindowRect(&rc, WINSTYLE, false);

cx, cy : ���� ��ǥ
���� RECT�� ������ ������ ������ ����
SetWindowPos(_hWnd, NULL, x, y,
(rc.right - rc.left), (rc.bottom - rc.top), // ���� ��ǥ
SWP_NOZORDER | SWP_NOMOVE);
������ �ɼ� ZORDER : �̹��� ��ħ ó��
NOZORDER : ���� ��� �켱��

WinMain() ���� �Լ��� ��ü�� ������ �ʰ� ���ð��� ����� ����
�� ���� �޸𸮻� WinMain ���� �������� �����ϴ� �Լ����� �ѹ��� �����ϸ� �ٽ�
�� �θ��� �ʱ� ������ ���� �÷����� �ʿ䰡 ����.

*/