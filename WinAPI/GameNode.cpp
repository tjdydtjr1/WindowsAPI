#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	// 타이머 초기화
	SetTimer(_hWnd, 1, 60, NULL);
    // 코딩 컨벤션을 맞추기 위해 RND는 초기화 기능이 없지만 초기화를 만들어 준다.
    RND->init();
    KEYMANAGER->init();

    this->setDoubleBuffer();


	// 함수가 성공적으로 실행 되었음을 알린다.
	return S_OK;
}

void GameNode::setDoubleBuffer(void)
{
    _DoubleBuffer = new GImage;
    _DoubleBuffer->init(WINSIZE_X, WINSIZE_Y);

}


void GameNode::release(void)
{
	// 동적할당과 같이 삭제하지 않고 종료하면 메모리 leak
	KillTimer(_hWnd, 1);

    RND->releaseSingleton();
    KEYMANAGER->releaseSingleton();

    SAFE_DELETE(_DoubleBuffer);

}

void GameNode::update(void)
{
    InvalidateRect(_hWnd, NULL, false);
}

void GameNode::render(HDC hdc)
{
	// ! Do Noting
}

// 메인 프로시져
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    
    
    switch (iMessage)
    {
    case WM_TIMER:
        this->update();
        break;
    case WM_PAINT:              
        
        hdc = BeginPaint(hWnd, &ps);
        
        this->render(hdc);

        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);
        
        break;

    case WM_LBUTTONDOWN:

        break;
    case WM_RBUTTONDOWN:

        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
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
