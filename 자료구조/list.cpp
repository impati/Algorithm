//list container을 사용해보자
#include<iostream>
#include<list>
using namespace std;
int main() {
	//생성자
	list<int> link;
	list<int> link1(10);//10개의 원소 생성
	list<int> link2(10, -1);//100개의 원소를 -1값으로 생성
	//멤버함수
	link2.assign(5, 100);//100으로 초기화된 5개의 원소할당 다시 공간을 할당하는 것 같다.
	link.front();
	link.back();
	//앞뒤 삭제 삽입가능.
	link.push_back(1);
	link.push_front(2);
	link.pop_back();
	link.pop_front();
	//연결리스트의 꽃 삭제 삽입.
	list<int> ::iterator iter;
	int value;
	link.insert(iter, value);
	link.erase(iter);
	link.remove(value);
	//이외
	link.size();
	link.reverse();
	link.merge(link1);
	link.sort();//디폴트는 오름차순.
	//등등 있다. 
	
	return 0;
}

