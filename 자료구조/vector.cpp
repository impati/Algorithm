//vector container을 사용해보자
#include<iostream>
#include<vector>
using namespace std;
int main() {
	//vector container의 멤버함수
	//생성자.
	vector<int> v;
	vector<int> v1(10);//할당
	vector<int> v2(10, 100);//할당,초기화
	//복사생성자
	vector<int>v3(v2);
	//멤버함수
	v.assign(10, 3);//할당과 초기화
	v.front();
	v.back();
	v.clear();
	v.push_back(10);
	v.pop_back();
	//반복자와
	vector <int>::iterator it;
	it=v.begin();//첫번째를 가르킴
	it=v.end();//아예마지막 다음.
	//크기
	v.size();
	//삽입.
	//효율이 좋지 못하다.
	v.insert(idx, value);//인덱스위치에 value값을 삽입.

	//삭제
	v.erase(it);//it이 가르키고있는 원소를제거
	//이외
	v.empty();

	return 0;
}
