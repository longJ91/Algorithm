// 문제 : https://www.acmicpc.net/problem/2589
// 삼성 sw 대비
// 모든 육지(L)에서 BFS를 통해 구해진 각 육지간의 최소비용 중 최대를 출력
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int N, M;
char map[50][50];
int cost[50][50];
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int main() {
	cin >> N >> M;
	string str;
	vector<pair<int, int> > land_set;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
			if (str[j] == 'L') land_set.push_back(make_pair(i, j));
		}
	}
	int land_size = land_set.size();
	int ans = 0;
	for (int i = 0; i < land_size; i++) {
		memset(cost, -1, sizeof(cost));
		queue<pair<int, int> > bfs;
		bfs.push(land_set[i]);
		int bfs_size = 1, temp = -1, temp_ans = 0;
		while (bfs_size != 0) {
			temp++;
			int q_size = bfs.size();
			for (int q = 0; q < q_size; q++) {
				int x, y;
				x = bfs.front().first;
				y = bfs.front().second;
				bfs.pop(); bfs_size--;
				for (int m = 0; m < 4; m++) {
					int cx = x + move_x[m];
					int cy = y + move_y[m];
					if (cx >= 0 && cx < N && cy >= 0 && cy < M) {
						if (map[cx][cy] == 'L') {
							if (cost[cx][cy] == -1) {
								cost[cx][cy] = temp + 1;
								bfs.push(make_pair(cx, cy));
								bfs_size++;
							}
						}
					}
				}
				temp_ans = max(temp_ans, temp);
			}
		}
		ans = max(ans, temp_ans);
	}
	cout << ans << endl;
	return 1;
}