//****************graph theory************** //
#include<iostream>
#include<vector>
#define SIZE 101
using namespace std;

//�׷����� ���ͷ� ���� ������ ����,ǥ���� �� �ִ�.
//���͸� ���� �׷��� ������ C���� ���Ḯ��Ʈ�� ������ �Ͱ� ���� �ð��� ���⵵�� ������.
vector <int > gr[SIZE];
int main() {
	
	int v1, v2;
	cin >> v1 >> v2;
	//*******���� �׷���*******//
	//���� v1-> v2 �� ǥ��.

	gr[v1].push_back(v2);
	

	//******������ �׷���*******//

	gr[v1].push_back(v2);
	gr[v2].push_back(v1);


	// ��� �������� �ٸ� �������� ���� ������ ������ �������. == push_back�� ����ص� ������ ����.


	//****** ����ġ�� �ִ� ����׷���******//
	//W�� ����ġ
	int V1, V2, W;
	cin >> V1 >> V2 >> W;
	vector <pair<int, int> > Gr[SIZE];

	Gr[V1].push_back({ V2,W });


	//****** ����ġ�� �ִ� ������׷���******//

	Gr[V1].push_back({ V2,W });
	Gr[V2].push_back(make_pair(V1,W)); //make_pair�Լ��� ����ص��ȴ�.









	return 0;
}
