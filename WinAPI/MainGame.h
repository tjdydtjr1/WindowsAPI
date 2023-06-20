#pragma once
#include "GameNode.h"
// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)


// 설계 연습
// 80개의 단일 이미지는 STL X => 애니메이션효과로 인해 텍스처가 많이 들어가면 사용해야한다.
// MAX? => 배열 => STL 사용도 생각하기

class MainGame : public GameNode
{
private:
	

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {  }
	~MainGame() {  }

};

