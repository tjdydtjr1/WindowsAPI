#include "Stdafx.h"
#include "ImageManager.h"

HRESULT ImageManager::init(void)
{
    // ! Do Nothing


    return S_OK;
}

void ImageManager::release(void)
{
    this->deleteAll();

}

GImage* ImageManager::addImage(string strKey, int width, int height)
{
    // 추가하려는 이미지가 존재하는지 키값으로 확인
    GImage* img = findImage(strKey);

    // 이미지가 있으면 그대로 써라
    if (img) 
    {
        return img;
    }

    // 이미지 없다..
    // 없으니까 새로 만든다.
    img = new GImage;

    // 초기화 실패 시 원본을 건들지 않고 내가 만든걸 해제하겠다.
    if (FAILED(img->init(width, height)))
    {
        SAFE_DELETE(img);
            return NULL;
    }

    // 상황에 따라 쓰자 pair, make_pair
    // pair 정확하게 자료형을 명시해준다는 장점이 있다.
    //_mImageList.insert(std::pair<string, GImage*>(strKey, img));
    // 사용이 편해보이나 자료형 명시가 없음
    _mImageList.insert(make_pair(strKey, img));

    return img;
}

GImage* ImageManager::addImage(string strKey, const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
    // 추가하려는 이미지가 존재하는지 키값으로 확인
    GImage* img = findImage(strKey);

    // 이미지가 있으면 그대로 써라
    if (img)
    {
        return img;
    }

    // 이미지 없다..
    // 없으니까 새로 만든다.
    img = new GImage;

    // 초기화 실패 시 원본을 건들지 않고 내가 만든걸 해제하겠다.
    if (FAILED(img->init(fileName, width, height, isTrans, transColor)))
    {
        SAFE_DELETE(img);

        return NULL;
    }

    /*
    위의 조건문
    C / C++
    지역 -> { }

    int*   -> 우선 순위*
    GImage* -> 우선 순위 GImage

    C언에서는 nullptr을 모른다 그렇기에 return 시 함수의 반환형을 다시 확인한다.
    return nullptr;
    return NULL; -> 절차지향 그대로 이행
    
    */


    // 상황에 따라 쓰자 pair, make_pair
    // pair 정확하게 자료형을 명시해준다는 장점이 있다.
    //_mImageList.insert(std::pair<string, GImage*>(strKey, img));
    // 사용이 편해보이나 자료형 명시가 없음
    _mImageList.insert(make_pair(strKey, img));

    return img;
}

GImage* ImageManager::addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool isTrans, COLORREF transColor)
{
    // 추가하려는 이미지가 존재하는지 키값으로 확인
    GImage* img = findImage(strKey);

    // 이미지가 있으면 그대로 써라
    if (img)
    {
        return img;
    }

    // 이미지 없다..
    // 없으니까 새로 만든다.
    img = new GImage;

    // 초기화 실패 시 원본을 건들지 않고 내가 만든걸 해제하겠다.
    if (FAILED(img->init(fileName, x, y, width, height, isTrans, transColor)))
    {
        SAFE_DELETE(img);
        return NULL;
    }

    // 상황에 따라 쓰자 pair, make_pair
    // pair 정확하게 자료형을 명시해준다는 장점이 있다.
    //_mImageList.insert(std::pair<string, GImage*>(strKey, img));
    // 사용이 편해보이나 자료형 명시가 없음
    _mImageList.insert(make_pair(strKey, img));

    return img;
}

GImage* ImageManager::addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
    // 추가하려는 이미지가 존재하는지 키값으로 확인
    GImage* img = findImage(strKey);

    // 이미지가 있으면 그대로 써라
    if (img)
    {
        return img;
    }

    // 이미지 없다..
    // 없으니까 새로 만든다.
    img = new GImage;

    // 초기화 실패 시 원본을 건들지 않고 내가 만든걸 해제하겠다.
    if (FAILED(img->init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
    {
        SAFE_DELETE(img);
        return NULL;
    }

    // 상황에 따라 쓰자 pair, make_pair
    // pair 정확하게 자료형을 명시해준다는 장점이 있다.
    //_mImageList.insert(std::pair<string, GImage*>(strKey, img));
    // 사용이 편해보이나 자료형 명시가 없음
    _mImageList.insert(make_pair(strKey, img));

    return img;
}

GImage* ImageManager::addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
    // 추가하려는 이미지가 존재하는지 키값으로 확인
    GImage* img = findImage(strKey);

    // 이미지가 있으면 그대로 써라
    if (img)
    {
        return img;
    }

    // 이미지 없다..
    // 없으니까 새로 만든다.
    img = new GImage;

    // 초기화 실패 시 원본을 건들지 않고 내가 만든걸 해제하겠다.
    if (FAILED(img->init(fileName, x, y, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
    {
        SAFE_DELETE(img);
        return NULL;
    }

    // 상황에 따라 쓰자 pair, make_pair
    // pair 정확하게 자료형을 명시해준다는 장점이 있다.
    //_mImageList.insert(std::pair<string, GImage*>(strKey, img));
    // 사용이 편해보이나 자료형 명시가 없음
    _mImageList.insert(make_pair(strKey, img));

    return img;
}

GImage* ImageManager::findImage(string strKey)
{
    auto key = _mImageList.find(strKey);

    // 검색한 키를 찾은 경우
    if (key != _mImageList.end())
    {
        return key->second;
    }

    return nullptr;
}

bool ImageManager::deleteImage(string strKey)
{
    auto key = _mImageList.find(strKey);

    // 검색한 키를 찾은 경우
    // ㄴ 맵만 뺄경우 값으로 접근하는 메모리 주소가 없어지므로 순차적으로 넣었으면 반대로 빼줘야함
    if (key != _mImageList.end())
    {
        key->second->release();
        SAFE_DELETE(key->second);
        _mImageList.erase(key);

        return true;
    }

    return false;
}

bool ImageManager::deleteAll()
{
    auto iter = _mImageList.begin();

    // while(true)
    for (; iter != _mImageList.end();)
    {
        if (iter->second != NULL)
        {
            iter->second->release();
            SAFE_DELETE(iter->second);
            iter = _mImageList.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    
    // 다지웠으면
    _mImageList.clear();

    return true;
}

void ImageManager::render(string strKey, HDC hdc)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->render(hdc);
    }
}

void ImageManager::render(string strKey, HDC hdc, int destX, int destY)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->render(hdc, destX, destY);
    }

}

void ImageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
    }
}

void ImageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->alphaRender(hdc, alpha);
    }
}

void ImageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->alphaRender(hdc, destX, destY, alpha);
    }
}

void ImageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
    }
}

void ImageManager::frameRender(string strKey, HDC hdc, int destX, int destY)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->frameRender(hdc, destX, destY);
    }
}

void ImageManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
    }
}

void ImageManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int sizeX, int sizeY)
{
    GImage* img = findImage(strKey);

    if (img)
    {
        img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY, sizeX, sizeY);
    }
}

void ImageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
    GImage* img = findImage(strKey);
    if (img)
    {
        img->loopRender(hdc, drawArea, offsetX, offsetY);
    }
}

void ImageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
    GImage* img = findImage(strKey);
    if (img)
    {
        img->loopAlphaRender(hdc, drawArea, offsetX, offsetY, alpha);
    }
}
