#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#define SIZE 211
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct edge {
	int v, cap, rev, cost;
	edge(int v, int cap, int rev, int cost) :v(v), cap(cap), rev(rev), cost(cost) {};
};
struct state {
	int v, nxt, rev, cost;
};
vector<edge>adj[SIZE];
void addedge(int s, int e, int cap, int cost) {
	adj[s].push_back({ e,cap,(int)adj[e].size(),cost });
	adj[e].push_back({ s,0,(int)adj[s].size() - 1,-cost });
}
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	//조건에 맞게 모델링.
	int v1, v2, w;
	int s = 0, e = n + 1;
	addedge(s, 1, 2, 0);
	addedge(1, s, 2, 0);
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		addedge(v1, v2, 1, w);
		addedge(v2, v1, 1, w);
	}
	addedge(n, e, 2, 0);
	addedge(e, n, 2, 0);
	int total_cost = 0;
	while (true) {
		queue<int>q;
		vector<int>dist(SIZE, INF);
		vector<bool>inq(SIZE, false);
		vector<state>parent(SIZE, { 0,0,0,0 });
		dist[s] = 0; inq[s] = true; q.push(s);
		while (!q.empty()) {
			int here = q.front(); q.pop();
			inq[here] = false;
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].v;
				int cost = adj[here][i].cost;
				int cap = adj[here][i].cap;
				int rev = adj[here][i].rev;
				if (cap > 0) {
					if (dist[there] > dist[here] + cost) {
						dist[there] = dist[here] + cost;
						parent[there].v = here;
						parent[there].cost = cost;
						parent[there].rev = rev;//there->here 몇번째
						parent[there].nxt = i;//here->there 몇번째
						if (!inq[there]) {
							inq[there] = true;
							q.push(there);
						}
					}
				}
			}
			if (parent[e].v == 0)break;
			int flow = INF;
			for (int i = e; i != s; i = parent[i].v) {
				flow = min(flow, adj[parent[i].v][parent[i].nxt].cap);
			}
			for (int i = e; i != s; i = parent[i].v) {
				total_cost += parent[i].cost * flow;
				adj[parent[i].v][parent[i].nxt].cap -= flow;
				adj[i][parent[i].rev].cap += flow;
			}
		}
	}
	cout << total_cost;


	return 0;
}
