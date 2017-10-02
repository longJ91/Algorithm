// 문제 : https://www.acmicpc.net/problem/3055
// 삼성 sw 대비
// BFS + 주어진 조건 구현
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int R, C;
char map[50][50];
bool map_check[50][50];
//순서 - 상 하 좌 우
int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, -1, 1 };
pair<int, int> finish;
queue< pair<int, int> > avoid, water;
bool range_check(const int x, const int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}
int main() {
	memset(map_check, false, sizeof(map_check));
	cin >> R >> C;
	string str;
	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			if (str[j] == '.') map[i][j] = '.';
			else if (str[j] == 'X') {
				map[i][j] = 'X';
				map_check[i][j] = true;
			}
			else if (str[j] == '*') {
				map[i][j] = '*';
				water.push(make_pair(i, j));
				map_check[i][j] = true;
			}
			else if (str[j] == 'D') {
				map[i][j] = 'D';
				finish = make_pair(i, j);
			}
			else if (str[j] == 'S') {
				map[i][j] = '.';
				avoid.push(make_pair(i, j));
				map_check[i][j] = true;
			}
		}
	}
	int avoid_size = 1, ret = 0, flag = -1;
	while (avoid_size != 0) {
		pair<int, int> avoid_check = avoid.front();
		int water_size = water.size();
		//물 채우기
		for (int i = 0; i < water_size; i++) {
			pair<int, int> water_now = water.front();
			water.pop();
			for (int k = 0; k < 4; k++) {
				int cx = water_now.first + move_x[k];
				int cy = water_now.second + move_y[k];
				if (range_check(cx, cy) && map[cx][cy] == '.') {
					map[cx][cy] = '*';
					water.push(make_pair(cx, cy));
				}
			}
		}
		//이동
		ret++;
		int move_size = avoid.size();
		for (int i = 0; i < move_size; i++) {
			pair<int, int> avoid_now = avoid.front();
			avoid.pop(); avoid_size--;
			for (int k = 0; k < 4; k++) {
				int cx = avoid_now.first + move_x[k];
				int cy = avoid_now.second + move_y[k];
				if (range_check(cx, cy) && map_check[cx][cy] == false && (map[cx][cy] == '.' || map[cx][cy] == 'D')) {
					map_check[cx][cy] = true;
					avoid.push(make_pair(cx, cy));
					avoid_size++;
					if (map[cx][cy] == 'D') {
						k = 4;
						i = move_size;
						avoid_size = 0;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag == 1) cout << ret << endl;
	else cout << "KAKTUS" << endl;
	return 1;
}