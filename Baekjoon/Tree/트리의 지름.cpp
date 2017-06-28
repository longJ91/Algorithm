// ���� : https://www.acmicpc.net/problem/1167
// BFS 2�� Ȱ��. ó�� root ��尡 ���� ���� �ʱ� ������ Ư�� ��带 ������� BFS�� 1�� �����ϰ� �������� ������ ��带 �������� �ٽ� �ѹ� BFS�� ����
#include <iostream> 
#include <queue>
#include <vector>
using namespace std;
vector< pair<int, int> > tree[100001];
int check[100001];
int checkLast[100001];
int main() {
	int n, b, e, c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		while (true) {
			cin >> e;
			if (e == -1) break;
			cin >> c;
			tree[b].push_back(make_pair(e, c));
		}
	}
	// BFS 1
	queue<int> q;
	q.push(1);
	check[1] = 0;
	int max = 0, index = 1;
	while (!q.empty()) {
		int begin = q.front(), len = tree[begin].size(), next, cost;
		for (int i = 0; i < len; i++){
			next = tree[begin].at(i).first;
			cost = tree[begin].at(i).second;
			if (check[next] == 0 && next != 1) {
				check[next] = check[begin] + cost;
				q.push(next);
			}
			if (check[next] > max) {
				max = check[next];
				index = next;
			}
		}
		q.pop();
	}
	// BFS 2
	q.push(index);
	checkLast[index] = 0;
	max = 0;
	while (!q.empty()) {
		int begin = q.front(), len = tree[begin].size(), next, cost;
		for (int i = 0; i < len; i++) {
			next = tree[begin].at(i).first;
			cost = tree[begin].at(i).second;
			if (checkLast[next] == 0 && next != index) {
				checkLast[next] = checkLast[begin] + cost;
				q.push(next);
			}
			if (checkLast[next] > max) max = checkLast[next];
		}
		q.pop();
	}
	cout << max << endl;
	return 0;
}