//****************dijkstra************** //
//���� �������κ��� �ٸ� ������ ���������� �ִܰŸ��� O(ElogV)�� ���� �� �ִ�.
#include<iostream>
#include<vector>
#include<queue>
#define SIZE 101
#define INF 987654321
using namespace std;

vector<pair<int, int>>adj[SIZE];
struct  Dijkstra {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	vector<int>dist;
	vector<bool>visit;
	Dijkstra(){
		dist.assign(SIZE, INF);
		visit.assign(SIZE, INF);
	}
	void dijkstra(int s) {
		dist[s] = 0;
		pq.push({ dist[s],s });
		while (!pq.empty()) {
			int here = pq.top().second;
			pq.pop();
			visit[here] = true;
			for (auto &there : adj[here]) {
				if (visit[there.first])continue;
				if (dist[there.first] < dist[here] + there.second) {
					dist[there.first] = dist[here] + there.second;
					pq.push({ dist[there.first],there.first });
				}
			}
		}
	}

};
int main() {
	int n, m;
	//������ 1���� n������ ��ȣ�� ������ �ִٰ� �����ϰ� ���������� 1�� �Ѵ�.
	//�׷��� ���� ���� �Է�
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		// v1->v2�� ����ǰ� ����ġ�� w�̴�.
		cin >> v1 >> v2 >> w;
		adj[v1].push_back({ v2,w });
	}
	Dijkstra d;


	d.dijkstra(1);
	for (int i = 1; i <= n; i++) {
		cout << d.dist[i] << endl;
	}



	return 0;
}
