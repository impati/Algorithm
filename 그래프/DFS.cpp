//****************DFS************** //
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define SIZE 101
using namespace std;

void DFS(int v);
vector<bool> visit(SIZE, false);
vector<int>gr[SIZE];
int main() {

	//������ �׷��� ����
	int v1, v2;
	for (int i = 0; i < 100; i++) {
		cin >> v1 >> v2;
		gr[v1].push_back(v2);
	}
	int start_node;
	//��������
	cin >> start_node;
	
	//��͸� �̿��� ���̿켱Ž��.
	DFS(start_node);
	
	return 0;
}
void DFS(int v) {
	visit[v] = true;
	cout << v << endl;//�湮����
	for (auto&there : gr[v]) {
		if (visit[there])continue;
		DFS(there);
	}

	return;
}
