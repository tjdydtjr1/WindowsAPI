#pragma once

#define MOLE_ARR 9
#define TEXT_MAX 255


class MoleGame
{
private:
	RECT _rc[MOLE_ARR];
	POINT _mouseXY;
	bool _state;
	char _text[TEXT_MAX];
	int _score;
public:
	// ���� �⺻Ʋ ����
	void printBaseGame(HDC hdc);
	// Rect ��ǥ ����
	void setRect(int startX, int startY);

	// Rect �迭 ��ǥ ��������
	RECT getRect(int idx) { return _rc[idx]; }
	
	// ���� ����
	//void setScore(int score) { _score = score; }
	void setScore(int score) { _score = score;  }
	int getScore() { return _score; }
	void printScore(HDC hdc) 
	{ 
		wsprintf(_text, "Score : %d", _score); 
		TextOut(hdc, 600, 10, _text, strlen(_text)); 
	}


	// ���°� �����ϱ� ( ���콺 �浹 üũ)
	void setState(bool state) { _state = state; }
	// ���°� ��������
	bool getState() { return _state; }

	// �簢�� �浹ü������ ���콺 ��ǥ ����
	bool checkXY(long mouseX, long mouseY);

	// �⺻ Rect ��ġ
	void printRect(HDC hdc);
	// �⺻ Ÿ�� ��ġ
	void printEllipse(HDC hdc);

	// �����ϰ� ���� ��ġ
	void printMole(HDC hdc);
	
	MoleGame()
		: _state(false)
		, _text{0}
		, _score(0)
	{}
	~MoleGame() {}

};

/*
state = false
random => 3�ʸ��� true�� ����

-> true������ �� ���콺 Ŭ�� ����
�⺻ �簢�� �浹ü �� ��ǥ = ���콺 xy ��ǥ ������
-> ���°� ���� => state = false

�⺻Ʋ �簢�� -> ������ ǥ�� -> true�϶� ���� ����



*/