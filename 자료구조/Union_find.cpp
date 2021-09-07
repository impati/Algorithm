//****************union_find************** //

// path_compress 집합합치기.

#include<iostream>
#define SIZE 100
using namespace std;
struct UF {
	int parent[SIZE];
	int n;
	UF(int size):n(size) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int idx) {
		if (idx == parent[idx])return idx;
		else return parent[idx] = find(parent[idx]);
	}
	bool is_union_(int v1, int v2) {
		v1 = find(v1), v2 = find(v2);
		if (v1 == v2)return true;
		else return false;
	}
	void merge(int v1, int v2) {
		v1 = find(v1), v2 = find(v2);
		if (v1 < v2)parent[v2] = v2;
		else parent[v1] = v2;
	}
};
int main() {
	int n;//집합의 개수.
	UF u(n);
	if (!u.is_union_(3, 4)) {	//3,4가 같은 집합이 아니라면 합쳐준다
		u.merge(3, 4);
	}


	return 0;
}