#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map[8][8];
int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {1, -1, 0, 0};
int test_case, N, K;
int main() {
	cin.sync_with_stdio(false);
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		cin >> N >> K;
		int max_h = 0, result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				max_h = max(max_h,map[i][j]);
			}
		}
		vector<pair<int, int> > max_pos;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_h) max_pos.push_back(make_pair(i,j));
			}
		}
		for (int k = 1; k <= K; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int temp_map[8][8];
					memcpy(temp_map, map, sizeof(map));
					temp_map[i][j] -= k;
					for (int a = 0; a < max_pos.size(); a++) {
						if (max_pos[a].first == i && max_pos[a].second == j) continue;
						int check[8][8];
						memset(check, -1, sizeof(check));
						queue< pair<int,int> > bfs;
						bfs.push(max_pos[a]);
						check[max_pos[a].first][max_pos[a].second] = true;
						int len = 1;
						while (!bfs.empty()) {
							len++;
							int bfs_size = bfs.size();
							for (int q = 0; q < bfs_size; q++) {
								pair<int, int> prev = bfs.front(); bfs.pop();
								for (int m = 0; m < 4; m++) {
									int cx = prev.first + move_x[m];
									int cy = prev.second+ move_y[m];
									if (cx < 0 || cx >= N || cy < 0 || cy >= N) continue;
									if (temp_map[cx][cy] < temp_map[prev.first][prev.second]) {
										if (check[cx][cy] >= len) continue;
										check[cx][cy] = len;
										bfs.push(make_pair(cx, cy));
										result = max(result, len);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}