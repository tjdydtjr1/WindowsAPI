#pragma once
#include "GameNode.h"

enum EMotion
{
	MOVE = 1,
	OUTER,
	STING,
	QUICKSTING,
	DIAGONALSTING,
	JUMP,
	CL,
};

class Motion : public GameNode
{

	// ������ �̹���
	GImage* _bgImage;
	// ��ŸƮ
	GImage* _startImage;
	// �¿� �̵�
	GImage* _move;
	// �ѿ� 
	GImage* _outer;
	// ���
	GImage* _sting;
	// ������ ���
	GImage* _quickSting;
	// �밢�� ���
	GImage* _diagonalSting;

	// ���� ����
	GImage* _jump;

	// Ŭ���̸���
	GImage* _cl;

	char text[128];

	bool _isStart;
	RECT _startBox;

	RECT _moveBox;
	RECT _outerBox;
	RECT _stingBox;
	RECT _quickStingBox;
	RECT _diagonalStingBox;
	RECT _jumpBox;
	RECT _clBox;
	
	// ���� ��
	int _alphaA;
	// ������ ���� ī��Ʈ
	int _count;
	// ������ �̹��� �ε���
	int _index;
	// ���� üũ
	bool _isLeft;

	bool _isAlphaIncrese;

	int _outerCount;
	int _stingCount;
	int _quickStingCount;
	int _diagonalStingCount;
	int _jumpCount;
	int _clCount;

	// ����ġ��
	int _motion;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Motion() {}
	~Motion() {}

};

