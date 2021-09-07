//set container을 사용해보자
// string클래스와 자주 사용된다//
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	int value;
	set<int> s;
	//균형이진트리로 이루어진 중복이 안되는 value들의 집합.
	//오름차순으로 정렬. 시간복잡도는 원소하나 찾는데 O(logn)
	
	//찾기
	s.find(value); //set에 value가 있다면 반복자를 반환하지만 없다면 end()를 반환.
	
	//삽입,삭제
	s.insert(value);
	s.erase(value);
	//기본
	s.begin();
	s.end();
	s.clear();
	s.size();
	s.empty();

	//특성상 중복을 가려내기 좋은 자료구조라고볼 수 있다.
	//이외 기능은 리스트나 벡터 맵같은 자료구조로 더 쉽고 간편하게 대체 가능하다.

	string str;
	multiset<string>ms;
	//set과 기본적인 기능이 똑같다.. 중복이 허락된다는점에서 다르다.

	//중복의 허락으로 의미가 생겨버린 멤버함수

	multiset<string> ::iterator it1,it2;
	
	it1 = ms.upper_bound(str);//str이 마지막으로 나오는 다음위치를 반환.
	it2 = ms.lower_bound(str); // str이 처음나오는 위치를 반환
	//it1~it2 가 equal 구간.

	ms.count(str);//ms에 str이 몇개있니.




	return 0;
}
