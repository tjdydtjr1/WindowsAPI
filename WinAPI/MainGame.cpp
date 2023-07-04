#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);
	
	//IMAGEMANAGER->addImage("Track", "Resources/Images/BackGround/Track.bmp", WINSIZE_X, WINSIZE_Y);
	
	_blackHole = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
	
	for (int i = 0; i < MAX_OBJECT; ++i)
	{
		Object _ob;
		_objectVec.push_back(_ob);
	}

	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		_iter->isVec = true;
		_iter->isCreate = false;
		_iter->theta = 0;
		_iter->_isEffect = false;

	}
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
}

void MainGame::update(void)
{
	GameNode::update();
	
	// ������Ʈ ����
	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		if (!_iter->isCreate)
		{
			_iter->x = rand() % WINSIZE_X;
			_iter->y = rand() % WINSIZE_Y;
			_iter->xy.x = cosf(_iter->theta - 90 * PI / 180.f) * OBJECT_SPEED;
			_iter->xy.y = sinf(_iter->theta - 90 * PI / 180.f) * OBJECT_SPEED;
			_iter->rc = RectMakeCenter(_iter->x + _iter->xy.x, _iter->y + _iter->xy.y, 10, 10);
			_iter->isCreate = true;
			_iter->_isEffect = true;
			_iter->theta = 0;
		}
	}

	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		if (_iter->isCreate)
		{
			if (_iter->isVec)
			{
				_iter->theta = atan2f((float)(_blackHole.top + 50 - _iter->rc.top + 5), (float)(_blackHole.left + 50 - _iter->rc.left + 5)) * 180 / PI;

				printf("���� : %d, ��ġ : %d , %d\n", _iter[0].theta, _iter[0].rc.left, _iter[0].rc.top);

				_iter->xy.x = cosf(_iter->theta * PI / 180.f) * OBJECT_SPEED;
				_iter->xy.y = sinf(_iter->theta * PI / 180.f) * OBJECT_SPEED;

				_iter->x += _iter->xy.x;
				_iter->y += _iter->xy.y;
				_iter->rc = RectMakeCenter(_iter->x, _iter->y, 10, 10);
			}
			

			if (IntersectRect(&_temp, &_blackHole, &_iter->rc) && _iter->isVec)
			{
				_iter->isVec = false;
				
				_iter->theta = _iter->theta - 180;

				_iter->xy.x = cosf(_iter->theta * PI / 180.f) * OBJECT_SPEED;
				_iter->xy.y = sinf(_iter->theta * PI / 180.f) * OBJECT_SPEED;

				_iter->x += _iter->xy.x;
				_iter->y += _iter->xy.y;
				_iter->rc = RectMakeCenter(_iter->x, _iter->y, 10, 10);
			}
		}
		_iter->x += _iter->xy.x;
		_iter->y += _iter->xy.y;
		_iter->rc = RectMakeCenter(_iter->x, _iter->y, 10, 10);

		if (_iter->rc.bottom > WINSIZE_Y || _iter->rc.left < 0)
		{
			_iter->isVec = true;
			_iter->isCreate = false;
		}

	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_blackHole.left > 0)
		{
			_blackHole.left -= OBJECT_SPEED;
			_blackHole.right -= OBJECT_SPEED;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_blackHole.right < WINSIZE_X)
		{
			_blackHole.left += OBJECT_SPEED;
			_blackHole.right += OBJECT_SPEED;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_blackHole.top > 0)
		{
			_blackHole.bottom -= OBJECT_SPEED;
			_blackHole.top -= OBJECT_SPEED;
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_blackHole.bottom < WINSIZE_Y)
		{
			_blackHole.bottom += OBJECT_SPEED;
			_blackHole.top += OBJECT_SPEED;
		}
	}
	


}


void MainGame::render(void)
{
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================

	// ��Ȧ �׸���
	DrawEllipseMake(getMemDC(), _blackHole);

	// ������Ʈ �׸���
	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		if (_iter->_isEffect)
		{
			_iter->_isEffect = false;
			
			DrawEllipseMake(getMemDC(), EllipseMakeCenter(_iter->rc.left, _iter->rc.top, 30, 30));
		}
		else
		{
			DrawEllipseMake(getMemDC(), _iter->rc);
		}
		
	}

	

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}
/*
����1. ��Ʈ������ PPT �ۼ�

- ��ǥ���� ���� ����
- �������ϰ� + ����ϰ�

����2. ��Ȧ
- �������� �����Ǵ� ������Ʈ ��ü
- �׸��� �ֺ� ������Ʈ�� ���Ƶ��̴� ��Ȧ�� �����.
�� ��Ȧ�� ������ ���ؼ� ������ �� �ִ�.
- ������Ʈ�� �����Ǵ� ��ġ�� �˱����� ǥ�ø� �Ѵ�.
�� EX : �� / �̹��� / ũ��

- �ʼ� : STL -> ���� or ����Ʈ ������Ʈ 1000��
*/

/*
GIF ��� ����
���� �ֱ�
�� �� ����

��ȹ��
�� ���ϰ��� �ʿ�

1. ��ȹ�� ����
�� ��� ������ �� ��� ���

2. ��ȹ�� �긴��
�� ����� ����� ��ü���⸶�� �����ؼ� �����Ѵ�.

������Ʈ ��ǥ
���� �ǵ�
���� �Ұ�
�� �帣, ȸ���, �ð�ȭ �̹���, ������ �� �����Ұ�

������ �Ұ� -> ��� �Ұ�
�� �̹��� �� ���� ���ٰ� �ٰ� �ƴ�

�÷ο� ��Ʈ
�� ���ӿ� ���� �帧��

Ŭ���� ������

���� ����
�� ���� �� �׷����ϰ�
�� �����׽�Ʈ ����� �Ϸ�����

���� ��
�� vs ���伥 �������� �߰�

�����, ������, ��������

���� ���� 

1OBJECT_SPEED ~ 20 ��
*/