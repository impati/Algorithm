#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
#include<stack>
#define SIZE 1111
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int s = 1, e = 2;
struct edge {
	int v, cap, rev;
	edge(int v,int cap,int rev):v(v),cap(cap),rev(rev){}
};
vector<edge>adj[SIZE];
vector<int>level(SIZE, -1);
void addedge(int s, int e, int c) {
	adj[s].emplace_back(e, c, (int)adj[e].size());
	adj[e].emplace_back(s, 0, (int)adj[s].size() - 1);
}
bool bfs() {
	level.assign(SIZE, -1);
	queue<int>q;
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		for (auto &there : adj[here]) {
			if (level[there.v] == -1 && there.cap > 0) {
				level[there.v] = level[here] + 1;
				q.push(there.v);
			}
		}
	}
	if (level[e] == -1)return  false;
	else return true;
}
int dfs(int v, int crtcap) {
	if (v == e)return crtcap;
	for (auto &nxt : adj[v]) {
		if (level[nxt.v] == level[v] + 1 && nxt.cap > 0) {
			int f = dfs(nxt.v, min(crtcap, nxt.cap));
			if (f > 0) {
				nxt.cap -= f;
				adj[nxt.v][nxt.rev].cap += f;
				return f;
			}
		}
	}
	return 0;
}
int n, m;
int main() {
	cin >> n >> m;
	int v1, v2;
	for(int i=0;i<m;i++){
		cin >> v1 >> v2;
		addedge(v1, v2, 1);
	}
	int ret = 0;
	while (bfs()) {
		while (true) {
			int flow = dfs(s, INF);
			if (flow == 0)break;
			ret += flow;
		}
	}
	cout << ret;




	return 0;
}