//vector만으로 충분히 스텍을 구현할 수 있다.
//#include<stack>에서 stack객체를 사용하면 된다.
//굳이 굳이 구현해보자!
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class stack {
private:
	vector<T> st;
	int TOP;
public:
	stack() :st(), TOP(0) {};
	stack(int n) :st(n), TOP(0) {};
	stack(int n, T value) :st(n,value), TOP(n) {};
	void push(T value);
	void pop();
	int size();
	bool empty();
	T top();
};
int main() {
	stack<int> s;
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}
	cout << s.size() << endl;
	while (!s.empty()) {
		int value = s.top();
		cout << value<< endl;
		s.pop();
	}
	return 0;
}
template<typename T>
void stack<T> :: push(T value) {
	st.push_back(value);
	TOP += 1;
}
template<typename T>
T stack<T> ::top() {
	T return_value= st[TOP-1];
	return return_value;
}
template<typename T>
void stack<T> ::pop() {
	st.pop_back();
	TOP -= 1;
}
template<typename T>
int stack<T>::size() {
	return TOP;
}
template<typename T>
bool stack<T> ::empty() {
	return TOP == 0 ? true : false;
}
