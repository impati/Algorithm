//우선 순위 큐  구 현 
#include<iostream>
#include<vector>
#include<time.h>
#define SIZE 100
using namespace std;
 //최소 힙 
class priority_queue {
private:
	int arr[SIZE];
	int bottom; 
public:
	priority_queue():bottom(0), arr(){};
	bool empty() {
		if (bottom == 0)return true;
		else return false;
	}
	int top() {
		if (!empty())return arr[1];
		else return -1;
	}
	void push(int value) {
		if (bottom == 0) {
			arr[++bottom] = value;
		}
		else {
			int idx = ++bottom;;
			arr[bottom] = value;
			while (idx != 1 && arr[idx] < arr[idx / 2]) {
				int tmp = arr[idx];
				arr[idx] = arr[idx / 2];
				arr[idx / 2] = tmp;
				idx /= 2;
			}
		}
	}
	void pop() {
		if(!empty()){
			int idx = 1;
			arr[idx] = arr[bottom--];
			while ((idx * 2 <= bottom) && (arr[idx] > arr[idx * 2] || arr[idx] > arr[idx * 2 + 1])) {
				if (arr[idx * 2] < arr[idx * 2 + 1]) {
					int tmp = arr[idx * 2];
					arr[idx * 2] = arr[idx];
					arr[idx] = tmp;
					idx *= 2;
				}
				else {
					int tmp = arr[idx * 2 + 1];
					arr[idx * 2 + 1] = arr[idx];
					arr[idx] = tmp;
					idx = idx * 2 + 1;
				}
			}
		}
	}
};
int main() {
	priority_queue pq;
	int i;
	int n;
	srand(time(NULL));
	for (int i = 1; i <= 10; i++) {
		int n = rand() % 100 + 1;
		pq.push(n);
	}
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}
