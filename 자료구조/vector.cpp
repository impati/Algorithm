//vector container�� ����غ���
#include<iostream>
#include<vector>
using namespace std;
int main() {
	//vector container�� ����Լ�
	//������.
	vector<int> v;
	vector<int> v1(10);//�Ҵ�
	vector<int> v2(10, 100);//�Ҵ�,�ʱ�ȭ
	//���������
	vector<int>v3(v2);
	//����Լ�
	v.assign(10, 3);//�Ҵ�� �ʱ�ȭ
	v.front();
	v.back();
	v.clear();
	v.push_back(10);
	v.pop_back();
	//�ݺ��ڿ�
	vector <int>::iterator it;
	it=v.begin();//ù��°�� ����Ŵ
	it=v.end();//�ƿ������� ����.
	//ũ��
	v.size();
	//����.
	//ȿ���� ���� ���ϴ�.
	v.insert(idx, value);//�ε�����ġ�� value���� ����.

	//����
	v.erase(it);//it�� ����Ű���ִ� ���Ҹ�����
	//�̿�
	v.empty();

	return 0;
}
