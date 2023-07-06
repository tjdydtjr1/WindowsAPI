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
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("�޸ձ���")
	);


	auto font = (HFONT)::SelectObject(hdc, font);
	auto oldFont = ;
	
	

	oldFont = (HFONT)::SelectObject(hdc, font);
	wsprintf(str, "���ο� ��Ʈ");
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

	// ��Ʈ �� ��� ����ȭ
	SetBkMode(hdc, TRANSPARENT);

	// ��Ʈ ����
	HFONT font = 
	CreateFont
	(
		fontSize, fontWeight, 0, 0, 0,
		0, 0, 0,
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT(fontName)
	);

	// ��Ʈ ����
	HFONT oldFont = (HFONT)::SelectObject(hdc, font);

	// �ؽ�Ʈ ���
	TextOutW(hdc, destX, destY, printString, length);

	// �ؽ�Ʈ ����
	SetTextColor(hdc, color);

	// ��Ʈ ����� �޸� ����
	SelectObject(hdc, oldFont);
	DeleteObject(font);
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWeight, LPCWSTR* printStringArr, int length, COLORREF color)
{
	/*int arraySize = sizeof(printStringArr) / sizeof(*printStringArr);

	int lineCound = 0;

	for (int i = 0; i < arraySize; ++i)
	{
		if (���ǽ�)
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
