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
			return y < ref.y;//  z가 같은 값일 때는 y기준으로의 최대 힙을 구성하겠다
		}
		else {
			return z < ref.z;//최대 힙.
		}
	}
};
int main() {
	// 기본적인 우선순위 큐.
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

	//pair 한 상태에서 pq.
	//first기준 정렬.
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
	
	// 3-variance 이상에서 pq사용하기.!

	priority_queue<triple>pq; // == priority_queue<triple,vector<triple>, less<triple>>pq;  연산자 오버로딩을 통해서 바꾸어 볼 수도 있다.

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