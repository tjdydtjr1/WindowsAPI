#include "Stdafx.h"
#include "GImage.h"


GImage::GImage() 
    : _imageInfo(nullptr)
    , _fileName(nullptr)
    , _isTrans(false)
    , _transColor(RGB(0, 0, 0))
    , _blendImage(NULL)     // ȣȯ��
{
}



HRESULT GImage::init(int width, int height)
{
    // �� �ʱ�ȭ �����ϰڴ�.
    // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }
    
    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_EMPTY;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->width = width;
    _imageInfo->height = height;

    // ������� ����
    _fileName = nullptr;
    _isTrans = false;
    _transColor = RGB(0, 0, 0);


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);

    return S_OK;
}

HRESULT GImage::init(const DWORD resID, int width, int height, bool isTrans, COLORREF transColor)
{
    // �� �ʱ�ȭ �����ϰڴ�.
    // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_RESOURCE;
    _imageInfo->resID = resID;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)LoadBitmap(_hInstance, MAKEINTRESOURCE(_imageInfo->resID));
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->width = width;
    _imageInfo->height = height;
   
    _fileName = nullptr;

    _isTrans = isTrans;
    _transColor = transColor;


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);


    return S_OK;
}

HRESULT GImage::init(const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
    // �� �ʱ�ȭ �����ϰڴ�.
    // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_FILE;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->width = width;
    _imageInfo->height = height;

    int len = strlen(fileName);
    _fileName = new char[len + 1];
    
    // strcpy -> ���� 1�� �� �߰�
    // �� �������� ���� / ���ڿ����� ������ ������ �ذ��� �Լ�
    // (������� ����, �ִ� ����, ����)
    strcpy_s(_fileName, len + 1, fileName);

    _isTrans = isTrans;
    _transColor = transColor;


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);


    return S_OK;
}

HRESULT GImage::init(const char* fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
    // �� �ʱ�ȭ �����ϰڴ�.
    // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_FILE;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->x = x;
    _imageInfo->x = y;
    _imageInfo->width = width;
    _imageInfo->height = height;

    int len = strlen(fileName);
    _fileName = new char[len + 1];

    // strcpy -> ���� 1�� �� �߰�
    // �� �������� ���� / ���ڿ����� ������ ������ �ذ��� �Լ�
    // (������� ����, �ִ� ����, ����)
    strcpy_s(_fileName, len + 1, fileName);

    _isTrans = isTrans;
    _transColor = transColor;


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);
    return S_OK;
}

HRESULT GImage::init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
    // �� �ʱ�ȭ �����ϰڴ�.
   // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_FILE;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->width = width;
    _imageInfo->height = height;
    _imageInfo->currentFrameX = 0;
    _imageInfo->currentFrameY = 0;
    _imageInfo->maxFrameX = maxFrameX - 1;
    _imageInfo->maxFrameY = maxFrameY - 1;
    _imageInfo->frameWidth = width / maxFrameX;
    _imageInfo->frameHeight = height / maxFrameY;

    
    int len = strlen(fileName);
    _fileName = new char[len + 1];

    // strcpy -> ���� 1�� �� �߰�
    // �� �������� ���� / ���ڿ����� ������ ������ �ذ��� �Լ�
    // (������� ����, �ִ� ����, ����)
    strcpy_s(_fileName, len + 1, fileName);

    _isTrans = isTrans;
    _transColor = transColor;


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);
    return S_OK;
}

 
HRESULT GImage::init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
    // �� �ʱ�ȭ �����ϰڴ�.
   // Ȥ�� ���� �ִٸ� ���� �������ϰ� �����ض�
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // ���� DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_FILE;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->x = x;
    _imageInfo->y = y;
    _imageInfo->width = width;
    _imageInfo->height = height;
    _imageInfo->currentFrameX = 0;
    _imageInfo->currentFrameY = 0;
    _imageInfo->maxFrameX = maxFrameX - 1;
    _imageInfo->maxFrameY = maxFrameY - 1;
    _imageInfo->frameWidth = width / maxFrameX;
    _imageInfo->frameHeight = height / maxFrameY;


    int len = strlen(fileName);
    _fileName = new char[len + 1];

    // strcpy -> ���� 1�� �� �߰�
    // �� �������� ���� / ���ڿ����� ������ ������ �ذ��� �Լ�
    // (������� ����, �ִ� ����, ����)
    strcpy_s(_fileName, len + 1, fileName);

    _isTrans = isTrans;
    _transColor = transColor;


    // ���� : �̹��� ������ ���� ��� �����Ϸ��� �������� ���� ����Ű�� ������ ���
    // ���ҽ��� ��� ���µ� �����ߴ�.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : ���� , E_FAIL : ���� 
    }

    ReleaseDC(_hWnd, hdc);

    return S_OK;
}

HRESULT GImage::initForAlphaBlend(void)
{
    HDC hdc = GetDC(_hWnd);

    // ���ĺ��� �ɼ�
    _blendFunc.BlendFlags = 0;
    _blendFunc.AlphaFormat = 0;         // ���İ��� �ٲ��� ������ �� / �� 0 = ��ó�� => WINAPI�� GPU�� ���� �ʴ´�.
    _blendFunc.BlendOp = AC_SRC_OVER;   // ���� -> ���� + ���� -> ����(�����Ͷ�����(�ȼ� ����)) ����� �������� => �����ҽ� �״�� ���ٶ�� ��� (CPU ���꿡�� ������)
    //_blendFunc.SourceConstantAlpha = 0; -> ���� �־��ָ� ���İ��� �״�� ���´�. => ó���� ���İ��� ����� �������� �ʰڴ�.

    _blendImage = new IMAGE_INFO;
    _blendImage->loadType = LOAD_FILE;
    _blendImage->resID = 0;
   _blendImage->hMemDC = CreateCompatibleDC(hdc);
   _blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height); // ���� �̹����� ��� ���İ� �б���
   _blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit); // hBit �� hOldBit�� ���� ���� ��� ���ذ� �ʿ�
   _blendImage->width = WINSIZE_X;
   _blendImage->height = WINSIZE_Y;


   /*
   // ���� �̹��� ó�� ����
   1�� ���(DC) -> blend(����)
   -> ����̹��� ���İ��� ���� �б�(if ~ else) ��滬���� ��������
   -> ���� �̹����� ��� ����
   -> �޸𸮿��� ȭ������ ����
   */

   // GetDC�� ������ ��������
   ReleaseDC(_hWnd, hdc);

    return S_OK;
}

void GImage::setTransColor(bool isTrans, COLORREF transColor)
{
    _isTrans = isTrans;
    _transColor = transColor;
}

// Ư�� �̹��������� �ſ� �߿��� �Լ�
void GImage::release(void)
{
    if (_imageInfo)
    {
        // �̹����� �ϳ��ϳ� ����
        SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
        DeleteObject(_imageInfo->hBit);
        DeleteObject(_imageInfo->hMemDC);
        
        // ������ ����
        SAFE_DELETE(_imageInfo);
        SAFE_DELETE_ARRAY(_fileName);

        // ���� �÷�Ű �ʱ�ȭ
        _isTrans = false;
        _transColor = RGB(0, 0, 0);
    }

    if (_blendImage)
    {
        SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
        DeleteObject(_blendImage->hBit);
        DeleteObject(_blendImage->hMemDC);

        SAFE_DELETE(_blendImage);
    }
}

// ���ȭ��
void GImage::render(HDC hdc)
{
    if (_isTrans)
    {
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                    // ������ ����� DC (ȭ�� DC)
            0,                      // ����� ��ǥ ���� X
            0,                      // ����� ��ǥ ���� Y
            _imageInfo->width,      // ����� �̹��� ���� ũ��
            _imageInfo->height,     // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,     // ����� ��� �޸� DC
            0,                      // ���� �������� X
            0,                      // ���� �������� Y
            _imageInfo->width,      // ���� ���� ���� ũ��
            _imageInfo->height,     // ���� ���� ���� ũ��
            _transColor             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            0,
            0,
            _imageInfo->width,
            _imageInfo->height,
            _imageInfo->hMemDC,
            0,
            0,
            SRCCOPY
        );
    }
}

// �����̴� ��ü
void GImage::render(HDC hdc, int destX, int destY)
{
    if (_isTrans)
    {
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                    // ������ ����� DC (ȭ�� DC)
            destX,                  // ����� ��ǥ ���� X
            destY,                  // ����� ��ǥ ���� Y
            _imageInfo->width,      // ����� �̹��� ���� ũ��
            _imageInfo->height,     // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,     // ����� ��� �޸� DC
            0,                      // ���� �������� X
            0,                      // ���� �������� Y
            _imageInfo->width,      // ���� ���� ���� ũ��
            _imageInfo->height,     // ���� ���� ���� ũ��
            _transColor             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBlt() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            destX,
            destY,
            _imageInfo->width,
            _imageInfo->height,
            _imageInfo->hMemDC,
            0,
            0,
            SRCCOPY
        );
    }
}


// �̹��� Ŭ���� : ���� �̹����� �����ؼ� ����, ���� ũ�⸦ �߶� ���� ���ϴ°��� ����
void GImage::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
    if (_isTrans)
    { 
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                    // ������ ����� DC (ȭ�� DC)
            destX,                  // ����� ��ǥ ���� X
            destY,                  // ����� ��ǥ ���� Y
            sourWidth,              // ����� �̹��� ���� ũ��
            sourHeight,              // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,     // ����� ��� �޸� DC
            sourX,                  // ���� �������� X
            sourY,                  // ���� �������� Y
            sourWidth,              // ���� ���� ���� ũ��
            sourHeight,              // ���� ���� ���� ũ��
            _transColor             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            destX,
            destY,
            sourWidth,
            sourHeight,
            _imageInfo->hMemDC,
            sourX,
            sourY,
            SRCCOPY
        );
    }
}

// ���ķ��� -> ���ȭ���� ���̵� �� / �ƿ�
void GImage::alphaRender(HDC hdc, BYTE alpha)
{
    // ���ĺ��� ó�� ����?
    // �� ����� �� �ֵ��� �ʱ�ȭ ���� �����Ѵ�.
    if (!_blendImage)
    {
        initForAlphaBlend();
    }

    _blendFunc.SourceConstantAlpha = alpha;

    if (_isTrans)
    {
        // 1. ����ؾ� �� DC�� �׷��� �ִ� ������ ���� �̹����� �׸���.
        BitBlt
        (
            _blendImage->hMemDC,
            0, 0,
            _imageInfo->width,
            _imageInfo->height,
            hdc,
            0, 0,
            SRCCOPY
        );

        // 2. ���� �̹����� ����� ���� �� ���� �̹����� �׸���.
        GdiTransparentBlt
        (
            _blendImage->hMemDC,            // ������ ����� DC (ȭ�� DC)
            0,                              // ����� ��ǥ ���� X
            0,                              // ����� ��ǥ ���� Y
            _imageInfo->width,              // ����� �̹��� ���� ũ��
            _imageInfo->height,              // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,              // ����� ��� �޸� DC
            0,                              // ���� �������� X
            0,                              // ���� �������� Y
            _imageInfo->width,              // ���� ���� ���� ũ��
            _imageInfo->height,              // ���� ���� ���� ũ��
            _transColor                      // ������ �� ������ ���� (����Ÿ) 
        );

        // 3. ���� �̹����� ȭ�鿡 �׸���.
        AlphaBlend
        (
            hdc,
            0, 0,
            _imageInfo->width,
            _imageInfo->height,
            _blendImage->hMemDC,
            0, 0,
            _imageInfo->width,
            _imageInfo->height,
            _blendFunc
        );


    }
    else
    {
        // �׳� �׸���.
        AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
            _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
    }

}

void GImage::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
    // ���ĺ��� ó�� ����?
    // �� ����� �� �ֵ��� �ʱ�ȭ ���� �����Ѵ�.
    if (!_blendImage)
    {
        initForAlphaBlend();
    }

    _blendFunc.SourceConstantAlpha = alpha;

    if (_isTrans)
    {
        // 1. ����ؾ� �� DC�� �׷��� �ִ� ������ ���� �̹����� �׸���.
        BitBlt
        (
            _blendImage->hMemDC,
            0, 0,
            _imageInfo->width,
            _imageInfo->height,
            hdc,
            destX, destY,
            SRCCOPY
        );

        // 2. ���� �̹����� ����� ���� �� ���� �̹����� �׸���.
        GdiTransparentBlt
        (
            _blendImage->hMemDC,            // ������ ����� DC (ȭ�� DC)
            0,                              // ����� ��ǥ ���� X
            0,                              // ����� ��ǥ ���� Y
            _imageInfo->width,              // ����� �̹��� ���� ũ��
            _imageInfo->height,              // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,              // ����� ��� �޸� DC
            0,                              // ���� �������� X
            0,                              // ���� �������� Y
            _imageInfo->width,              // ���� ���� ���� ũ��
            _imageInfo->height,              // ���� ���� ���� ũ��
            _transColor                      // ������ �� ������ ���� (����Ÿ) 
        );

        // 3. ���� �̹����� ȭ�鿡 �׸���.
        AlphaBlend
        (
            hdc,
            destX, destY,
            _imageInfo->width,
            _imageInfo->height,
            _blendImage->hMemDC,
            0, 0,
            _imageInfo->width,
            _imageInfo->height,
            _blendFunc
        );
    }
    else
    {
        // �׳� �׸���.
        AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
            _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
    }

}

void GImage::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHegiht, BYTE alpha)
{
}

void GImage::frameRender(HDC hdc, int destX, int destY)
{
    if (_isTrans)
    {
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                                     // ������ ����� DC (ȭ�� DC)
            destX,                                   // ����� ��ǥ ���� X
            destY,                                   // ����� ��ǥ ���� Y
            _imageInfo->frameWidth,                   // ����� �̹��� ���� ũ��
            _imageInfo->frameHeight,                   // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,                      // ����� ��� �޸� DC
            _imageInfo->currentFrameX * _imageInfo-> frameWidth,                  // ���� �������� X
            _imageInfo->currentFrameY * _imageInfo->frameHeight,                  // ���� �������� Y
            _imageInfo->frameWidth,                 // ���� ���� ���� ũ��
            _imageInfo->frameHeight,                  // ���� ���� ���� ũ��
            _transColor                             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            destX,
            destY,
            _imageInfo->frameWidth, 
            _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            _imageInfo->currentFrameX * _imageInfo->frameWidth,
            _imageInfo->currentFrameY * _imageInfo->frameHeight,
            SRCCOPY
        );
    }
}

void GImage::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
    // �̹��� ����ó��
    _imageInfo->currentFrameX = currentFrameX;
    _imageInfo->currentFrameY = currentFrameY;

    if (currentFrameX > _imageInfo->maxFrameX)
    {
        _imageInfo->currentFrameX = _imageInfo->maxFrameX;
    }
    if (currentFrameY > _imageInfo->maxFrameY)
    {
        _imageInfo->currentFrameY = _imageInfo->maxFrameY;
    }

    if (_isTrans)
    {
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                                     // ������ ����� DC (ȭ�� DC)
            destX,                                   // ����� ��ǥ ���� X
            destY,                                   // ����� ��ǥ ���� Y
            _imageInfo->frameWidth,                   // ����� �̹��� ���� ũ��
            _imageInfo->frameHeight,                   // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,                      // ����� ��� �޸� DC
            _imageInfo->currentFrameX * _imageInfo->frameWidth,                  // ���� �������� X
            _imageInfo->currentFrameY * _imageInfo->frameHeight,                  // ���� �������� Y
            _imageInfo->frameWidth,                 // ���� ���� ���� ũ��
            _imageInfo->frameHeight,                  // ���� ���� ���� ũ��
            _transColor                             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            destX,
            destY,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            _imageInfo->currentFrameX * _imageInfo->frameWidth,
            _imageInfo->currentFrameY * _imageInfo->frameHeight,
            SRCCOPY
        );
    }
}

void GImage::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int sizeX, int sizeY)
{
    // �̹��� ����ó��
    _imageInfo->currentFrameX = currentFrameX;
    _imageInfo->currentFrameY = currentFrameY;

    if (currentFrameX > _imageInfo->maxFrameX)
    {
        _imageInfo->currentFrameX = _imageInfo->maxFrameX;
    }
    if (currentFrameY > _imageInfo->maxFrameY)
    {
        _imageInfo->currentFrameY = _imageInfo->maxFrameY;
    }

    if (_isTrans)
    {
        // GdiTransparentBlt() : ��Ʈ���� �ҷ��� �� Ư�� ������ �����ϰ� �����Ѵ�.
        GdiTransparentBlt
        (
            hdc,                                     // ������ ����� DC (ȭ�� DC)
            destX,                                   // ����� ��ǥ ���� X
            destY,                                   // ����� ��ǥ ���� Y
           sizeX,                   // ����� �̹��� ���� ũ��
           sizeY,                   // ����� �̹��� ���� ũ��
            _imageInfo->hMemDC,                      // ����� ��� �޸� DC
           _imageInfo->currentFrameX * _imageInfo->frameWidth,                  // ���� �������� X
           _imageInfo->currentFrameY * _imageInfo->frameHeight,                 // ���� �������� Y
            _imageInfo->frameWidth,                 // ���� ���� ���� ũ��
            _imageInfo->frameHeight,                  // ���� ���� ���� ũ��
            _transColor                             // ������ �� ������ ���� (����Ÿ) 
        );
    }
    else
    {
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
        // �� SRCCOPY : �ҽ� ������ ������ �����Ѵ�.
        BitBlt
        (
            hdc,
            destX,
            destY,
            _imageInfo->frameWidth,
            _imageInfo->frameHeight,
            _imageInfo->hMemDC,
            _imageInfo->currentFrameX * _imageInfo->frameWidth, 
            _imageInfo->currentFrameY * _imageInfo->frameHeight,
            SRCCOPY
        );
    }

}

