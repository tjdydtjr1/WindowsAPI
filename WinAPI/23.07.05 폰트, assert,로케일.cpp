/*
// SetBkMode() : 텍스트 버퍼등을 투명하게 한다.
	SetBkMode(getMemDC(), TRANSPARENT);

	// 기존 텍스트
	char str[128];
	wsprintf(str, "기존");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	// 새로운 방식
	HFONT font;
	HFONT oldFont;
	/*
	font = CreateFont
	(
		문자크기, 문자폭, 기울기 (전체), 문자 방향, 문자 굵기,
		기울기 (t / f), 밑줄 (t / f), 취소선,
		문자 세팅, 출력 정확도, 클리핑 정확도, 출력의 질, 자간
	);
	
font = CreateFont
(
	70, 0, 0, 0, 600,
	0, 0, 1,
	HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("휴먼굴림")
);

oldFont = (HFONT)::SelectObject(getMemDC(), font);
wsprintf(str, "새로운 폰트");
TextOut(getMemDC(), 100, 400, str, strlen(str));

SelectObject(getMemDC(), oldFont);
DeleteObject(font);
*/

/*
_start = new StartScene;
	_start->init();

	_second = new SecondScene;
	_second->init();

	// _currentScene -> 시동이 안되면 그냥 실행 자체가 안된다. -> 굳이 돌려볼 필요도 없다.
	_currentScene = _start;

	// <-> : assert를 릴리즈할 때 주석 또는 제거하기 위해 주석으로 표시한다.
	assert(_currentScene != nullptr);
	//assert(_currentScene != nullptr, "MainGame 초기화 부분에서 노트 파트 오류 발생");


	/*

	포폴에 1 ~ 2개 사용 -> 영상 자막에 어디에 왜 썻는지 명시
	=> assert
	- 디버깅 모드에서 동작하는 오류 검출용 함수
	ㄴ 릴리즈 모드에서는 동작하지 않는다.

	- assert 함수에 걸리게 되면 버그 발생 위치 / 콜 스택등 여러 정보를 알 수 있다.
	ㄴ Expression -> false -> assert error

	- 대부분 문법이 true일때만 동작하지만 assert()은 거짓일 때 동작을 한다.
	ㄴ 그렇기 때문에 일어나면 안되는 조건이 아니라 꼭 일어나야 하는 조건을 명시해야 한다.

	EX) assert(A != NULL)
		ㄴ A가 NULL이 아니면 true가 나오게 되므로 패스
		ㄴ A가 NULL이 맞다면 false가 나오게 되므로 assert error

	C / C++
	assert() : "C" -> 컴파일 타임을 지나 프로그램을 실행시키고 문제를 파악하겠다.
	static_assert() : "C++" -> 컴파일 중에 문제를 파악 => 컴파일? = 상수 값

	*/

*/