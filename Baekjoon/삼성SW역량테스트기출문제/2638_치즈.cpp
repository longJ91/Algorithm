// 문제 : https://www.acmicpc.net/problem/2638
// 삼성 sw 대비
/* 
(0,0)에서 bfs 시작
빈공간이면 1, 치즈면 +1 더해주기
전체 맵을 보며 cost가 1 보다 커진 부분을 빈공간 1로 변경
반복 - 전체 맵 체크할때, 1 보다 큰 부분이 한군데도 없을때 종료
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int map[100][100];
int cost[100][100];
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0, flag = 1;
	while (true) {
		queue< pair<int, int> > bfs;
		bfs.push(make_pair(0, 0));
		int bfs_size = 1;
		memset(cost, -1, sizeof(cost));
		while (bfs_size != 0) {
			int i, j;
			i = bfs.front().first;
			j = bfs.front().second;
			bfs.pop(); bfs_size--;
			for (int m = 0; m < 4; m++) {
				int cx = i + move_x[m];
				int cy = j + move_y[m];
				if (cx >= 0 && cx < N && cy >= 0 && cy < M) {
					if (map[cx][cy] == 0) {
						if (cost[cx][cy] == -1) {
							cost[cx][cy] = 1;
							bfs.push(make_pair(cx, cy));
							bfs_size++;
						}
					}
					else {
						if (cost[cx][cy] == -1) cost[cx][cy] = 1;
						else cost[cx][cy]++;
					}
				}
			}
		}
		flag = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cost[i][j] > 1) {
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
		if (flag == -1) break;
		ans++;
	}
	cout << ans << endl;
	return 1;
}
