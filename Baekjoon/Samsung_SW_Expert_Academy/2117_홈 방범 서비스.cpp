#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int map[20][20];
bool check[20][20];
int move_x[4] = {0, 0, -1, 1};
int move_y[4] = {1, -1, 0, 0};
int test_case, N, M, result;
bool cost(const int K, const int H) {
	return ((K*K) + ((K - 1)*(K - 1))) <= (H * M);
}
int main() {
	cin.sync_with_stdio(false);
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memset(check, false, sizeof(check));
				queue<pair<int, int> > bfs;
				bfs.push(make_pair(i, j));
				check[i][j] = true;
				int k, house = 0, max_house = 0;
				k = 1;
				if (map[i][j] == 1) house = 1;
				if (cost(k, house)) max_house = max(max_house, house);
				while (!bfs.empty()) {
					k++;
					int len = bfs.size();
					for (int a = 0; a < len; a++) {
						pair<int, int> now = bfs.front(); bfs.pop();
						for (int m = 0; m < 4; m++) {
							int cx = now.first + move_x[m];
							int cy = now.second + move_y[m];
							if (cx < 0 || cx >= N || cy < 0 || cy >= N) continue;
							if (check[cx][cy]) continue;
							check[cx][cy] = true;
							bfs.push(make_pair(cx, cy));
							if (map[cx][cy] == 1) house++;
						}
					}
					if (cost(k, house)) {
						max_house = max(max_house, house);
					}
				}
				result = max(result, max_house);
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}