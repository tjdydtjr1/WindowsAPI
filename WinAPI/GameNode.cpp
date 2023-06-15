#include "Stdafx.h"
#include "GameNode.h"
#include "CardGame.h"

HRESULT GameNode::init(void)
{
	// Ÿ�̸� �ʱ�ȭ
	SetTimer(_hWnd, 1, 50, NULL);

	// �Լ��� ���������� ���� �Ǿ����� �˸���.
	return S_OK;
}

void GameNode::release(void)
{
	// �����Ҵ�� ���� �������� �ʰ� �����ϸ� �޸� leak
	KillTimer(_hWnd, 1);
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

    HBRUSH brush_Red;
    HBRUSH brush_Blue;

    switch (iMessage)
    {
    case WM_TIMER:
        this->update();
        break;
    case WM_PAINT:              
        
        hdc = BeginPaint(hWnd, &ps);
        brush_Red = CreateSolidBrush(RGB(255, 0, 0));
        brush_Red = (HBRUSH)::SelectObject(hdc, brush_Red);
        
        // ���콺 ��ǥ Ȯ��
        wsprintf(text, "���콺 X : %d , ���콺 Y : %d", _ptMouse.x, _ptMouse.y);
        TextOut(hdc, 10, 10, text, strlen(text));
        
        // �⺻Ʋ ���
        this->render(hdc);
        
        // ���� �� �� ����        
        brush_Blue = CreateSolidBrush(RGB(0, 0, 255));
        brush_Blue = (HBRUSH)::SelectObject(hdc, brush_Blue);
        Rectangle(hdc, 100, 100, 200, 200);

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
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);

        return 0;
    }
    // ������ ���ν������� ó������ ���� ������ �޼����� ó���� �ش�.
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
