// ¹®Á¦ : https://www.acmicpc.net/problem/10451
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t< T; t++) {
		cin >> N;
		int v;
		vector<int> DFSE(N + 1);
		for (int u = 1; u <= N; u++) {
			cin >> v;
			DFSE[u] = v;
		}
		vector<int> S;
		vector<bool> DFScheck(N + 1);
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (DFScheck[i] == false) {
				DFScheck[i] = true;
				S.push_back(i);
				while (!S.empty()) {
					int v = S.back();
					if (DFScheck[DFSE[v]] == true) {
						cnt++;
						S.clear();
						break;
					}
					S.pop_back();
					S.push_back(DFSE[v]);
					DFScheck[DFSE[v]] = true;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}