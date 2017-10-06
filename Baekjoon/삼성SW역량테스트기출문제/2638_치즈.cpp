// ���� : https://www.acmicpc.net/problem/2638
// �Ｚ sw ���
/* 
(0,0)���� bfs ����
������̸� 1, ġ��� +1 �����ֱ�
��ü ���� ���� cost�� 1 ���� Ŀ�� �κ��� ����� 1�� ����
�ݺ� - ��ü �� üũ�Ҷ�, 1 ���� ū �κ��� �ѱ����� ������ ����
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
