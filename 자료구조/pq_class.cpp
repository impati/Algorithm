#include<iostream>
#include<queue>
#include<time.h>
#define MOD 100
using namespace std;
struct triple {
	int x, y, z;
	triple(int v1, int v2, int v3) :x(v1), y(v2), z(v3) {  };
	bool operator < (const triple&ref)const {
		if (z == ref.z) {
			return y < ref.y;//  z�� ���� ���� ���� y���������� �ִ� ���� �����ϰڴ�
		}
		else {
			return z < ref.z;//�ִ� ��.
		}
	}
};
int main() {
	// �⺻���� �켱���� ť.
	priority_queue<int, vector<int>, less<int>>max_pq;
	priority_queue<int, vector<int>, greater<int>>min_pq;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int value = rand() % MOD + 1;
		max_pq.push(value);
		min_pq.push(value);
	}
	//max_pq
	while (!max_pq.empty()) {
		cout << max_pq.top() << endl;
		max_pq.pop();
	}
	//min_pq.
	while (!min_pq.empty()) {
		cout << min_pq.top() << endl;
		min_pq.pop();
	}
	cout << endl;

	//pair �� ���¿��� pq.
	//first���� ����.
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pair_pq;
	for (int i = 0; i < 10; i++) {
		pair<int, int>value(rand() % MOD + 1, rand() % MOD + 1);
		pair_pq.push(value);
	}
	while (!pair_pq.empty()) {
		cout << pair_pq.top().first<<" "<<pair_pq.top().second << endl;
		pair_pq.pop();
	}

	cout << endl;
	
	// 3-variance �̻󿡼� pq����ϱ�.!

	priority_queue<triple>pq; // == priority_queue<triple,vector<triple>, less<triple>>pq;  ������ �����ε��� ���ؼ� �ٲپ� �� ���� �ִ�.

	for (int i = 0; i < 10; i++) {
		triple value(rand() % MOD + 1, rand() % MOD + 1, rand() % MOD + 1);
		pq.push(value);
	}

	while (!pq.empty()) {
		cout << pq.top().x << " " << pq.top().y << " " << pq.top().z << endl;
		pq.pop();
	}

	return 0;
}