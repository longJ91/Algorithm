//다익스트라 & DFS 응용
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int Answer;
struct EC {
	int end, cost;
};
bool SORT(const pair<int,int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K, P;
		cin >> N >> M >> K;
		int s, e, c;
		vector < vector<EC> > node(N + 1);
		for (int i = 0; i < M; i++){
			//scanf("%d %d %d",s,e,c);
			cin >> s >> e >> c;
			EC temp;
			temp.end = e;
			temp.cost = c;
			node[s].push_back(temp);
			temp.end = s;
			node[e].push_back(temp);
		}
		cin >> P;
		vector < pair<int, int> > trval;
		for (int i = 0; i < P; i++){
			//scanf("%d %d", s, e);
			cin >> s >> e;
			int temp;
			if (s > e) {
				temp = s;
				s = e;
				e = temp;
			}
			trval.push_back(make_pair(s, e));
		}
		sort(trval.begin(), trval.end(), SORT);
		
		int flag = -1, len = trval.size();
		int S, E;
		int R = 0;
		
		for (int i = 0; i < len; i++){
			vector<int> minCost(N + 1, -1);
			if (flag == -1) {
				S = trval[i].first;
				minCost[S] = 0;
				queue<int> DFS;
				DFS.push(S);
				while (!DFS.empty()) {
					S = DFS.front();
					DFS.pop();
					int minLen = node[S].size();
					for (int j = 0; j < minLen; j++){
						E = node[S][j].end;
						int minC = node[S][j].cost;
						if (minCost[E] == -1) {
							minCost[E] = minCost[S] + minC;
							DFS.push(E);
						}
						else if ((minCost[E] > minCost[S] + minC)) {
							minCost[E] = minCost[S] + minC;
						}
					}
				}
				flag = 1;
			}

			//k값 비교
			while (i<len) {
				E = trval[i].second;
				if (minCost[E] > K) {
					R++;
				}
				if (i + 1 < len && trval[i + 1].first == trval[i].first) {
					i++;
				}
				else {
					flag = -1;
					break;
				}
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << R << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}