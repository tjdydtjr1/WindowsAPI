/*
// 1. 객체에 따른 new
// 2. 관리 문제
// ㄴ STL -> Map, Vector 특징 생각해보기 => void func 마지막에 생각
//			ㄴUnordered Map 검색속도가 빠르다.(중복X)
//

*/

#pragma region STL 맵
/*
- 키 + 값을 잊지 말자.
ㄴ 첫번째 first -> 키
ㄴ 두번째 second -> 값

- 추가하는 방법은 insert()로 사용하고 키와 벨류를 동시에 추가해야 하니 pair / make_pair 사용

- pair() : 두 가지 자료형을 하나로 묶어주는 구조체 (템플릿 -> 어떤 자료형도 가능)

- make_pair() : pair를 만들어 주는 함수
ㄴ pair.first = x; / pari.second = y;
ㄴ pair = make_pair(x, y);

- 하나의 키에 여러개의 값을 저장하고 싶다면 멀티맵을 사용하는 것도 고려
- pair를 확장시켜 구조를 작성하거나 다수의 반환값을 가지고 싶다면 tuple도 고려해야 한다.
*/
#pragma endregion


/*
// map 에서 char*가 아닌 string를 쓰는 이유
	// ㄴ iterator에서 순회를 돌아야하지만 char*에 들어있는 메모리를 확인하는 추가 작업이 생겨서
	//	  느려진다.

	typedef map<string, GImage*> mapImageList;
	typedef map<string, GImage*>::iterator mapImageIter;


*/

// 단독처리 시 문제점
// ㄴ 1. 프레임워크 코드 불일치
// ㄴ 2. 객체간 (이미지) 충돌 가능성
// ㄴ GImage* 를 참조하는 함수를 통해 원본을 훼손하지 않고 사용한다.


/*
// 상황에 따라 쓰자 pair, make_pair
// pair 정확하게 자료형을 명시해준다는 장점이 있다.
//_mImageList.insert(std::pair<string, GImage*>(strKey, img));
// 사용이 편해보이나 자료형 명시가 없음
_mImageList.insert(make_pair(strKey, img));

*/

