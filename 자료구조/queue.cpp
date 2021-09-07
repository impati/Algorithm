//queue객체를 사용해보자.
#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	//자주 사용하는 멤버함수들..
	for (int i = 0; i < 10; i++)//push
		q.push(i);
	q.size();
	while (!q.empty()) {
		cout << q.front() <<" "<<q.back()<< endl;//맨앞과 맨뒤
		q.pop();// 삭제.
	}
	return 0;
}