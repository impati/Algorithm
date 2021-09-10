//****************topological sorting 1************** //

// 선후관계에 대한 정렬
//dfs순서상 역순이 위상정렬 순서가된다.
#include<iostream>
#define SIZE 100
#include<stack>
#include<vector>
using namespace std;
vector<int>adj[SIZE];
bool cycle = false;
stack<int>st;
vector<bool>visit(SIZE,false);
vector<bool>finish(SIZE, false);
void dfs(int v) {
	visit[v] = true;
	for (auto &nxt : adj[v]) {
		if (visit[nxt])continue;
		else if (finish[nxt]) {
			cycle = true; continue;
		}
		dfs(nxt);
	}
	finish[v] = true;
	st.push(v);
}
int main() {
	int n,m;
	cin >> n>>m;
	//순서정보입력받는다.
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		//v1이 v2보다 먼저 와야한다.
		adj[v1].push_back(v2);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i])dfs(i);
	}
	//위상정렬.
	if (cycle) {
		//cycle이 true라면 사이클이 형성되므로 위상정렬을 수행할 수 없다.
	}
	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}

	return 0;
}
