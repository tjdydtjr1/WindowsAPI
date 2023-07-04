#pragma once
#include "GameNode.h"
// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)

using std::vector;

#define MAX_OBJECT 1000
#define OBJECT_SPEED 5
#define PI 3.14159265358979f

struct Object
{
	RECT rc;
	int x;			// x
	int y;			// y
	int theta;
	bool isCreate;
	POINT xy;   // �̵�
};

class MainGame : public GameNode
{
private:
	std::vector<Object> _objectVec;
	vector<Object>::iterator _iter;
	RECT _blackHole;
	int _idx;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {  }
	~MainGame() {  }

};

