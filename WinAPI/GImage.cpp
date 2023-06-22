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
    // 재 초기화 방지하겠다.
    // 혹시 값이 있다면 먼저 릴리즈하고 접근해라
    if (_imageInfo != nullptr)
    {
        this->release();
    }
    
    // 서브 DC
    HDC hdc = GetDC(_hWnd);

    _imageInfo = new IMAGE_INFO;

    _imageInfo->loadType = LOAD_EMPTY;
    _imageInfo->resID = 0;
    _imageInfo->hMemDC = CreateCompatibleDC(hdc);
    _imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
    _imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
    _imageInfo->width = width;
    _imageInfo->height = height;

    // 사용하지 않음
    _fileName = nullptr;
    _isTrans = false;
    _transColor = RGB(0, 0, 0);


    // 참고 : 이미지 파일이 없을 경우 컴파일러가 정상적인 곳을 가리키며 에러를 띄움
    // 리소스를 얻어 오는데 실패했다.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : 성공 , E_FAIL : 실패 
    }

    ReleaseDC(_hWnd, hdc);

    return S_OK;
}

HRESULT GImage::init(const DWORD resID, int width, int height, bool isTrans, COLORREF transColor)
{
    // 재 초기화 방지하겠다.
    // 혹시 값이 있다면 먼저 릴리즈하고 접근해라
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // 서브 DC
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


    // 참고 : 이미지 파일이 없을 경우 컴파일러가 정상적인 곳을 가리키며 에러를 띄움
    // 리소스를 얻어 오는데 실패했다.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : 성공 , E_FAIL : 실패 
    }

    ReleaseDC(_hWnd, hdc);


    return S_OK;
}

HRESULT GImage::init(const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
    // 재 초기화 방지하겠다.
    // 혹시 값이 있다면 먼저 릴리즈하고 접근해라
    if (_imageInfo != nullptr)
    {
        this->release();
    }

    // 서브 DC
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
    
    // strcpy -> 인자 1개 더 추가
    // ㄴ 고질적인 문자 / 문자열에서 사이즈 문제를 해결한 함수
    // (복사받을 변수, 최대 길이, 원본)
    strcpy_s(_fileName, len + 1, fileName);

    _isTrans = isTrans;
    _transColor = transColor;


    // 참고 : 이미지 파일이 없을 경우 컴파일러가 정상적인 곳을 가리키며 에러를 띄움
    // 리소스를 얻어 오는데 실패했다.
    if (_imageInfo->hBit == 0)
    {
        release();
        return E_FAIL; // S_OK : 성공 , E_FAIL : 실패 
    }

    ReleaseDC(_hWnd, hdc);


    return S_OK;
}

void GImage::setTransColor(bool isTrans, COLORREF transColor)
{
    _isTrans = isTrans;
    _transColor = transColor;
}

// 특히 이미지에서는 매우 중요한 함수
void GImage::release(void)
{
    if (_imageInfo)
    {
        // 이미지를 하나하나 삭제
        SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
        DeleteObject(_imageInfo->hBit);
        DeleteObject(_imageInfo->hMemDC);
        
        // 포인터 삭제
        SAFE_DELETE(_imageInfo);
        SAFE_DELETE_ARRAY(_fileName);

        // 투명 컬러키 초기화
        _isTrans = false;
        _transColor = RGB(0, 0, 0);
    }
}

// 배경화면
void GImage::render(HDC hdc)
{
    if (_isTrans)
    {
        // GdiTransparentBlt() : 비트맵을 불러올 때 특정 색상을 제외하고 복사한다.
        GdiTransparentBlt
        (
            hdc,                    // 복사할 장소의 DC (화면 DC)
            0,                      // 복사될 좌표 시작 X
            0,                      // 복사될 좌표 시작 Y
            _imageInfo->width,      // 복사될 이미지 가로 크기
            _imageInfo->height,     // 복사될 이미지 세로 크기
            _imageInfo->hMemDC,     // 복사될 대상 메모리 DC
            0,                      // 복사 시작지점 X
            0,                      // 복사 시작지점 Y
            _imageInfo->width,      // 복사 영역 가로 크기
            _imageInfo->height,     // 복사 영역 세로 크기
            _transColor             // 복사할 때 제외할 색상 (마젠타) 
        );
    }
    else
    {
        // BitBit() : DC간의 영역끼리 서로 고속 복사를 해준다. 
        // ㄴ SRCCOPY : 소스 영역을 영역에 복사한다.
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

// 움직이는 객체
void GImage::render(HDC hdc, int destX, int destY)
{
    if (_isTrans)
    {
        // GdiTransparentBlt() : 비트맵을 불러올 때 특정 색상을 제외하고 복사한다.
        GdiTransparentBlt
        (
            hdc,                    // 복사할 장소의 DC (화면 DC)
            destX,                  // 복사될 좌표 시작 X
            destY,                  // 복사될 좌표 시작 Y
            _imageInfo->width,      // 복사될 이미지 가로 크기
            _imageInfo->height,     // 복사될 이미지 세로 크기
            _imageInfo->hMemDC,     // 복사될 대상 메모리 DC
            0,                      // 복사 시작지점 X
            0,                      // 복사 시작지점 Y
            _imageInfo->width,      // 복사 영역 가로 크기
            _imageInfo->height,     // 복사 영역 세로 크기
            _transColor             // 복사할 때 제외할 색상 (마젠타) 
        );
    }
    else
    {
        // BitBit() : DC간의 영역끼리 서로 고속 복사를 해준다. 
        // ㄴ SRCCOPY : 소스 영역을 영역에 복사한다.
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

