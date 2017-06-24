// ���� : https://www.acmicpc.net/problem/11725
// BFS�� Ž���ϸ鼭 Queue�� �߰� �� �� ���� ������ �θ�. �ֳ��ϸ� 1�� ��Ʈ(��, ����� ������ ������ ��� �ڽ�)�� ���� �ϱ� ������
// �θ� ������ ������ ���� Queue ���� �θ�� �ڽ� ������ ���� ����
// endl ���� "\n" ����ϱ� endl�� ������ ���۸� ���� ������ �ӵ��� ���ϵ�
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