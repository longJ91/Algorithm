#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;

struct TC {
	int t, c;
};

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, s, t, c;
		int firstNode;
		cin >> N >> M;
		//Á¤Á¡
		vector< vector<TC> > node(N + 1);
		for (int i = 0; i < M; i++){
			cin >> s >> t >> c;
			if (i == 0) firstNode = s;
			TC temp;
			temp.t = t;
			temp.c = c;
			node[s].push_back(temp);
			temp.t = s;
			node[t].push_back(temp);
		}
		vector<int> check;
		vector<bool> nodeCheck(N + 1, false);
		vector<int> result;
		check.push_back(firstNode);
		nodeCheck[firstNode] = true;
		int count = 0;
		while (count != N - 1) {
			int len = check.size();
			int minR = 1001, minNode;
			for (int i = 0; i < len; i++){
				int start = check[i], Alen = node[start].size();
				for (int i = 0; i < Alen; i++){
					int end = node[start][i].t, cost = node[start][i].c;
					if (nodeCheck[end] == false && cost < minR) {
						minR = cost;
						minNode = end;
					}
				}
			}
			check.push_back(minNode);
			nodeCheck[minNode] = true;
			result.push_back(minR);
			count++;
		}
		sort(result.begin(), result.end());
		N == 2 ? Answer = result[0] : Answer = result[(N / 2) - 1];
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}