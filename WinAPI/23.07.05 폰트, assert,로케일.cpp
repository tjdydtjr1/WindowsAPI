/*
// SetBkMode() : �ؽ�Ʈ ���۵��� �����ϰ� �Ѵ�.
	SetBkMode(getMemDC(), TRANSPARENT);

	// ���� �ؽ�Ʈ
	char str[128];
	wsprintf(str, "����");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	// ���ο� ���
	HFONT font;
	HFONT oldFont;
	/*
	font = CreateFont
	(
		����ũ��, ������, ���� (��ü), ���� ����, ���� ����,
		���� (t / f), ���� (t / f), ��Ҽ�,
		���� ����, ��� ��Ȯ��, Ŭ���� ��Ȯ��, ����� ��, �ڰ�
	);
	
font = CreateFont
(
	70, 0, 0, 0, 600,
	0, 0, 1,
	HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("�޸ձ���")
);

oldFont = (HFONT)::SelectObject(getMemDC(), font);
wsprintf(str, "���ο� ��Ʈ");
TextOut(getMemDC(), 100, 400, str, strlen(str));

SelectObject(getMemDC(), oldFont);
DeleteObject(font);
*/

/*
_start = new StartScene;
	_start->init();

	_second = new SecondScene;
	_second->init();

	// _currentScene -> �õ��� �ȵǸ� �׳� ���� ��ü�� �ȵȴ�. -> ���� ������ �ʿ䵵 ����.
	_currentScene = _start;

	// <-> : assert�� �������� �� �ּ� �Ǵ� �����ϱ� ���� �ּ����� ǥ���Ѵ�.
	assert(_currentScene != nullptr);
	//assert(_currentScene != nullptr, "MainGame �ʱ�ȭ �κп��� ��Ʈ ��Ʈ ���� �߻�");


	/*

	������ 1 ~ 2�� ��� -> ���� �ڸ��� ��� �� ������ ���
	=> assert
	- ����� ��忡�� �����ϴ� ���� ����� �Լ�
	�� ������ ��忡���� �������� �ʴ´�.

	- assert �Լ��� �ɸ��� �Ǹ� ���� �߻� ��ġ / �� ���õ� ���� ������ �� �� �ִ�.
	�� Expression -> false -> assert error

	- ��κ� ������ true�϶��� ���������� assert()�� ������ �� ������ �Ѵ�.
	�� �׷��� ������ �Ͼ�� �ȵǴ� ������ �ƴ϶� �� �Ͼ�� �ϴ� ������ ����ؾ� �Ѵ�.

	EX) assert(A != NULL)
		�� A�� NULL�� �ƴϸ� true�� ������ �ǹǷ� �н�
		�� A�� NULL�� �´ٸ� false�� ������ �ǹǷ� assert error

	C / C++
	assert() : "C" -> ������ Ÿ���� ���� ���α׷��� �����Ű�� ������ �ľ��ϰڴ�.
	static_assert() : "C++" -> ������ �߿� ������ �ľ� => ������? = ��� ��

	*/

*/