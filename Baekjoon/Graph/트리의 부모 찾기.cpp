// 문제 : https://www.acmicpc.net/problem/11725
// BFS로 탐색하면서 Queue에 추가 될 때 현재 정점이 부모. 왜냐하면 1을 루트(즉, 연결된 나머지 정점은 모두 자식)로 시작 하기 때문에
// 부모 정점이 무조건 먼저 Queue 들어와 부모와 자식 정점을 구별 가능
// endl 보다 "\n" 사용하기 endl은 강제로 버퍼를 비우기 때문에 속도가 저하됨
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100111;
bool check[MAX];
int parent[MAX];
vector<int> tree[MAX];
int main() {
	int N, start, end;
	cin >> N;
	for (int i = 0; i < N - 1 ; i++){
		cin >> start >> end;
		tree[start].push_back(end);
		tree[end].push_back(start);
	}
	queue<int> q;
	q.push(1);
	check[1] = true;
	int v, len, k, node;
	while (!q.empty()) {	
		v = q.front();
		q.pop();
		len = tree[v].size();
		for(k = 0; k < len;k++) {
			node = tree[v][k];
			if (check[node] == false) {
				check[node] = true;
				parent[node] = v;
				q.push(node);
			}
		}
	}
	for (int i = 2; i <= N; i++) cout << parent[i] << '\n';
	return 0;
}