// 문제 : https://www.acmicpc.net/problem/2665
// 삼성 sw 대비 - bfs
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n;
//0 - 검은방, 1 - 흰방
int map[50][50];
int cost[50][50];
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };
int main() {
	memset(cost, -1, sizeof(cost));
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	queue<pair<int, int> > bfs;
	int bfs_size = 1;
	bfs.push(make_pair(0, 0));
	cost[0][0] = 0;
	while (bfs_size != 0) {
		pair<int, int> now = bfs.front();
		bfs.pop(); bfs_size--;
		for (int m = 0; m < 4; m++) {
			int cx = now.first + move_x[m];
			int cy = now.second + move_y[m];
			if (cx >= 0 && cx < n && cy >= 0 && cy < n) {
				if (cost[cx][cy] == -1) {
					cost[cx][cy] = cost[now.first][now.second];
					bfs.push(make_pair(cx, cy));
					bfs_size++;
					if (map[cx][cy] == 0) cost[cx][cy]++;
				}
				else {
					if (map[cx][cy] == 0) {
						if (cost[cx][cy] > cost[now.first][now.second] + 1) {
							cost[cx][cy] = cost[now.first][now.second] + 1;
							bfs.push(make_pair(cx, cy));
							bfs_size++;
						}
					}
					else {
						if (cost[cx][cy] > cost[now.first][now.second]) {
							cost[cx][cy] = cost[now.first][now.second];
							bfs.push(make_pair(cx, cy));
							bfs_size++;
						}
					}
				}
			}
		}
	}
	cout << cost[n - 1][n - 1] << endl;
	return 1;
}