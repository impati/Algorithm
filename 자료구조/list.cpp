//list container�� ����غ���
#include<iostream>
#include<list>
using namespace std;
int main() {
	//������
	list<int> link;
	list<int> link1(10);//10���� ���� ����
	list<int> link2(10, -1);//100���� ���Ҹ� -1������ ����
	//����Լ�
	link2.assign(5, 100);//100���� �ʱ�ȭ�� 5���� �����Ҵ� �ٽ� ������ �Ҵ��ϴ� �� ����.
	link.front();
	link.back();
	//�յ� ���� ���԰���.
	link.push_back(1);
	link.push_front(2);
	link.pop_back();
	link.pop_front();
	//���Ḯ��Ʈ�� �� ���� ����.
	list<int> ::iterator iter;
	int value;
	link.insert(iter, value);
	link.erase(iter);
	link.remove(value);
	//�̿�
	link.size();
	link.reverse();
	link.merge(link1);
	link.sort();//����Ʈ�� ��������.
	//��� �ִ�. 
	
	return 0;
}

