//****************lazy propaganda segmentation tree************ //
#include<iostream>
#include<time.h>
#define SIZE 101
using namespace std;

// ������ Ʈ�� + [left,right]������ value�ξ�����Ʈ   
class seg {
private:
	int tree[4 * SIZE], lazy[4 * SIZE];
	int N;
public:
	seg(int n) : N(n) ,lazy(){};
	int init(int arr[],int node, int start, int end) {
		if (start == end)return tree[node] = arr[start];
		else {
			int pit = (start + end) / 2;
			return tree[node] = init(arr,node * 2, start, pit) + init(arr,node * 2 + 1, pit + 1, end);
		}
	}
	void propaganda(int node, int start, int end) {
		if (lazy[node]) {
			tree[node] += (end - start + 1)*lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
				
			}
			lazy[node] = 0;
		}
	}
	void update(int node, int start, int end, int left,int right, int value) {
		propaganda(node, start, end);
		if (left > end || start > right) {
			return;
		}
		else if (left <= start && end <= right) {
			tree[node] += (end - start + 1)*value;
			if (start != end) {
				if (start != end) {
					lazy[node * 2] += value;
					lazy[node * 2 + 1] += value;
				}
			}
		}
		else {
			int pit = (start + end) / 2;
			update(node * 2, start, pit, left, right, value);
			update(node * 2 + 1, pit + 1, end, left,right, value);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
	int query(int node, int start, int end, int left, int right) {
		propaganda(node, start, end);
		if (left > end || start > right) {
			return 0;
		}
		else if (left <= start && end <= right) {
			return tree[node];
		}
		int pit = (start + end) / 2;
		return query(node * 2, start, pit, left, right) + query(node * 2 + 1, pit + 1, end, left, right);
	}

};
int main() {
	int arr[SIZE];
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 101 + 1;
	}
	seg s(SIZE);
	s.init(arr, 1, 1, SIZE);

	//[1,30]������ ���
	cout << s.query(1, 1, SIZE, 1, 30) << endl;

	// [1,30]������ ��� ���� 10�� ����
	s.update(1, 1, SIZE, 1, 30, 10);
	//[1,30]������ ���
	cout << s.query(1, 1, SIZE, 1, 30) << endl;


	//�����ڷῡ ���� ������Ʈ ó���� ������ ������ �� �ִ�.



	return 0;
}
