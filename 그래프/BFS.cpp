//****************BFS************** //
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define SIZE 101
using namespace std;

void BFS();
int main() {

	// ����ġ�� ������ �ִܰŸ� �˰���
	// �ʺ�켱Ž��
	// ť�� �̿��� �׷��� Ž��
	BFS();
	
	return 0;
}
void BFS() {
	vector<int> gr[SIZE];
	vector<bool>visit(SIZE, false);
	//������ �׷��� ����
	int v1, v2;
	for (int i = 0; i < 10; i++) {
		cin >> v1 >> v2;
		gr[v1].push_back(v2);
	}
	int start;//(�ƹ��ų�) ������������ ���� �ʺ�켱 Ž���� ����.
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		visit[here] = true;
		// cout<<here<<endl;  �湮 ����.
		q.pop();
		for (auto &there : gr[here]) {
			if(visit[there])continue;
			q.push(there);
		}
	}
	return;
}
