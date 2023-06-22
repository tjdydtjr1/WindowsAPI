/*

이미지 GDI -> GDI+     / D2D
1. 렌더
2. 알파 투명도 : 깜빡거림 스테이지 전환
3. 클리핑 => GDI+ 최적화 : 맵을 전체가 아닌 필요한 부분만 그려야함
4. 프레임(애니메이션) : 스프라이트의 연속
5. 루프 : 반복 -> 런게임 종류

 IntersectRect() : 교집합을 구하는 함수 (RECT 끼리의)
- 첫번째 인자는 두 사각형 A, B가 충돌했을 때 생기는 사각형
- 이 부분의 크기가 존재한다면 충돌이 된것이고 아니라면 충돌이 안된것
- 2번 인자의 렉트와 3번 인자의 렉트가 겹치는 영역이 생기면 1번 렉트에 저장을 한다.
- 충돌을 감지하면 충돌한 인자의 포인터 전달
  ㄴ 충돌이 없으면 0 / 충돌이 발생한 상황이라면 NON ZERO 반환

RECT temp;
for (int i = 0; i < ENEMY_MAX; ++i)
{
	for (int j = 0; i < BULLET_MAX; ++j)
	{
		   // if문을 사용해서 반환값이 true일 경우에 코드를 작성하면 OK
		if (IntersectRect(&temp, &_enemy[i].rc, &_bullet[j].rc))
		{
		}
	}
}
*/
/*
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
/*
// 생성자는 private 변수들의 초기화에 사용
GImage();

 소멸자 안쓰는 이유
 1. release로 대체 
 2. 추상객체로서 구체화 되는 경우가 없기 때문에
~GImage() {}


참고 : 이미지 파일이 없을 경우 컴파일러가 정상적인 곳을 가리키며 에러를 띄움

*/
/*
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

		BitBit() : DC간의 영역끼리 서로 고속 복사를 해준다.
		ㄴ SRCCOPY : 소스 영역을 영역에 복사한다.

*/

/*

한줄 조사.
_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	LoadBitmap, MAKEINTRESOURCE

*/