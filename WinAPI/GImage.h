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
	HRESULT init(int width, int height);
	
	// bool BOOL 의 모호함 차이
	// 이미지 리소스로 초기화
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	// 이미지 파일로 초기화
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));


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

	// = 인라인 함수 =
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }
	

	// 생성자는 private 변수들의 초기화에 사용
	GImage();

	// 소멸자 안쓰는 이유
	// 1. release로 대체 
	// 2. 추상객체로서 구체화 되는 경우가 없기 때문에
	~GImage() {}

};

