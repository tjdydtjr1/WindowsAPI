#pragma once
#include "SingletonBase.h"

// ��ü���� ��ȯ -> ���� ��� / �����

// Ű ���ռ�
#define KEY_MAX 256

using std::bitset;

class KeyManager : public SingletonBase <KeyManager>
{
private:
	//BOOL _keyUp[KEY_MAX];
	//BOOL _keyDown[KEY_MAX];
	std::bitset<KEY_MAX> _keyUp;
	std::bitset<KEY_MAX> _keyDown;

public:
	// �ʱ�ȭ
	HRESULT init(void);

	// �Ű������� int�� ���� ���� ���� �������� �켱ó���ϱ� ����
	// void ������ ��������� �ǵ�
	// Ű�� �ѹ��� ���ȴ���
	bool isOnceKeyDown(int key);
	// Ű�� �ѹ� ������ �������
	bool isOnceKeyUp(int key);
	// Ű�� ��� �����ִ���
	bool isStayKeyDown(int key);
	// ���Ű => ���� Ű ����
	bool isToggleKey(int key);

	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }
	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }


	KeyManager() {}
	~KeyManager() {}

};

