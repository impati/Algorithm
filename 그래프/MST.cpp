//****************MST************** //
#include<queue>
#include<iostream>
#include<algorithm>
#define SIZE 101 //정점의 개수.
using namespace std;

//최소 스패닝 트리 MST 알고리즘에 대해 알아보자.
//최소 스패닝 트리란 그래프에서 가장 적은 비용으로 모든 정점을 연결하는 알고리즘이다.
// 크루스칼 알고리즘.
// 1.가장 가중치가 작은 간선부터 연결해준다.
// 2.간선을 통해 연결되는 두 정점이 이미 연결이 되어 있다면 연결하지 않는다.
// 3.최종적으로 (정점의 개수-1)개의 간선을 추가하면 알고리즘을 종료한다.
struct UF {
	int parent[SIZE];
	int n;
	UF(int n):n(n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int idx) {
		if (parent[idx] == idx)return idx;
		else return parent[idx] = find(parent[idx]);
	}
	void union_(int v1, int v2) {
		v1 = find(v1), v2 = find(v2);
		if (v1 < v2)
			parent[v2] = v1;
		else
			parent[v1] = v2;
	}
	bool is_union_(int v1, int v2) {
		v1 = find(v1); v2 = find(v2);
		if (v1 == v2)return true;
		else return false;
	}
};
struct graph {
	int v1, v2, w;
	bool operator < (const graph & ref)const {
		return w > ref.w;
	}
};
int main() {

	priority_queue<graph>pq;
	vector<int>adj[SIZE];
	for (int i = 0; i < SIZE; i++) {
		int v1, v2,w;
		cin >> v1 >> v2 >> w;//연결정보
		pq.push({ v1,v2,w });
	}
	UF connect(SIZE);
	int count = 0;//연결된 컴포넌트
	int value = 0;//최소 가중치로 그래프만드는 값.
	while (!pq.empty()) {
		graph here = pq.top();
		pq.pop();
		if (!connect.is_union_(here.v1, here.v2)) {
			connect.union_(here.v1, here.v2);
			value += here.w;
		}
		if (count == SIZE - 1)break;
	}
	cout << value; // 최소비용의 스패닝트리.
	return 0;
}