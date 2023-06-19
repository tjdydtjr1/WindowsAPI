#include "Stdafx.h"
#include "KeyManager.h"

HRESULT KeyManager::init(void)
{
	// Ű ���� ���� �������� ���� ���·� �ʱ�ȭ
	for (int i = 0; i < KEY_MAX; ++i)
	{
		this->setKeyUp(i, false);
		this->setKeyDown(i, false);
	}
	// �� ����ƴ��� Ȯ��
	return S_OK;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		this->setKeyUp(key, true);
	}
	else
	{
		if (this->getKeyUp()[key])
		{
			this->setKeyUp(key, false);
		}
	}
	return false;
}

bool KeyManager::isOnceKeyDown(int key)
{
	/*
	GetAsyncKeyState()
	- � Ű�� �ԷµȰ��� üũ / ���α׷����� Ű�� �Է¹ް� ���� �� ����ϴ� API ���� �Լ�
	- �⺻������ �޼��� ť�� �ִ� Ű�� ������ Ȯ�� �Ѵ�.
	- Ű�� ���� ������ üũ�ϱ� ���� &(AND) ������ ����ؼ� Ȯ���Ѵ�.
	- 0x0000
	- 0x0001
	- 0x8000
	- 0x8001

	*/
	
	// ��Ʈ ������ AND ������ �Ѵ�.
	// �� �Ѵ� 1�� ���� ����� 1�̰� / �ƴ϶�� ����� 0
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getKeyDown()[key])
		{
			this->setKeyDown(key, true);
		}
	}
	else
	{
		this->setKeyDown(key, true);
		return true;
	}

	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}

	return false;
}

bool KeyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001)
	{
		return true;
	}

	return false;
}

