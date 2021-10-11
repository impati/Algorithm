/***************************floyd warshall***************************/
#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 111
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int dist[SIZE][SIZE];
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	//초기화
	for (int i = 0; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, INF);
	}
	//그래프의 연결정보
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		dist[v1][v2] = min(dist[v1][v2], w);
	}
	for (int i = 0; i <= n; i++)dist[i][i] = 0;
	//i를 경유하여
	for (int i = 0; i <= n; i++) {
		//k to j
		for (int k = 0; k <= n; k++) {
			for (int j = 0; j <= n; j++) {
				if (dist[k][j] > dist[k][i] + dist[i][j]) {
					dist[k][j] = dist[k][i] + dist[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (dist[i][k] == INF)cout << "0" << " ";
			else cout << dist[i][k] << " ";
		}
		cout << "\n";
	}
	return 0;
}