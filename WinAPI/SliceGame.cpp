#include "Stdafx.h"
#include "SliceGame.h"

HRESULT SliceGame::init(void)
{
	GameNode::init();
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/Object/baseball.bmp", 600, 600, true, RGB(255, 0, 255));

	_idx = 0;
	_temp = 0;
	_count = 0;

	// 그림 섞기 위한 랜덤 인덱스
	for (int i = 0; i < 9; ++i)
	{
		_idx = rand() % 9;
		_temp = _idx;
		if (_rndIdx[_temp])
		{
			--i;
			continue;
		}
		_rndIdx[_temp] = i;
		_checkIdx[i] = i;
	}


	for (int i = 0; i < 9; ++i)
	{
		_rc[_rndIdx[i]] = RectMake(900 + (200 * (i % 3)), 200 * (i / 3), 200, 200);
	}
	
	for (int i = 0; i < 9; ++i)
	{
		_result[i] = RectMake(900 + (200 * (i % 3)), 200 * (i / 3), 200, 200);
	}

	return S_OK;
}

void SliceGame::release(void)
{
	GameNode::release();
	SAFE_DELETE(_bgImage);
}

void SliceGame::update(void)
{
	GameNode::update();

	for (int i = 0; i < 9; ++i)
	{
		_rc[_rndIdx[i]] = RectMake(900 + (200 * (i % 3)), 200 * (i / 3), 200, 200);
	}

	// 치트 사용
	if (!KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		for (int i = 0; i < 9; ++i)
		{
			_rndIdx[i] = i;
		}
		_rndIdx[7] = 8;
		_rndIdx[8] = 7;
		_swap = 8;
		_count = 8;
		
	}
	
	// 
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		
		if (_swap != 2 && _swap != 5 && _swap != 8)
		{
			_temp = _rndIdx[_swap + 1];
			_rndIdx[_swap + 1] = _rndIdx[_swap];
			_rndIdx[_swap] = _temp;

			++_swap;
		}
		_count = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (_rndIdx[i] == i)
			{
				++_count;
			}
		}

		
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_swap != 0 && _swap != 3 && _swap != 6)
		{
			// _check[0] = 2 1 4 5 8 6
			// _rc[_check[0]] = > _rc[2] = 0번이미지 
			_temp = _rndIdx[_swap - 1];
			_rndIdx[_swap - 1] = _rndIdx[_swap];
			_rndIdx[_swap] = _temp;
		
			--_swap;
		}
		_count = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (_rndIdx[i] == i)
			{
				++_count;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_swap != 0 && _swap != 1 && _swap != 2)
		{
			_temp = _rndIdx[_swap - 3];
			_rndIdx[_swap - 3] = _rndIdx[_swap];
			_rndIdx[_swap] = _temp;
		
			_swap -= 3;
		}
		_count = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (_rndIdx[i] == i)
			{
				++_count;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_swap != 6 && _swap != 7 && _swap != 8)
		{
			_temp = _rndIdx[_swap + 3];
			_rndIdx[_swap + 3] = _rndIdx[_swap];
			_rndIdx[_swap] = _temp;

			_swap += 3;
		}
		_count = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (_rndIdx[i] == i)
			{
				++_count;
			}
		}
	}

	// 결과확인

	

	if (_count >= 9)
	{
		_alpha += 5;
		if (_alpha >= 255)
		{
			_alpha = 255;
		}
	}

}

void SliceGame::render(HDC hdc)
{

	// =======================================================
	HDC memDC = this->getBackBuffer()->getMemDC();
	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// =======================================================
	//_bgImage->render(memDC, 0, 0);
	//_plImage->render(memDC, _rc.left, _rc.top);
	// =======================================================
	// 투명값
	//_bgImage->alphaRender(memDC, _alphaA);
	
	//_plImage->alphaRender(memDC, _rc.left, _rc.top, _alphaB);
	// =======================================================
	// 좌측 원본 이미지	
	
	
	if(_count < 9)
	{
		_bgImage->render(memDC, 0, 0);

		char text[128];

		// 짤린 이미지 출력

		for (int i = 0; i < 9; ++i)
		{
			//DrawRectMake(memDC, _rc[i]); 5 -> 0 _rc[5] -> 0Image
			_bgImage->render(memDC, _rc[i].left, _rc[i].top,
				(200 * (i % 3)), 200 * (i / 3), 200, 200, 255);
		}
		for (int i = 0; i < 9; ++i)
		{
			wsprintf(text, "%d", _checkIdx[i]);
			TextOut(memDC, _rc[i].left, _rc[i].top, text, strlen(text));
		}
	}
	else if (_count >= 9)
	{
		_bgImage->alphaRender(memDC, WINSIZE_X / 4, WINSIZE_Y / 4, _alpha);

	}
	//DrawRectMake(memDC, _rc[9]);
	
	

	
	// 클리핑 : 자르기
	//_bgImage->render(memDC, _rc.left, _rc.top, 500, 500, 300, 300, _alphaB);
	
	// =======================================================

	// =======================================================
	this->getBackBuffer()->render(hdc, 0, 0);


}

//bool SliceGame::rectEqual(RECT _rc1, RECT _rc2)
//{
//	if (
//		_rc1.left == _rc2.left &&
//		_rc1.top == _rc2.top &&
//		_rc1.right == _rc2.right &&
//		_rc1.bottom == _rc2.bottom
//		)
//	{
//		return true;
//	}
//	return false;
//}
