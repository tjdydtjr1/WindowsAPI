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
		_iter->isCreate = false;
		_iter->theta = 0;
	}

	_idx = 0;
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
}

void MainGame::update(void)
{
	GameNode::update();
	
	// 오브젝트 생성
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
			_iter->theta = 0;
		}
	}

	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		if (_iter->isCreate)
		{
			_iter->theta;
			_iter->xy.x = cosf(_iter->theta - 90 * PI / 180.f) * OBJECT_SPEED;
			_iter->xy.y = sinf(_iter->theta - 90 * PI / 180.f) * OBJECT_SPEED;

			_iter->x += _iter->xy.x;
			_iter->y += _iter->xy.y;
			_iter->rc = RectMakeCenter(_iter->x, _iter->y, 10, 10);
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
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// =======================================================

	// 블랙홀 그리기
	DrawEllipseMake(getMemDC(), _blackHole);
	
	// 오브젝트 그리기
	for (_iter = _objectVec.begin(); _iter != _objectVec.end(); ++_iter)
	{
		DrawEllipseMake(getMemDC(), _iter->rc);
	}

	/*for (int i = 0; i < MAX_OBJECT; ++i)
	{
		DrawEllipseMake(getMemDC(), _object[i].rc);
	}*/

	// =======================================================
	
	this->getBackBuffer()->render(getHDC());


}
/*
과제1. 포트폴리오 PPT 작성

- 발표일은 아직 미정
- 디테일하게 + 깔끔하게

과제2. 블랙홀
- 무작위로 생성되는 오브젝트 객체
- 그리고 주변 오브젝트를 빨아들이는 블랙홀을 만든다.
ㄴ 블랙홀은 조작을 통해서 움직일 수 있다.
- 오브젝트가 생성되는 위치를 알기위해 표시를 한다.
ㄴ EX : 색 / 이미지 / 크기

- 필수 : STL -> 벡터 or 리스트 오브젝트 1000개
*/

/*
GIF 사용 금지
목차 넣기
ㄴ 준 제목

기획서
ㄴ 통일감이 필요

1. 기획서 올인
ㄴ 모든 내용을 다 담는 방법

2. 기획서 브릿지
ㄴ 기반을 만들고 객체지향마냥 분할해서 설명한다.

프로젝트 목표
제작 의도
게임 소개
ㄴ 장르, 회사명, 시각화 이미지, 여백의 미 생각할것

컨텐츠 소개 -> 기능 소개
ㄴ 이미지 글 많이 쓴다고 다가 아님

플로우 차트
ㄴ 게임에 대한 흐름도

클래스 구조도

개발 일정
ㄴ 봤을 때 그럴싸하게
ㄴ 게임테스트 디버깅 하루정도

개발 툴
ㄴ vs 포토샵 영상편집 추가

배운점, 느낀점, 개선할점

개발 일정 

1OBJECT_SPEED ~ 20 장
*/