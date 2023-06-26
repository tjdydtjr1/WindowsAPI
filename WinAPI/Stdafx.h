#pragma once
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이 들어 있는 포함 파일입니다.

// 리눅스와 같이 OS 변경 시 코드 변경 없이 사용할 수 있게 해주는 헤더 파일
#include "targetver.h"


// 경고 무시
#pragma warning(disalbe : 4005) // -> 프로젝트 속성 -> C/C++ -> 고급 -> 특정 경고 오류 처리 (코드사용하자)


#include <SDKDDKVER.h>

#define WIN32_LEAN_AND_MEAN

// !라이브러리 추가
#pragma comment (lib, "msimg32.lib")


// Windows 헤더 파일
#include <Windows.h>

// C 런타임 헤더 파일
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>		// Windows.h 에 통합되어 있음.
#include <stdio.h>
#include <time.h>
#include <tchar.h>
#include <conio.h>


// ===========================================================================
// C++ 런타임 헤더 파일
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>

// bitset : 비트 연산을 좀더 쉽게 관리해 주는 함수를 지원하는 STL
// ㄴ reset(), set(), flip(), all(), any(), size() 등등..
#include <bitset>


/*
// ! D2D/D3D 헤더 파일
#include <D2D1.h>
#include <d2d1helper.h>
#include <d3dx9.h>

// 가장 많이 쓰이는 DX11 쉐이더 필수
#include <D3DX11.h>
#include <d3d11shader.h>
#include <dinput.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxgiod.lib")

ID2D1Factory*			_ID2DFactory = nullptr;
ID2D1HwndRenderTarget*	_ID2DRenderTarget = nullptr;

*/

// # 사용자 정의 헤더 파일 #
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"


// # 싱글톤 #
// 전역객체 : 호출이 많기에 스네이크를 사용 안함
#define RND			RandomFunction::getSingleton()
#define KEYMANAGER	KeyManager::getSingleton()


// # 매크로 # (윈도우창 초기화)
// 매크로 표기법 _로 단어 구분
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			400			// 400
#define WINSTART_Y			100			// 100
#define WINSIZE_X			1800			// 800
#define WINSIZE_Y			1000		// 800
// WS_CATION  : 타이틀바를 가지기 위한 옵션
// WS_SYSMENU : 제목 표시줄에 컨트롤 메뉴 상자 창
#define WINSTYLE			WS_CAPTION | WS_SYSMENU

// # 매크로 함수 # -> 한줄이 원칙이나 '\' 역슬래쉬를 사용하여 이을 수 있다.
// ㄴ 클래스에서 동적할당된 부분 해제
#define SAFE_DELETE(p)			{if(p){delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

// # 전역 변수 # - 데이터 영역
// ㄴ 전체 프로젝트의 전역 변수로 접근이 가능하기에 사용하는데 유의해야 한다.
// EX) Player Inven 
// extern 키워드는 다른 헤더 / cpp에서 변수를 공유해서 쓰기 위해 사용한다.
// ㄴ 객체
// 기본적으로 전역 변수는 키워드를 생략해도 기본적으로 extern화 되는 경우가 많다.
// 클래스 참조와 같은 경우 대상 객체를 명확하게 해줘야 extern화 할 수 있다 (nullptr도 안됨)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X 좌표와 Y 좌표를 평면의 좌표에 정의할 때 사용을 한다.
extern POINT			_ptMouse;




// ===============================================================================
// 임시
#define WINMYNAME(p)				(LPTSTR)(TEXT(p))
#define RECTCENTER_X(p)				(p.left + p.right) / 2
#define RECTCENTER_Y(p)				(p.top + p.bottom) / 2

#define WINMINSIZE_LEFT			20
#define WINMINSIZE_TOP			20
#define WINMINSIZE_RIGHT		780
#define WINMINSIZE_BOTTOM		750