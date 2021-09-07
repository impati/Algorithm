//****************graph theory************** //
#include<iostream>
#include<vector>
#define SIZE 101
using namespace std;

//그래프는 벡터로 아주 간단히 구현,표현할 수 있다.
//벡터를 통한 그래프 구현은 C언어에서 연결리스트로 구현한 것과 같은 시공간 복잡도를 가진다.
vector <int > gr[SIZE];
int main() {
	
	int v1, v2;
	cin >> v1 >> v2;
	//*******방향 그래프*******//
	//정점 v1-> v2 을 표현.

	gr[v1].push_back(v2);
	

	//******무방향 그래프*******//

	gr[v1].push_back(v2);
	gr[v2].push_back(v1);


	// 어느 정점에서 다른 정점으로 가는 간선의 순서는 상관없다. == push_back을 사용해도 문제가 없다.


	//****** 가중치가 있는 방향그래프******//
	//W는 가중치
	int V1, V2, W;
	cin >> V1 >> V2 >> W;
	vector <pair<int, int> > Gr[SIZE];

	Gr[V1].push_back({ V2,W });


	//****** 가중치가 있는 무방향그래프******//

	Gr[V1].push_back({ V2,W });
	Gr[V2].push_back(make_pair(V1,W)); //make_pair함수를 사용해도된다.









	return 0;
}
