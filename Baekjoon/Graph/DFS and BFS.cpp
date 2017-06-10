// 문제 : https://www.acmicpc.net/problem/1260
// Graph, DFS - Stack 활용, BFS - Queue 활용, sort도 해줘야함, 단 이거 완벽하지않음 문제점 못찾음. 백준 모범답 참고하고 재귀 사용도 고려
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N, M, V;
	cin >> N >> M >> V;
	int node, edge;
	vector< queue<int> > DFSE(N + 1);
	vector< queue<int> > BFSE(N + 1);
	for (int i = 1; i <= M; i++) {
		cin >> node >> edge;
		DFSE[node].push(edge);
		BFSE[node].push(edge);
	}
	for (int i = 1; i <= N; i++) {
		vector<int> temp;
		while (!DFSE[i].empty()) {
			temp.push_back(DFSE[i].front());
			DFSE[i].pop();
		}
		sort(temp.begin(), temp.end());
		int l = temp.size();
		for (int j = 0; j < l; j++) DFSE[i].push(temp.at(j));
		temp.clear();

		while (!BFSE[i].empty()) {
			temp.push_back(BFSE[i].front());
			BFSE[i].pop();
		}
		sort(temp.begin(), temp.end());
		l = temp.size();
		for (int j = 0; j < l; j++) BFSE[i].push(temp.at(j));
		temp.clear();
	}
	//DFS
	stack<int> S;
	vector<bool> DFScheck(N + 1);
	S.push(V);
	DFScheck[V] = true;
	cout << V << " ";
	while (!S.empty()) {
		int v = S.top();
		int l = DFSE[v].size();
		bool flag = true;
		for (int i = 1; i <= l; i++) {
			if (DFScheck[DFSE[v].front()] == false) {
				S.push(DFSE[v].front());
				DFScheck[DFSE[v].front()] = true;
				cout << DFSE[v].front() << " ";
				DFSE[v].pop();
				flag = false;
				break;
			}
		}
		if (flag) S.pop();
	}
	cout << endl;
	//BFS
	queue<int> Q;
	vector<bool> BFScheck(N + 1);
	Q.push(V);
	BFScheck[V] = true;
	cout << V << " ";
	while (!Q.empty()) {
		int v = Q.front();
		int l = BFSE[v].size();
		Q.pop();
		for (int i = 1; i <= l; i++) {
			if (BFScheck[BFSE[v].front()] == false) {
				Q.push(BFSE[v].front());
				BFScheck[BFSE[v].front()] = true;
				cout << BFSE[v].front() << " ";
			}
			BFSE[v].pop();
		}	
	}
	cout << endl;
	return 0;
}