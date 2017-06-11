// ¹®Á¦ : https://www.acmicpc.net/problem/11724
// 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int u, v;
	vector< queue<int> > DFSE(N + 1);
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		DFSE[u].push(v);
		DFSE[v].push(u);
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
	}
	//DFS
	stack<int> S;
	vector<bool> DFScheck(N + 1);
	int cnt = 0;
	for (int k = 1; k <= N; k++) {
		if (DFScheck[k] == false) {
			S.push(k);
			DFScheck[k] = true;
			//cout << k << " ";
			while (!S.empty()) {
				int v = S.top();
				int l = DFSE[v].size();
				bool flag = true;
				for (int i = 1; i <= l; i++) {
					if (DFScheck[DFSE[v].front()] == false) {
						S.push(DFSE[v].front());
						DFScheck[DFSE[v].front()] = true;
						//cout << DFSE[v].front() << " ";
						DFSE[v].pop();
						flag = false;
						break;
					}
					DFSE[v].pop();
				}
				if (flag) S.pop();
			}
			//cout << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}