#pragma once
/*
이미지 GDI -> GDI+     / D2D
1. 렌더
2. 알파 투명도 : 깜빡거림 스테이지 전환
3. 클리핑 => GDI+ 최적화 : 맵을 전체가 아닌 필요한 부분만 그려야함
4. 프레임(애니메이션) : 스프라이트의 연속
5. 루프 : 반복 -> 런게임 종류
*/

class GImage
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,		// 리소스, 파일
		LOAD_EMPTY, LOAD_END				// 빈 비트맵, 로드 Done
	};

	typedef struct tagImage
	{
		// DWORD = unsigned long
		DWORD		resID; 
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		
		// 가장 큰 이미지 기준
		float		x;					// 이미지 x 좌표
		float		y;					// 이미지 y 좌표
		int			width;				// 이미지 가로 크기
		int			height;				// 이미지 세로 크기
		int			currentFrameX;		// 현재 프레임 X
		int			currentFrameY;		// 현재 프레임 Y
		int			maxFrameX;			// 최대 프레임 X 갯수
		int			maxFrameY;			// 최대 프레임 Y 갯수
		int			frameWidth;			// 1 프레임 가로 크기
		int			frameHeight;		// 1 프레임 세로 크기
		BYTE		loadType;
		// BYTE = unsigned  0 ~ 255
		tagImage()
		{
			resID = 0;
			hMemDC = nullptr;
			hBit = nullptr;
			hOBit = nullptr;
			width = 0;
			height = 0;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INPO;

private:
	LPIMAGE_INPO _imageInfo;		// 이미지 정보에 대한 구조체
	char*		 _fileName;			// 파일 이름을 찾기 위한 변수
	bool		 _isTrans;			// 캐릭터의 배경색을 뺄지 여부
	COLORREF	 _transColor;		// 뺄꺼면 어떤 색깔로 뺄것인지
									// ㄴ (255, 0, 255) 마젠타 색상으로 많이 뺌
									// ㄴ 게임에서 잘안쓰고 눈에 잘띔
	/*
	COLORREF
	- 윈도우즈에서 색상값을 표현하기 위한 부호없는 32비트 정수형
	ㄴ R, G, B 각각 1바이트 0 ~ 255 까지의 값을 표현하는데 최적화 되어 있다.
	*/

	// 쉐이더, 모바일최적화 -> 알파값 (GDI는 알파값 사용 x)
	BLENDFUNCTION	_blendFunc;		// 알파블렌드 기능
	LPIMAGE_INPO	_blendImage;	// 알파블렌드 이미지

public:
	// 함수 오버로딩 이유
	// ㄴ 이미지가 무겁기 때문에 런타임 중 프리징을 막기 위해
	// ㄴ 필요없는 코스트를 아끼기 위해 인자 한 두개의 차이가 있다.
	// 나누기 연산은 기본적으로 무겁기 때문에 유의하자.
	HRESULT init(int width, int height);
	
	// bool BOOL 의 모호함 차이
	// 이미지 리소스로 초기화
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	// 이미지 파일로 초기화
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	
	// 프레임 이미지 파일로 초기화
	// 한번쓰고 값을 안바꾸는 애들 => 배경 이미지
	HRESULT init(const char* fileName, float x, float y, int width, int height, 
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	
	// 지속적으로 프레임을 올리겠다.
	HRESULT init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, 
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	
	// 플레이어에 사용
	HRESULT init(const char* fileName, float x, float y, int width, int height, 
		int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));


	HRESULT initForAlphaBlend(void);


	// 투명 컬러키 세팅
	void setTransColor(bool isTrans, COLORREF transColor);

	// 해제
	void release(void);

	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	
	// 이미지 클리핑 -> 시작점 끝점 기준으로 가로 세로의 길이를 짜른다.
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	
	// 알파렌더 BYTE = 0 ~ 255
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY,int sourX, int sourY, int sourWidth, int sourHegiht, BYTE alpha);

	// 프레임 렌더
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);



	// = 인라인 함수 =
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }
	
	// 이미지 X 좌표
	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }
	
	// 이미지 Y 좌표
	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	// 이미지 센터좌표
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	// 이미지 가로 / 세로 크기
	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	// 바운딩 박스 (충돌용 렉트)
	inline RECT boundingBox(void)
	{
		RECT rc =
		{
			(int)_imageInfo->x,
			(int)_imageInfo->y,
			(int)_imageInfo->x + _imageInfo->width,
			(int)_imageInfo->y + _imageInfo->height
		};

		return rc;
	}

	// 바운딩 박스 (충돌용 렉트)
	inline RECT boundingBoxWithFrame(void)
	{
		RECT rc =
		{
			(int)_imageInfo->x,
			(int)_imageInfo->y,
			(int)_imageInfo->x + _imageInfo->frameWidth,
			(int)_imageInfo->y + _imageInfo->frameHeight
		};

		return rc;
	}

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;

		// 현재 프레임이 맥스를 넘지 않도록 고정
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
		return _imageInfo->currentFrameX;
	}
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline int setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		
		// 현재 프레임이 맥스를 넘지 않도록 고정
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}

		return _imageInfo->currentFrameY;
	}

	// 이미지 1 프레임 가로 / 세로 크기
	inline int getFrameWidth(void) { return _imageInfo->frameWidth;}
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }
	
	// 최대 프레임 X / Y 갯수
	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }



	// 생성자는 private 변수들의 초기화에 사용
	GImage();

	// 소멸자 안쓰는 이유
	// 1. release로 대체 
	// 2. 추상객체로서 구체화 되는 경우가 없기 때문에
	~GImage() {}

};

