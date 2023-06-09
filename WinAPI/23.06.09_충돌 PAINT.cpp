/*
 RECT, LPRECT
 RECT : 사각형의 좌표를 저장하기 위한 구조체
 충돌에 적합함(원보다 연산이 적음) -> 충돌체 위에 이미지를 덧씌워서 움직임

 API 방식 AABB RECT의 사각형이 회전하지 않는다.
 DC상에서 회전을 막음 회전할 시 깨짐

 AABB 방식 -> 사각형 그대로 유지
 OBB 방식 -> 오브젝트의 움직임에 따라 사각형이 회전한다.
 ㄴ 정밀도가 AABB보다 높지만 연산이 많이 필요한다.

 SetPixel()
 픽셀 충돌 (색상 검출) -> 2D 곡선, 대각선(계단) 충돌에 쓰임
 ㄴ 버텍스 개념을 쓰지 않기에 상대적으로 OBB보다 연산이 가볍다.
 ㄴ 많이 쓰면 색상값 검출을 위한 검사를 해야하기 때문에 프레임 드랍이 생김 
 
 */
/*
=> WM_PAINT
- 윈도우를 다시 그려야 할때 사용하는 메세지
1. 윈도우가 처음 만들어졌을 때
2. 윈도우 크기를 조절하고 싶을 때
3. 윈도우가 다른 윈도우에 가려졌다가 다시 보일 때
4. 특정 함수가 호출될 때 -> InvalidateRect, Invalidate, UpdataAllViews 등등..
   ㄴ 기본적으로 렌더링 관련된 함수가 나오면 PAINT를 떠올려야 한다.
*/
