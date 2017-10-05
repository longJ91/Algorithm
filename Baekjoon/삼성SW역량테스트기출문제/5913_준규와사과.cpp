// 문제 : https://www.acmicpc.net/problem/5913
// DFS (5,5) 까지 가는 모든 경우의 수
// 단, (5,5) 도착 했을때 사과나무 지역 모두 방문 해야함
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int K, total, ans;
int map[6][6];
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };
void dfs(const int i, const int j, const int cnt) {
	if (i == 5 && j == 5) {
		if (cnt == total) {
			ans++;
			return;
		}
	}
	else {
		for (int m = 0; m < 4; m++) {
			int cx = i + move_x[m];
			int cy = j + move_y[m];
			if (cx >= 1 && cx <= 5 && cy >= 1 && cy <= 5) {
				if (map[cx][cy] == 0) {
					map[cx][cy] = -1;
					dfs(cx, cy, cnt + 1);
					map[cx][cy] = 0;
				}
			}
		}
	}
}
int main() {
	memset(map, 0, sizeof(map));
	cin >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		map[x][y] = -1;
	}
	ans = 0;
	total = 25 - K;
	map[1][1] = -1;
	dfs(1,1,1);
	cout << ans << endl;
	return 1;
}