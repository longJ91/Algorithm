#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M;
		cin >> N >> M;
		vector<int> world(N + 1, 0);
		vector< vector<int> > link(N + 1);
		int a, b, firstNode;
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			if (i == 0) firstNode = a;
			link[a].push_back(b);
			link[b].push_back(a);
		}
		queue<int> DFS;
		DFS.push(firstNode);
		world[firstNode] = 1;
		int A, flag = 1;
		while (!DFS.empty()) {
			A = DFS.front();
			DFS.pop();
			int len = link[A].size(), B;
			for (int i = 0; i < len; i++){
				B = link[A][i];
				if (world[B] == 0) {
					DFS.push(B);
					world[B] = -world[A];
				}
				else {
					if (world[B] == world[A]) {
						flag = -1;
						break;
					}
				}
			}
			if (flag == -1) break;
		}

		flag == 1 ? Answer = 1 : Answer = 0;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}