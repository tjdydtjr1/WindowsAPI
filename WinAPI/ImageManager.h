#pragma once
#include "SingletonBase.h"
#include "GImage.h"

// 1. ��ü�� ���� new
// 2. ���� ���� 
// �� STL -> Map, Vector Ư¡ �����غ��� => void func �������� ����
//			��Unordered Map �˻��ӵ��� ������.(�ߺ�X)
// 

#pragma region STL ��
/*
- Ű + ���� ���� ����.
�� ù��° first -> Ű
�� �ι�° second -> ��

- �߰��ϴ� ����� insert()�� ����ϰ� Ű�� ������ ���ÿ� �߰��ؾ� �ϴ� pair / make_pair ���

- pair() : �� ���� �ڷ����� �ϳ��� �����ִ� ����ü (���ø� -> � �ڷ����� ����)

- make_pair() : pair�� ����� �ִ� �Լ�
�� pair.first = x; / pari.second = y;
�� pair = make_pair(x, y);

- �ϳ��� Ű�� �������� ���� �����ϰ� �ʹٸ� ��Ƽ���� ����ϴ� �͵� ���
- pair�� Ȯ����� ������ �ۼ��ϰų� �ټ��� ��ȯ���� ������ �ʹٸ� tuple�� ����ؾ� �Ѵ�.
*/
#pragma endregion

using std::map;
using std::string;

class ImageManager : public SingletonBase<ImageManager>
{
private:
	// map ���� char*�� �ƴ� string�� ���� ����
	// �� iterator���� ��ȸ�� ���ƾ������� char*�� ����ִ� �޸𸮸� Ȯ���ϴ� �߰� �۾��� ���ܼ�
	//	  ��������.

	typedef map<string, GImage*> mapImageList;
	typedef map<string, GImage*>::iterator mapImageIter;

private:
	mapImageList _mImageList;

public:

	HRESULT init(void);
	void release(void);

	// �ܵ�ó�� �� ������
	// �� 1. �����ӿ�ũ �ڵ� ����ġ
	// �� 2. ��ü�� (�̹���) �浹 ���ɼ�
public:
	GImage* addImage(string strKey, int width, int height);
	GImage* addImage(string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	GImage* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));


	GImage* findImage(string strKey);
	bool deleteImage(string strKey);
	bool deleteAll();

	// ���� �⺻
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);

	// �̹��� Ŭ���� -> ������ ���� �������� ���� ������ ���̸� ¥����.
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	// ���ķ��� BYTE = 0 ~ 255
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	// ������ ����
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int sizeX, int sizeY);


	// ���� ����
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);


	ImageManager() {}
	~ImageManager() {}

};

