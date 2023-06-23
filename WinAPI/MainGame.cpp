#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plgImage = new GImage;
	_plgImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));
	_rc = RectMakeCenter(400, 400, 173, 291);

	_radian = 3.1415926535f;
	_degree = 180.0f;

	for (int i = 0; i < 5; ++i)
	{
		_star[i].x = cosf((i * 72 - 90 ) * PI / 180.0f) * 200 + WINSIZE_X / 2;
		_star[i].y = sinf((i * 72 - 90 ) * PI / 180.0f) * 200 + WINSIZE_Y / 2;
		
		/*
		�������� �׸��� ���� ����Ʈ 5��
		�� 72 = 360 / 5
		
		90 -> �ʱ� ����

		��׸��� -> ��������

		200 -> �߽ɿ����� �Ÿ�
		WINSIZE_X / Y -> ����
		*/
	}

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_bgImage);
	//SAFE_DELETE(_plgImage);


}

void MainGame::update(void)
{
	GameNode::update();


	if (!KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "���� Ȯ��", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5.0f;
		_rc.right += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5.0f;
		_rc.right -= 5.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 5.0f;
		_rc.bottom -= 5.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 5.0f;
		_rc.bottom += 5.0f;
	}

	GetLocalTime(&_st);
	_st.wSecond;
}

void MainGame::render(HDC hdc)
{
	// =======================================================
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	/*_bgImage->render(memDC, 0, 0);
	_plgImage->render(memDC, _rc.left, _rc.top);*/
	// =======================================================


	char strRadian[128];
	char strDegree[128];
	char strSecond[128];

	sprintf_s(strSecond, "%d ��", _st.wSecond);
	TextOut(memDC, WINSIZE_X / 2, 100, strSecond, strlen(strSecond));

	// ���ȿ��� ��׸���
	// �� 1 Radian = 180 / PI Degree
	sprintf_s(strRadian, "%.2f ���� ���� %.2f ��׸� ���� ����."
		, _radian, _radian * (180.0f / M_PI));
	TextOut(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2 - 100, strRadian, strlen(strRadian));

	// ��׸����� ��������
	// �� 1 Degree = PI / 180 Radian
	sprintf_s(strDegree, "%.2f ��׸� ���� %.2f ���� ���� ����."
		, _degree, _degree * (PI / 180.0f));
	TextOut(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2, strDegree, strlen(strDegree));

	// CreatePen(�� ��Ÿ��, ����, ����);
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN currentPen;
	
	currentPen = (HPEN)::SelectObject(memDC, pen);


	LineMake(memDC, WINSIZE_X / 2 - 100, WINSIZE_Y / 2 + 100, WINSIZE_X / 2 + 200, WINSIZE_Y / 2 + 100);

	DeleteObject(pen);


	// =======================================================
	/*
	

	*/


	SetPixel(memDC, _star[0].x, _star[0].y, RGB(255, 0, 0));

	for (int i = 0; i < 5; ++i)
	{
		EllipseMake(memDC, _star[i].x, _star[i].y, 10, 10);
	}

	this->getDoubleBuffer()->render(hdc, 0, 0);


}
