//deque객체를 사용해보자.
#include<iostream>
#include<deque>
using namespace std;
int main() {

	deque<int>dq;//객체 생성
	//자주 사용하는 멤버함수들
	dq.back();
	dq.front();
	dq.push_back(3);
	dq.push_front(3);
	dq.empty();
	dq.pop_back();
	dq.pop_front();

	return 0;
}
