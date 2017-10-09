// 문제 : https://www.acmicpc.net/problem/2573
// 삼성 sw 대비 - bfs 응용
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int map[300][300];
int move_x[4] = { 1, -1, 0, 0 };
int move_y[4] = { 0, 0, 1, -1 };
vector<pair<int, int> > find_ice() {
	vector<pair<int, int> > set;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) set.push_back(make_pair(i, j));
		}
	}
	return set;
}
void remove_ice(const vector<pair<int, int> > set) {
	int temp_map[300][300], set_size = set.size();
	memset(temp_map, 0, sizeof(temp_map));
	for (int i = 0; i < set_size; i++) {
		int x = set[i].first;
		int y = set[i].second;
		for (int m = 0; m < 4; m++) {
			int cx = x + move_x[m];
			int cy = y + move_y[m];
			if (cx >= 0 && cx < N && cy >= 0 && cy < M) {
				if (map[cx][cy] == 0) temp_map[x][y] -= 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] += temp_map[i][j];
			if (map[i][j] < 0) map[i][j] = 0;
		}
	}
}
bool check_ice() {
	vector<pair<int, int> > set;
	set = find_ice();
	int set_size = set.size();
	if (set_size == 0) return false;
	bool check[300][300];
	memset(check, false, sizeof(check));
	queue<pair<int, int> > bfs;
	check[set[0].first][set[0].second] = true;
	bfs.push(set[0]);
	int cnt_ice = 1;
	while (!bfs.empty()) {
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();
		for (int m = 0; m < 4; m++) {
			int cx = x + move_x[m];
			int cy = y + move_y[m];
			if (cx >= 0 && cx < N && cy >= 0 && cy < M) {
				if (check[cx][cy] == false && map[cx][cy] > 0) {
					check[cx][cy] = true;
					bfs.push(make_pair(cx, cy));
					cnt_ice++;
				}
			}
		}
	}
	if (cnt_ice != set_size) return true;
	return false;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (true) {
		ans++;
		vector<pair<int, int> > ice_set;
		ice_set = find_ice();
		if (ice_set.size() == 0) {
			ans = 0;
			break;
		}
		remove_ice(ice_set);
		if (check_ice()) break;
	}
	cout << ans << endl;
	return 1;
}