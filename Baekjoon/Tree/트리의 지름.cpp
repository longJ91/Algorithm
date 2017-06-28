// 문제 : https://www.acmicpc.net/problem/1167
// BFS 2번 활용. 처음 root 노드가 존재 하지 않기 때문에 특정 노드를 기반으로 BFS를 1번 진행하고 마지막에 도달한 노드를 바탕으로 다시 한번 BFS를 진행
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