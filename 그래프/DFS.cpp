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

	//임의의 그래프 정보
	int v1, v2;
	for (int i = 0; i < 100; i++) {
		cin >> v1 >> v2;
		gr[v1].push_back(v2);
	}
	int start_node;
	//시작정점
	cin >> start_node;
	
	//재귀를 이용한 깊이우선탐색.
	DFS(start_node);
	
	return 0;
}
void DFS(int v) {
	visit[v] = true;
	cout << v << endl;//방문순서
	for (auto&there : gr[v]) {
		if (visit[there])continue;
		DFS(there);
	}

	return;
}
