#pragma once
#include "SingletonBase.h"

#define KEY_MAX 256

using std::bitset;

class testKeyManager : public SingletonBase<testKeyManager>
{
private:
	bitset<KEY_MAX> _keyUp;
	bitset<KEY_MAX> _keyDown;

public:
	HRESULT init(void);
	
	bool isOnceKeyUp(int key);
	bool isOnceKeyDown(int key);
	bool isStateKeyDown(int key);
	bool isToggleKey(int key);

	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }
	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }

};

