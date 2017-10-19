// 문제 : https://www.acmicpc.net/problem/7569
// BFS를 활용한 문제
#include <iostream>
#include <queue>
using namespace std;
struct position {
	int h, n, m;
	position(const int H_, const int N_, const int M_) {
		h = H_;
		n = N_;
		m = M_;
	}
};
//왼쪽, 오른쪽, 앞, 뒤, 위, 아래
int move_h[6] = {0, 0, 0, 0, 1, -1};
int move_n[6] = {0, 0, 1, -1, 0, 0};
int move_m[6] = {-1, 1, 0, 0, 0, 0};
//H, N, M
int map[101][101][101];
int M, N, H;
int main() {
	cin.sync_with_stdio(false);
	cin >> M >> N >> H;
	int total = 0;
	queue<position> bfs;
	for (int h = 1; h <= H; h++) {
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				cin >> map[h][n][m];
				if (map[h][n][m] != -1) total++;
				if (map[h][n][m] == 1) bfs.push(position(h, n, m));
			}
		}
	}
	int time = 0, cnt = bfs.size();
	while (!bfs.empty()) {
		int len = bfs.size();
		time++;
		for (int i = 0; i < len; i++) {
			position temp = bfs.front();
			bfs.pop();
			for (int m = 0; m < 6; m++) {
				int ch = temp.h + move_h[m];
				int cn = temp.n + move_n[m];
				int cm = temp.m + move_m[m];
				if (ch < 1 || ch > H || cn < 1 || cn > N || cm < 1 || cm > M) continue;
				if (map[ch][cn][cm] == -1) continue;
				if (map[ch][cn][cm] == 0) {
					map[ch][cn][cm] = 1;
					bfs.push(position(ch, cn, cm));
					cnt++;
				}
			}
		}
	}
	time--;
	if (cnt != total) time = -1;
	cout << time << endl;
	return 0;
}