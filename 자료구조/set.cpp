//set container�� ����غ���
// stringŬ������ ���� ���ȴ�//
#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	int value;
	set<int> s;
	//��������Ʈ���� �̷���� �ߺ��� �ȵǴ� value���� ����.
	//������������ ����. �ð����⵵�� �����ϳ� ã�µ� O(logn)
	
	//ã��
	s.find(value); //set�� value�� �ִٸ� �ݺ��ڸ� ��ȯ������ ���ٸ� end()�� ��ȯ.
	
	//����,����
	s.insert(value);
	s.erase(value);
	//�⺻
	s.begin();
	s.end();
	s.clear();
	s.size();
	s.empty();

	//Ư���� �ߺ��� �������� ���� �ڷᱸ����� �� �ִ�.
	//�̿� ����� ����Ʈ�� ���� �ʰ��� �ڷᱸ���� �� ���� �����ϰ� ��ü �����ϴ�.

	string str;
	multiset<string>ms;
	//set�� �⺻���� ����� �Ȱ���.. �ߺ��� ����ȴٴ������� �ٸ���.

	//�ߺ��� ������� �ǹ̰� ���ܹ��� ����Լ�

	multiset<string> ::iterator it1,it2;
	
	it1 = ms.upper_bound(str);//str�� ���������� ������ ������ġ�� ��ȯ.
	it2 = ms.lower_bound(str); // str�� ó�������� ��ġ�� ��ȯ
	//it1~it2 �� equal ����.

	ms.count(str);//ms�� str�� ��ִ�.




	return 0;
}
