#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	// Ÿ�̸� �ʱ�ȭ
	SetTimer(_hWnd, 1, 1, NULL);
    
    // �ڵ� �������� ���߱� ���� RND�� �ʱ�ȭ ����� ������ �ʱ�ȭ�� ����� �ش�.
    RND->init();
    KEYMANAGER->init();

	// �Լ��� ���������� ���� �Ǿ����� �˸���.
	return S_OK;
}

void GameNode::release(void)
{
	// �����Ҵ�� ���� �������� �ʰ� �����ϸ� �޸� leak
	KillTimer(_hWnd, 1);

    RND->releaseSingleton();
    KEYMANAGER->releaseSingleton();

}

void GameNode::update(void)
{
	InvalidateRect(_hWnd, NULL, true);
}

void GameNode::render(HDC hdc)
{
	// ! Do Noting
}

// ���� ���ν���
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    char text[128];
    
    switch (iMessage)
    {
    case WM_TIMER:
        this->update();
        break;
    case WM_PAINT:              
        
        hdc = BeginPaint(hWnd, &ps);
        // ���콺 ��ǥ Ȯ��
        wsprintf(text, "���콺 X : %d , ���콺 Y : %d", _ptMouse.x, _ptMouse.y);
        TextOut(hdc, 10, 10, text, strlen(text));

        this->render(hdc);
        
        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = LOWORD(lParam);
        
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
        case VK_SPACE:
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
