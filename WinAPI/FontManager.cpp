#include "Stdafx.h"
#include "FontManager.h"

HRESULT FontManager::init(void)
{

	return S_OK;
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWeight, char* printString, int length, COLORREF color)
{
	/*SetBkMode(hdc, TRANSPARENT);

	HFONT font = CreateFont
	(
		70, 0, 0, 0, 600,
		0, 0, 1,
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("휴먼굴림")
	);


	auto font = (HFONT)::SelectObject(hdc, font);
	auto oldFont = ;
	
	

	oldFont = (HFONT)::SelectObject(hdc, font);
	wsprintf(str, "새로운 폰트");
	TextOut(getMemDC(), 100, 400, str, strlen(str));


	SetTextColor(hdc, color);
	const int stringLength = strlen();
	wchar_t charBuffer[256];
	ZeroMemory(charBuffer);

	TextOut();
	TextOutW();

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);*/

}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWeight, LPCWSTR printString, int length, COLORREF color)
{
	if (length < 1)
	{
		return;
	}

	// 폰트 뒷 배경 투명화
	SetBkMode(hdc, TRANSPARENT);

	// 폰트 생성
	HFONT font = 
	CreateFont
	(
		fontSize, fontWeight, 0, 0, 0,
		0, 0, 0,
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT(fontName)
	);

	// 폰트 선택
	HFONT oldFont = (HFONT)::SelectObject(hdc, font);

	// 텍스트 출력
	TextOutW(hdc, destX, destY, printString, length);

	// 텍스트 색상
	SetTextColor(hdc, color);

	// 폰트 사용후 메모리 해제
	SelectObject(hdc, oldFont);
	DeleteObject(font);
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWeight, LPCWSTR* printStringArr, int length, COLORREF color)
{
	/*int arraySize = sizeof(printStringArr) / sizeof(*printStringArr);

	int lineCound = 0;

	for (int i = 0; i < arraySize; ++i)
	{
		if (조건식)
		{

		}
		else if()
		{
			break;
		}

		else
		{

			}
	}*/
}
