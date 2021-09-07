//****************BFS************** //
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define SIZE 101
using namespace std;

void BFS();
int main() {

	// 가중치가 동일한 최단거리 알고리즘
	// 너비우선탐색
	// 큐를 이용한 그래프 탐색
	BFS();
	
	return 0;
}
void BFS() {
	vector<int> gr[SIZE];
	vector<bool>visit(SIZE, false);
	//임의의 그래프 정보
	int v1, v2;
	for (int i = 0; i < 10; i++) {
		cin >> v1 >> v2;
		gr[v1].push_back(v2);
	}
	int start;//(아무거나) 시작정점으로 부터 너비우선 탐색을 수행.
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		visit[here] = true;
		// cout<<here<<endl;  방문 순서.
		q.pop();
		for (auto &there : gr[here]) {
			if(visit[there])continue;
			q.push(there);
		}
	}
	return;
}
