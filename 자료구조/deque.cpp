//deque��ü�� ����غ���.
#include<iostream>
#include<deque>
using namespace std;
int main() {

	deque<int>dq;//��ü ����
	//���� ����ϴ� ����Լ���
	dq.back();
	dq.front();
	dq.push_back(3);
	dq.push_front(3);
	dq.empty();
	dq.pop_back();
	dq.pop_front();

	return 0;
}
