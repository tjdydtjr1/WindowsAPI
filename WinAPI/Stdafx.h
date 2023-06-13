#pragma once
// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������ ��� �ִ� ���� �����Դϴ�.

// �������� ���� OS ���� �� �ڵ� ���� ���� ����� �� �ְ� ���ִ� ��� ����
#include "targetver.h"


// ��� ����
#pragma warning(disalbe : 4005) // -> ������Ʈ �Ӽ� -> C/C++ -> ���� -> Ư�� ��� ���� ó�� (�ڵ�������)


#include <SDKDDKVER.h>

#define WIN32_LEAN_AND_MEAN

// Windows ��� ����
#include <Windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>		// Windows.h �� ���յǾ� ����.
#include <stdio.h>

#include <tchar.h>

// ===========================================================================
// C++ ��Ÿ�� ��� ����
#include <iostream>

#include <chrono>
#include <random>
#include <vector>
#include <map>

#include <unordered_map>
#include <cassert>

/*
// ! D2D/D3D ��� ����
#include <D2D1.h>
#include <d2d1helper.h>
#include <d3dx9.h>

// ���� ���� ���̴� DX11 ���̴� �ʼ�
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

#include "CommonMacroFunction.h"

// # ��ũ�� # (������â �ʱ�ȭ)
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			400
#define WINSTART_Y			100
#define WINSIZE_X			800
#define WINSIZE_Y			800
// WS_CATION  : Ÿ��Ʋ�ٸ� ������ ���� �ɼ�
// WS_SYSMENU : ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â
#define WINSTYLE			WS_CAPTION | WS_SYSMENU

// # ��ũ�� �Լ� # -> ������ ��Ģ�̳� '\' ���������� ����Ͽ� ���� �� �ִ�.
// �� Ŭ�������� �����Ҵ�� �κ� ����
#define SAFE_DELETE(p)			{if(p){delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[](p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

// # ���� ���� # - ������ ����
// �� ��ü ������Ʈ�� ���� ������ ������ �����ϱ⿡ ����ϴµ� �����ؾ� �Ѵ�.
// EX) Player Inven 
// extern Ű����� �ٸ� ��� / cpp���� ������ �����ؼ� ���� ���� ����Ѵ�.
// �� ��ü
// �⺻������ ���� ������ Ű���带 �����ص� �⺻������ externȭ �Ǵ� ��찡 ����.
// Ŭ���� ������ ���� ��� ��� ��ü�� ��Ȯ�ϰ� ����� externȭ �� �� �ִ� (nullptr�� �ȵ�)
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X ��ǥ�� Y ��ǥ�� ����� ��ǥ�� ������ �� ����� �Ѵ�.
extern POINT			_ptMouse;




// ===============================================================================
// �ӽ�
#define WINMYNAME(p)				(LPTSTR)(TEXT(p))
#define RECTCENTER_X(p)				(p.left + p.right) / 2
#define RECTCENTER_Y(p)				(p.top + p.bottom) / 2

enum class InputKey
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};