#pragma once
#include "SingletonBase.h"

// 객체지향 전환 -> 설계 방식 / 방법론

// 키 조합수
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
	// 초기화
	HRESULT init(void);

	// 매개변수로 int를 쓰는 이유 연산 과정에서 우선처리하기 위해
	// void 였으면 상관없었을 건데
	// 키가 한번만 눌렸는지
	bool isOnceKeyDown(int key);
	// 키가 한번 누르고 띄었는지
	bool isOnceKeyUp(int key);
	// 키가 계속 눌려있는지
	bool isStayKeyDown(int key);
	// 토글키 => 상태 키 유지
	bool isToggleKey(int key);

	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }
	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }


	KeyManager() {}
	~KeyManager() {}

};

