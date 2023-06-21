/*
// 설계 연습
#define BULLET_MAX 5
#define PLAYER_SPEED 5
// 80개의 단일 이미지는 STL X => 애니메이션효과로 인해 텍스처가 많이 들어가면 사용해야한다.
#define ENEMY_MAX 30
// MAX? => 배열 => STL 사용도 생각하기


// 키를 누른다는 이벤트를 통해 파생 코드들이 발생 => 필수 조건문
키 입력의 if문은 필수 사항 줄일 수 없음

if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		// 플레이어 적과 달리 총알은 메모리 사용량이 많기 때문에
		// 메모리를 스택에서 사용후 제거한다.
		fireBullet();
	}

*/