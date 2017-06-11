// ���� : https://www.acmicpc.net/problem/1707
// ������ Ž���ϸ鼭 �湮�� ������ A, B�� �����Ѵ�. ��, A or B�� ��� �Ѵٸ� ���� ������ ������ �ݴ��� B or A�� ��Ÿ�����Ѵ�.
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int K;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int V, E;
		cin >> V >> E;
		vector< queue<int> > DFSE(V + 1);
		for (int e = 1; e <= E; e++) {
			int u, v;
			cin >> u >> v;
			DFSE[u].push(v);
			DFSE[v].push(u);
		}
		//���� ����
		for (int i = 1; i <= V; i++) {
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
		//���� Ž��(DFS)
		stack<int> S;
		vector<int> DFScheck(V + 1);// 0-false, 1-A, 2-B
		bool result = true;
		for (int k = 1; k <= V; k++) {
			if (DFScheck[k] == 0) {
				S.push(k);
				DFScheck[k] = 1;
				//cout << k << " ";
				while (!S.empty()) {
					int v = S.top();
					int l = DFSE[v].size();
					bool flag = true;
					for (int i = 1; i <= l; i++) {
						if (DFScheck[DFSE[v].front()] == 0) {
							S.push(DFSE[v].front());
							DFScheck[v] == 1 ? DFScheck[DFSE[v].front()] = 2 : DFScheck[DFSE[v].front()] = 1;
							//cout << DFSE[v].front() << " ";
							DFSE[v].pop();
							flag = false;
							break;
						}
						if (DFScheck[v] == DFScheck[DFSE[v].front()] && DFScheck[v] != 0) result = false;
						DFSE[v].pop();
					}
					if (flag) S.pop();
				}
				//cout << endl;
			}
		}
		result == true ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}