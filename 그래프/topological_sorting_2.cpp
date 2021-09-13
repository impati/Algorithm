//****************topological sorting 2************** //

// ���İ��迡 ���� ����
// 1.���������� 0�� ������ ť���ְ� 
// 2 ���鼭 ���������� �ٿ��ش�.
// 3.1-2���� �ݺ��Ѵ�.
// ť���� �A ������ ��ü ���� ������ ������ ���������� ������ �� ����.
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#define SIZE 100
using namespace std;
vector<int>adj[SIZE];
vector<int>in(SIZE, 0);//��������
queue<int>q;
int main() {
	int n, m;
	cin >> n >> m;
	//���������Է¹޴´�.
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		in[v2] += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)q.push(i);//���������� 0�� ������ ť�� �ִ´�.
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