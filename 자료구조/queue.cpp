//queue��ü�� ����غ���.
#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	//���� ����ϴ� ����Լ���..
	for (int i = 0; i < 10; i++)//push
		q.push(i);
	q.size();
	while (!q.empty()) {
		cout << q.front() <<" "<<q.back()<< endl;//�Ǿհ� �ǵ�
		q.pop();// ����.
	}
	return 0;
}