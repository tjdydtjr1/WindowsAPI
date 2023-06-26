#pragma once
/*
�̹��� GDI -> GDI+     / D2D
1. ����
2. ���� ���� : �����Ÿ� �������� ��ȯ
3. Ŭ���� => GDI+ ����ȭ : ���� ��ü�� �ƴ� �ʿ��� �κи� �׷�����
4. ������(�ִϸ��̼�) : ��������Ʈ�� ����
5. ���� : �ݺ� -> ������ ����
*/

class GImage
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,		// ���ҽ�, ����
		LOAD_EMPTY, LOAD_END				// �� ��Ʈ��, �ε� Done
	};

	typedef struct tagImage
	{
		// DWORD = unsigned long
		DWORD		resID; 
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		int			width;
		int			height;
		BYTE		loadType;
		// BYTE = unsigned  0 ~ 255
		tagImage()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INPO;

private:
	LPIMAGE_INPO _imageInfo;		// �̹��� ������ ���� ����ü
	char*		 _fileName;			// ���� �̸��� ã�� ���� ����
	bool		 _isTrans;			// ĳ������ ������ ���� ����
	COLORREF	 _transColor;		// ������ � ����� ��������
									// �� (255, 0, 255) ����Ÿ �������� ���� ��
									// �� ���ӿ��� �߾Ⱦ��� ���� �߶�
	/*
	COLORREF
	- ��������� ������ ǥ���ϱ� ���� ��ȣ���� 32��Ʈ ������
	�� R, G, B ���� 1����Ʈ 0 ~ 255 ������ ���� ǥ���ϴµ� ����ȭ �Ǿ� �ִ�.
	*/

	// ���̴�, ���������ȭ -> ���İ� (GDI�� ���İ� ��� x)
	BLENDFUNCTION	_blendFunc;		// ���ĺ��� ���
	LPIMAGE_INPO	_blendImage;	// ���ĺ��� �̹���

public:
	HRESULT init(int width, int height);
	
	// bool BOOL �� ��ȣ�� ����
	// �̹��� ���ҽ��� �ʱ�ȭ
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	// �̹��� ���Ϸ� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));


	HRESULT initForAlphaBlend(void);


	// ���� �÷�Ű ����
	void setTransColor(bool isTrans, COLORREF transColor);

	// ����
	void release(void);

	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	
	// �̹��� Ŭ���� -> ������ ���� �������� ���� ������ ���̸� ¥����.
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	
	// ���ķ��� BYTE = 0 ~ 255
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY,int sourX, int sourY, int sourWidth, int sourHegiht, BYTE alpha);

	// = �ζ��� �Լ� =
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }
	

	// �����ڴ� private �������� �ʱ�ȭ�� ���
	GImage();

	// �Ҹ��� �Ⱦ��� ����
	// 1. release�� ��ü 
	// 2. �߻�ü�μ� ��üȭ �Ǵ� ��찡 ���� ������
	~GImage() {}

};

