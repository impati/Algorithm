//****************MST************** //
#include<queue>
#include<iostream>
#include<algorithm>
#define SIZE 101 //������ ����.
using namespace std;

//�ּ� ���д� Ʈ�� MST �˰��� ���� �˾ƺ���.
//�ּ� ���д� Ʈ���� �׷������� ���� ���� ������� ��� ������ �����ϴ� �˰����̴�.
// ũ�罺Į �˰���.
// 1.���� ����ġ�� ���� �������� �������ش�.
// 2.������ ���� ����Ǵ� �� ������ �̹� ������ �Ǿ� �ִٸ� �������� �ʴ´�.
// 3.���������� (������ ����-1)���� ������ �߰��ϸ� �˰����� �����Ѵ�.
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
		cin >> v1 >> v2 >> w;//��������
		pq.push({ v1,v2,w });
	}
	UF connect(SIZE);
	int count = 0;//����� ������Ʈ
	int value = 0;//�ּ� ����ġ�� �׷�������� ��.
	while (!pq.empty()) {
		graph here = pq.top();
		pq.pop();
		if (!connect.is_union_(here.v1, here.v2)) {
			connect.union_(here.v1, here.v2);
			value += here.w;
		}
		if (count == SIZE - 1)break;
	}
	cout << value; // �ּҺ���� ���д�Ʈ��.
	return 0;
}