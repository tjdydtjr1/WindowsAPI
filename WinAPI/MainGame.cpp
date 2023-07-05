#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);
	
	//IMAGEMANAGER->addImage("Track", "Resources/Images/BackGround/Track.bmp", WINSIZE_X, WINSIZE_Y);
	_start = new StartScene;
	_start->init();

	_second = new SecondScene;
	_second->init();

	// _currentScene -> �õ��� �ȵǸ� �׳� ���� ��ü�� �ȵȴ�. -> ���� ������ �ʿ䵵 ����.
	_currentScene = _start;

	// <-> : assert�� �������� �� �ּ� �Ǵ� �����ϱ� ���� �ּ����� ǥ���Ѵ�.
	assert(_currentScene != nullptr);
	//assert(_currentScene != nullptr, "MainGame �ʱ�ȭ �κп��� ��Ʈ ��Ʈ ���� �߻�");
	

	/*
	
	������ 1 ~ 2�� ��� -> ���� �ڸ��� ��� �� ������ ���
	=> assert
	- ����� ��忡�� �����ϴ� ���� ����� �Լ�
	�� ������ ��忡���� �������� �ʴ´�.

	- assert �Լ��� �ɸ��� �Ǹ� ���� �߻� ��ġ / �� ���õ� ���� ������ �� �� �ִ�.
	�� Expression -> false -> assert error

	- ��κ� ������ true�϶��� ���������� assert()�� ������ �� ������ �Ѵ�.
	�� �׷��� ������ �Ͼ�� �ȵǴ� ������ �ƴ϶� �� �Ͼ�� �ϴ� ������ ����ؾ� �Ѵ�.

	EX) assert(A != NULL)
	    �� A�� NULL�� �ƴϸ� true�� ������ �ǹǷ� �н�
		�� A�� NULL�� �´ٸ� false�� ������ �ǹǷ� assert error

	C / C++
	assert() : "C" -> ������ Ÿ���� ���� ���α׷��� �����Ű�� ������ �ľ��ϰڴ�.
	static_assert() : "C++" -> ������ �߿� ������ �ľ� => ������? = ��� ��

	*/
	
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_start);
	SAFE_DELETE(_second);

}

void MainGame::update(void)
{
	GameNode::update();
	_currentScene->update();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_currentScene = _second;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_MBUTTON))
	{
		_currentScene = _start;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		
	}
	


}


void MainGame::render(void)
{
	// PatBlt() : �簢�� �ȿ� ������ �귯���� ä��� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================

	_currentScene->render();

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

