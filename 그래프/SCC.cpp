#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define SIZE 111
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
vector<int>adj[SIZE];
struct SCC {
	int innate,cnt;
	stack<int>st;
	vector<int>finish, visited;
	vector<int>scc[SIZE];
	SCC() {
		innate = 0; cnt = 1;
		finish.assign(SIZE,0);
		visited.assign(SIZE, 0);
	}
	int get_scc(int v) {
		visited[v] = ++innate;
		int par = visited[v];
		st.push(v);
		for (auto &nxt : adj[v]) {
			if (visited[nxt] == 0) {
				par = min(par, get_scc(nxt));
			}
			else if (finish[nxt] == 0) {
				par = min(par, visited[nxt]);
			}
		}
		if (par == visited[v]) {
			while (!st.empty()) {
				int t = st.top();
				st.pop();
				scc[cnt].push_back(t);
				finish[t] = cnt;
				if (t == v)break;
			}
			cnt++;
		}
		return par;
	}
};
int main() {
	fastio;
	int n, m;
	//연결정보
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
	}
	SCC s;
	for (int i = 0; i < n; i++) {
		if (s.visited(i) == 0)s.get_scc(i);
	}
	
	return 0;
}