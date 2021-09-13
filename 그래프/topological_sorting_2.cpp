//****************topological sorting 2************** //

// 선후관계에 대한 정렬
// 1.진입차수가 0인 노드들을 큐에넣고 
// 2 빼면서 진입차수를 줄여준다.
// 3.1-2번을 반복한다.
// 큐에서 뺸 집합이 전체 정점 수보다 작으면 위상정렬을 수행할 수 없다.
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#define SIZE 100
using namespace std;
vector<int>adj[SIZE];
vector<int>in(SIZE, 0);//진입차수
queue<int>q;
int main() {
	int n, m;
	cin >> n >> m;
	//순서정보입력받는다.
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		in[v2] += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)q.push(i);//진입차수가 0인 정점을 큐에 넣는다.
	}
	vector<int>ret;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		ret.push_back(here);
		for (auto &there : adj[here]) {
			in[there] -= 1;
			if (in[there] == 0)q.push(there);
		}
	}
	for (auto &ele : ret) {
		cout << ele << " ";
	}


	return 0;
}