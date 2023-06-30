/*
// 1. ��ü�� ���� new
// 2. ���� ����
// �� STL -> Map, Vector Ư¡ �����غ��� => void func �������� ����
//			��Unordered Map �˻��ӵ��� ������.(�ߺ�X)
//

*/

#pragma region STL ��
/*
- Ű + ���� ���� ����.
�� ù��° first -> Ű
�� �ι�° second -> ��

- �߰��ϴ� ����� insert()�� ����ϰ� Ű�� ������ ���ÿ� �߰��ؾ� �ϴ� pair / make_pair ���

- pair() : �� ���� �ڷ����� �ϳ��� �����ִ� ����ü (���ø� -> � �ڷ����� ����)

- make_pair() : pair�� ����� �ִ� �Լ�
�� pair.first = x; / pari.second = y;
�� pair = make_pair(x, y);

- �ϳ��� Ű�� �������� ���� �����ϰ� �ʹٸ� ��Ƽ���� ����ϴ� �͵� ���
- pair�� Ȯ����� ������ �ۼ��ϰų� �ټ��� ��ȯ���� ������ �ʹٸ� tuple�� ����ؾ� �Ѵ�.
*/
#pragma endregion


/*
// map ���� char*�� �ƴ� string�� ���� ����
	// �� iterator���� ��ȸ�� ���ƾ������� char*�� ����ִ� �޸𸮸� Ȯ���ϴ� �߰� �۾��� ���ܼ�
	//	  ��������.

	typedef map<string, GImage*> mapImageList;
	typedef map<string, GImage*>::iterator mapImageIter;


*/

// �ܵ�ó�� �� ������
// �� 1. �����ӿ�ũ �ڵ� ����ġ
// �� 2. ��ü�� (�̹���) �浹 ���ɼ�
// �� GImage* �� �����ϴ� �Լ��� ���� ������ �Ѽ����� �ʰ� ����Ѵ�.


/*
// ��Ȳ�� ���� ���� pair, make_pair
// pair ��Ȯ�ϰ� �ڷ����� ������شٴ� ������ �ִ�.
//_mImageList.insert(std::pair<string, GImage*>(strKey, img));
// ����� ���غ��̳� �ڷ��� ��ð� ����
_mImageList.insert(make_pair(strKey, img));

*/

