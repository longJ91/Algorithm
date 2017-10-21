// 문제 : https://www.acmicpc.net/problem/2206
// 삼성 시험 보기 마지막 테스트 연습!!!
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct state {
	int x, y, s;
	state(const int X, const int Y, const int S) {
		x = X;
		y = Y;
		s = S;
	}
};
int map[1001][1001];
int check[2][1001][1001];
int move_x[4] = {0,0,-1,1};
int move_y[4] = {1,-1,0,0};
int N, M, result;
int main() {
	cin >> N >> M;
	string str;
	vector<pair<int, int> >  WALL;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}
	memset(check, -1, sizeof(check));
	queue<state> bfs;
	bfs.push(state(1,1,0));
	check[0][1][1] = 1;
	while (!bfs.empty()) {
		state now = bfs.front();
		bfs.pop();
		for (int m = 0; m < 4; m++) {
			int cx = now.x + move_x[m];
			int cy = now.y + move_y[m];
			if (cx < 1 || cx > N || cy < 1 || cy > M) continue;
			if (map[cx][cy] == 1) {
				if (now.s == 1) continue;
				if (check[1][cx][cy] == -1) {
					check[1][cx][cy] = check[0][now.x][now.y] + 1;
					bfs.push(state(cx, cy, 1));
				}
			}
			else {
				if (check[now.s][cx][cy] == -1) {
					check[now.s][cx][cy] = check[now.s][now.x][now.y] + 1;
					bfs.push(state(cx, cy, now.s));
				}
			}
		}
	}
	result = 987654321;
	if (check[0][N][M] != -1) result = min(result, check[0][N][M]);
	if (check[1][N][M] != -1) result = min(result, check[1][N][M]);
	if (result == 987654321) result = -1;
	cout << result << endl;
	return 0;
}