#pragma once

// 2D ���⺤�͸� ǥ���ϱ� ���� ��ǥ
inline POINT pointMake(int x, int y)
{
	POINT pt = { x, y };
	return pt;
}

// ��ǥ �̵��� ���� �׸���
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}
 
// �簢�� ��ǥ�� ��ȯ
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

// �簢�� ������ ���� �簢�� �׸���
inline void DrawRectMake(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

// �簢�� ���� ���� ��ǥ�� ��ȯ
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

	return rc;
}

// �簢�� �׸���
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

// Ÿ�� �׸���
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

// Ÿ�� ���� ���� ����ؼ� �׸���
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

//inline RECT Colision(RECT rc, InputKey key)
//{
//
//}




//RECT RectInnerCenter(RECT* rcX, RECT* rcY, int width, int height)
//{
//	RECT rect = RectMakeCenter(rcX->left + 50, rcY->top + 50, width, height);
//	return rect;
//	
//}

//
//int RectCenterX(RECT rc)
//{
//	return ((rc.left + rc.right) / 2);
//}
//int RectCenterY(RECT rc)
//{
//	return ((rc.top + rc.bottom) / 2);
//}