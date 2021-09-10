//****************topological sorting 1************** //

// ���İ��迡 ���� ����
//dfs������ ������ �������� �������ȴ�.
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
		if (!finish[nxt]) {
			cycle = true; continue;
		}
		dfs(nxt);
	}
	finish[v] = true;
	st.push(v);
}
int main() {
	int n;
	cin >> n;
	//���������Է¹޴´�.
	for (int i = 0; i < n; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		//v1�� v2���� ���� �;��Ѵ�.
		adj[v1].push_back(v2);
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i])dfs(i);
	}
	//��������.
	if (cycle) {
		//cycle�� true��� ����Ŭ�� �����ǹǷ� ���������� ������ �� ����.
	}
	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}

	return 0;
}