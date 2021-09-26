//*bipartite_matching*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define SIZE 111
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m;	
vector<int>adj[SIZE];
vector<int>atob(SIZE, -1);
vector<int>btoa(SIZE, -1);
bool dfs(int v, vector<bool>&visited) {
	if (visited[v])return false;
	visited[v] = true;
	for (auto &nxt : adj[v]) {
		if (btoa[nxt] == -1 || dfs(btoa[nxt], visited)) {
			atob[v] = nxt;
			btoa[nxt] = v;
			return true;
		}
	}
	return false;

}
int main(){
	cin >> n >> m;
	//연결정보.
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		adj[i].push_back(v);
	}
	//이분매칭
	int count = 0;
	for (int i = 1; i <= n; i++) {
		vector<bool>visited(SIZE, false);
		if (dfs(i, visited))count++;
	}
	//최대매칭수
	cout << count;


	

	

	return 0;
}