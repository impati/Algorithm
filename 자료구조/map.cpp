//map container�� ����غ���
// stringŬ������ ���� ���ȴ�//
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	map <string,int > s1;
	map<int, string> s2;

	//�ε����� ���� ���� ����.
	// ��ü[key]=value ����(����)
	s1["impati"] = 3;
	//����
	s1["impati"] = 1;

	//����. == ��ü.erase(key)
	s1.erase("impati");

	//Ž��.
	map<string, int> ::iterator it;
	for (it = s1.begin(); it != s1.end(); it++) {
		cout << it->first <<" "<<it->second<< endl;
	}
	//�̿�
	s1.clear();
	s1.empty();
	s1.size();
	
	
	//mutimap >> key �ߺ��� ��� ->�ε����� ���� ������ �Ұ����ϴ�.
	//������ ���ϴ� key���� value�� ã�����ؼ��� find()����Լ� , lower_bound(key) , upper_bound(key)�� �������.
	//equal_range(key)�� pair<,>�� ��ȯ key�� ù��°�� ��Ÿ����.



	return 0;
}