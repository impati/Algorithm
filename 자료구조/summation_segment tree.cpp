//bottom-up 세그먼트 트리
// 선형자료에 대해 구간합,구간곱,구간최대 구간 최소등을 logN 만에 구할 수 있다. 
#include<iostream>
#include<vector>
#define SIZE 101
using namespace std;
class summation_seg {
private:
	int N;
	int tree[2 * SIZE];
public:
	summation_seg(int n, int arr[]) : N(n) {
		for (int i = 1; i <= N; i++) {
			tree[i + N] = arr[i];
		}
		for (int i = N - 1; i >= 1; i--) {
			tree[i] = tree[i << 1] + tree[(i << 1) ^ 1];
		}
	}
	void update(int idx, int value) {
		for (tree[idx += N] = value; idx >= 1; idx >>= 1) {
			tree[idx >> 1] = tree[idx] + tree[idx ^ 1];
		}
	}
	int query(int left, int right) {
		int return_value = 0;
		left += N, right += N;
		while (left <= right) {
			if (left & 1) {
				return_value += tree[left];
				left += 1;
			}
			if (!(right & 1)) {
				return_value += tree[right];
				right -= 1;
			}
			left >>= 1, right >>= 1;
		}
		return return_value;
	}
};

int main() {
	int n;
	int arr[SIZE];
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		arr[i] = i + 1;
	}
	summation_seg s(n, arr);//생성자를 통한 초기화

	cout<<s.query(1, n)<<endl;

	s.update(3, 11);
	cout << s.query(1, n);


	return 0;
}
