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

	// _currentScene -> 시동이 안되면 그냥 실행 자체가 안된다. -> 굳이 돌려볼 필요도 없다.
	_currentScene = _start;

	// <-> : assert를 릴리즈할 때 주석 또는 제거하기 위해 주석으로 표시한다.
	assert(_currentScene != nullptr);
	//assert(_currentScene != nullptr, "MainGame 초기화 부분에서 노트 파트 오류 발생");
	

	/*
	
	포폴에 1 ~ 2개 사용 -> 영상 자막에 어디에 왜 썻는지 명시
	=> assert
	- 디버깅 모드에서 동작하는 오류 검출용 함수
	ㄴ 릴리즈 모드에서는 동작하지 않는다.

	- assert 함수에 걸리게 되면 버그 발생 위치 / 콜 스택등 여러 정보를 알 수 있다.
	ㄴ Expression -> false -> assert error

	- 대부분 문법이 true일때만 동작하지만 assert()은 거짓일 때 동작을 한다.
	ㄴ 그렇기 때문에 일어나면 안되는 조건이 아니라 꼭 일어나야 하는 조건을 명시해야 한다.

	EX) assert(A != NULL)
	    ㄴ A가 NULL이 아니면 true가 나오게 되므로 패스
		ㄴ A가 NULL이 맞다면 false가 나오게 되므로 assert error

	C / C++
	assert() : "C" -> 컴파일 타임을 지나 프로그램을 실행시키고 문제를 파악하겠다.
	static_assert() : "C++" -> 컴파일 중에 문제를 파악 => 컴파일? = 상수 값

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
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================

	_currentScene->render();

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}

