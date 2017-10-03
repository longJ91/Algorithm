// 문제 : https://www.acmicpc.net/problem/2468
// 삼성 sw 대비
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int N, max_height, ans, temp;
int map[100][100];
bool check_map[100][100];
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int main() {
	cin >> N;
	max_height = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			max_height = max(map[i][j], max_height);
		}
	}
	ans = 0;
	for (int k = 0; k < max_height; k++) {
		memset(check_map, false, sizeof(check_map));
		temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > k && check_map[i][j] == false) {
					temp++;
					queue<pair<int, int> > safe;
					safe.push(make_pair(i, j));
					int safe_size = 1;
					check_map[i][j] = true;
					while (safe_size != 0) {
						pair<int, int> now = safe.front();
						safe.pop(); safe_size--;
						for (int m = 0; m < 4; m++) {
							int cx = now.first + move_x[m];
							int cy = now.second + move_y[m];
							if (cx >= 0 && cx < N && cy >= 0 && cy < N) {
								if (map[cx][cy] > k && check_map[cx][cy] == false) {
									safe.push(make_pair(cx, cy));
									safe_size++;
									check_map[cx][cy] = true;
								}
							}
						}
					}
				}
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
	return 1;
}