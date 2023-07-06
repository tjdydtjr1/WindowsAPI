#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
    
    return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
    _hdc = GetDC(_hWnd);
    _managerInit = managerInit;

    if (_managerInit)
    {
        // 로케일 설정
        // ㄴ 프로그램의 명령어가 여러가지 언어로 주어져 있는 경우 이 중에 어떤 언어의 것을
        //    출력할 것인지에 대한 설정 
        setlocale(LC_ALL, "korean");

        // 타이머 초기화
        SetTimer(_hWnd, 1, 30, NULL);
        // 코딩 컨벤션을 맞추기 위해 RND는 초기화 기능이 없지만 초기화를 만들어 준다.
        RND->init();
        KEYMANAGER->init();
        IMAGEMANAGER->init();
        FONTMANAGER->init();
        TEMPSOUNDMANAGER->init();

    }
   
    return S_OK;
}

// 백버퍼로 변경
// 주석 처리
//void GameNode::setDoubleBuffer(void)
//{
//    _DoubleBuffer = new GImage;
//    _DoubleBuffer->init(WINSIZE_X, WINSIZE_Y);
//
//}

void GameNode::release(void)
{
    if (_managerInit)
    {
        // 동적할당과 같이 삭제하지 않고 종료하면 메모리 leak
        KillTimer(_hWnd, 1);

        RND->releaseSingleton();
        KEYMANAGER->releaseSingleton();

        IMAGEMANAGER->release();
        IMAGEMANAGER->releaseSingleton();
        TEMPSOUNDMANAGER->releaseSingleton();
    }
	
    ReleaseDC(_hWnd, _hdc);

}

void GameNode::update(void)
{
    InvalidateRect(_hWnd, NULL, false);
}

void GameNode::render(void)
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
        
        this->render();

        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);
        
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
