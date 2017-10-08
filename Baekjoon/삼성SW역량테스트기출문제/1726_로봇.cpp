// 문제 : https://www.acmicpc.net/problem/1726
// 삼성 sw 대비
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct robot {
	robot(int X, int Y, int D) {
		x = X;
		y = Y;
		d = D;
	}
	int x, y, d;
};
int M, N;
// 0 - 이동 가능, 1 - 이동 불가능
int map[100][100];
int cost[100][100][5];
int start_x, start_y, start_direction;
int end_x, end_y, end_direction;
int flag, ans;
int move_[3] = {1, 2, 3};
int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> start_x >> start_y >> start_direction;
	cin >> end_x >> end_y >> end_direction;
	start_x--;
	start_y--;
	end_x--;
	end_y--;
	memset(cost, -1, sizeof(cost));
	ans = 0;
	cost[start_x][start_y][start_direction] = 0;
	queue<robot> bfs;
	bfs.push(robot(start_x,start_y,start_direction));
	int bfs_size = 1;
	while (bfs_size != 0) {
		int x, y, d;
		x = bfs.front().x;
		y = bfs.front().y;
		d = bfs.front().d;
		bfs.pop(); bfs_size--;
		if (x == end_x && y == end_y && d == end_direction) {
			ans = cost[x][y][d];
			bfs_size = 0;
			break;
		}
		if (d == 1) {
			for (int m = 0; m < 3; m++) {
				int cy = y + move_[m];
				if (cy < N && map[x][cy] == 0 && cost[x][cy][d] == -1) {
					cost[x][cy][d] = cost[x][y][d] + 1;
					bfs.push(robot(x, cy, d)); bfs_size++;
				}
				if (cy < N && map[x][cy] == 1) break;
			}
			if (cost[x][y][3] == -1) {
				cost[x][y][3] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 3)); bfs_size++;
			}
			if (cost[x][y][4] == -1) {
				cost[x][y][4] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 4)); bfs_size++;
			}
		}
		else if (d == 2) {
			for (int m = 0; m < 3; m++) {
				int cy = y - move_[m];
				if (cy >= 0 && map[x][cy] == 0 && cost[x][cy][d] == -1) {
					cost[x][cy][d] = cost[x][y][d] + 1;
					bfs.push(robot(x, cy, d)); bfs_size++;
				}
				if (cy >= 0 && map[x][cy] == 1) break;
			}
			if (cost[x][y][3] == -1) {
				cost[x][y][3] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 3)); bfs_size++;
			}
			if (cost[x][y][4] == -1) {
				cost[x][y][4] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 4)); bfs_size++;
			}
		}
		else if (d == 3) {
			for (int m = 0; m < 3; m++) {
				int cx = x + move_[m];
				if (cx < M && map[cx][y] == 0 && cost[cx][y][d] == -1) {
					cost[cx][y][d] = cost[x][y][d] + 1;
					bfs.push(robot(cx, y, d)); bfs_size++;
				}
				if (cx < M && map[cx][y] == 1) break;
			}
			if (cost[x][y][1] == -1) {
				cost[x][y][1] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 1)); bfs_size++;
			}
			if (cost[x][y][2] == -1) {
				cost[x][y][2] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 2)); bfs_size++;
			}
		}
		else if (d == 4) {
			for (int m = 0; m < 3; m++) {
				int cx = x - move_[m];
				if (cx >= 0 && map[cx][y] == 0 && cost[cx][y][d] == -1) {
					cost[cx][y][d] = cost[x][y][d] + 1;
					bfs.push(robot(cx, y, d)); bfs_size++;
				}
				if (cx >= 0 && map[cx][y] == 1) break;
			}
			if (cost[x][y][1] == -1) {
				cost[x][y][1] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 1)); bfs_size++;
			}
			if (cost[x][y][2] == -1) {
				cost[x][y][2] = cost[x][y][d] + 1;
				bfs.push(robot(x, y, 2)); bfs_size++;
			}
		}
	}
	cout << ans << endl;
	return 1;
}