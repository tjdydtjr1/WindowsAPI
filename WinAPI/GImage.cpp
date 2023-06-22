#include "Stdafx.h"
#include "GImage.h"

GImage::GImage() 
    : _imageInfo(nullptr)
    , _fileName(nullptr)
    , _isTrans(false)
    , _transColor(RGB(0, 0, 0))
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
        // BitBit() : DC���� �������� ���� ��� ���縦 ���ش�. 
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

