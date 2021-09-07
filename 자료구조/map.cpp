//map container을 사용해보자
// string클래스와 자주 사용된다//
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	map <string,int > s1;
	map<int, string> s2;

	//인덱스를 통한 접근 가능.
	// 객체[key]=value 생성(삽입)
	s1["impati"] = 3;
	//수정
	s1["impati"] = 1;

	//삭제. == 객체.erase(key)
	s1.erase("impati");

	//탐색.
	map<string, int> ::iterator it;
	for (it = s1.begin(); it != s1.end(); it++) {
		cout << it->first <<" "<<it->second<< endl;
	}
	//이외
	s1.clear();
	s1.empty();
	s1.size();
	
	
	//mutimap >> key 중복이 허용 ->인덱스를 통한 접근이 불가능하다.
	//때문에 원하는 key값과 value를 찾기위해서는 find()멤버함수 , lower_bound(key) , upper_bound(key)를 사용하자.
	//equal_range(key)은 pair<,>로 반환 key의 첫번째를 나타낸다.



	return 0;
}