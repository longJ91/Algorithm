// 문제 : https://www.acmicpc.net/problem/1967
// BFS 2번 활용해서 트리의 지름 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int, int> > tree[10001];
int preCheck[10001];
int postCheck[10001];
int main() {
	int n, s, e, c;
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> s >> e >> c;
		tree[s].push_back(make_pair(e, c));
		tree[e].push_back(make_pair(s, c));
	}
	//BFS 1
	queue<int> q;
	q.push(1);
	preCheck[1] = 0;
	int max = 0, index = 1;
	while (!q.empty()) {
		int begin = q.front(), len = tree[begin].size();
		for (int i = 0; i < len; i++){
			int end = tree[begin].at(i).first, cost = tree[begin].at(i).second;
			if (preCheck[end] == 0 && end != 1) {
				preCheck[end] = preCheck[begin] + cost;
				q.push(end);
			}
			if (preCheck[end] > max) {
				max = preCheck[end];
				index = end;
			}
		}
		q.pop();
	}
	//BFS 2
	q.push(index);
	postCheck[index] = 0;
	max = 0;
	while (!q.empty()) {
		int begin = q.front(), len = tree[begin].size();
		for (int i = 0; i < len; i++) {
			int end = tree[begin].at(i).first, cost = tree[begin].at(i).second;
			if (postCheck[end] == 0 && end != index) {
				postCheck[end] = postCheck[begin] + cost;
				q.push(end);
			}
			if (postCheck[end] > max) max = postCheck[end];
		}
		q.pop();
	}
	cout << max << endl;
	return 0;
}