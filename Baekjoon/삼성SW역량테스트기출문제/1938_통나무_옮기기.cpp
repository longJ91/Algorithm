// 문제 : https://www.acmicpc.net/problem/1938
// 전체 조건 2가지(상태) * 5가지(이동 방법) = 10 가지를 생각하며 완전 탐색
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans;
int map[50][50];
//3차원 위치 값 의미   0 - v, 1- h
int cost[50][50][2];
pair<int, int> finish_center, start_center;
char log_state, finish_state;
void find(const char state, const pair<int, int> log_center, const int cnt) {
	//base case
	if (state == finish_state && log_center.first == finish_center.first && log_center.second == finish_center.second) {
		ans = min(ans, cnt);
		return;
	}
	int i, j;
	i = log_center.first;
	j = log_center.second;
	//10 가지 move
	//세로
	if (state == 'v') {
		//up
		if (i - 2 >= 0 && map[i - 2][j] == 0) {
			if (cost[i - 1][j][0] == -1) {
				cost[i - 1][j][0] = cnt + 1;
				find(state, make_pair(i - 1, j), cnt + 1);
			}
			else {
				if (cost[i - 1][j][0] > cnt + 1) {
					cost[i - 1][j][0] = cnt + 1;
					find(state, make_pair(i - 1, j), cnt + 1);
				}
			}
		}
		//down
		if (i + 2 < N && map[i + 2][j] == 0) {
			if (cost[i + 1][j][0] == -1) {
				cost[i + 1][j][0] = cnt + 1;
				find(state, make_pair(i + 1, j), cnt + 1);
			}
			else {
				if (cost[i + 1][j][0] > cnt + 1) {
					cost[i + 1][j][0] = cnt + 1;
					find(state, make_pair(i + 1, j), cnt + 1);
				}
			}
		}
		//left
		if (j - 1 >= 0 && map[i][j - 1] == 0 && map[i - 1][j - 1] == 0 && map[i + 1][j - 1] == 0) {
			if (cost[i][j - 1][0] == -1) {
				cost[i][j - 1][0] = cnt + 1;
				find(state, make_pair(i, j - 1), cnt + 1);
			}
			else {
				if (cost[i][j - 1][0] > cnt + 1) {
					cost[i][j - 1][0] = cnt + 1;
					find(state, make_pair(i, j - 1), cnt + 1);
				}
			}
		}
		//right
		if (j + 1 < N && map[i][j + 1] == 0 && map[i - 1][j + 1] == 0 && map[i + 1][j + 1] == 0) {
			if (cost[i][j + 1][0] == -1) {
				cost[i][j + 1][0] = cnt + 1;
				find(state, make_pair(i, j + 1), cnt + 1);
			}
			else {
				if (cost[i][j + 1][0] > cnt + 1) {
					cost[i][j + 1][0] = cnt + 1;
					find(state, make_pair(i, j + 1), cnt + 1);
				}
			}
		}
		//rotation
		if (j - 1 >= 0 && map[i][j - 1] == 0 && map[i - 1][j - 1] == 0 && map[i + 1][j - 1] == 0 && j + 1 < N && map[i][j + 1] == 0 && map[i - 1][j + 1] == 0 && map[i + 1][j + 1] == 0) {
			if (cost[i][j][1] == -1) {
				cost[i][j][1] = cnt + 1;
				find('h', make_pair(i, j), cnt + 1);
			}
			else {
				if (cost[i][j][1] > cnt + 1) {
					cost[i][j][1] = cnt + 1;
					find('h', make_pair(i, j), cnt + 1);
				}
			}
		}
	}
	//가로
	else{
		//up
		if (i - 1 >= 0 && map[i - 1][j] == 0 && map[i - 1][j - 1] == 0 && map[i - 1][j + 1] == 0) {
			if (cost[i - 1][j][1] == -1) {
				cost[i - 1][j][1] = cnt + 1;
				find(state, make_pair(i - 1, j), cnt + 1);
			}
			else {
				if (cost[i - 1][j][1] > cnt + 1) {
					cost[i - 1][j][1] = cnt + 1;
					find(state, make_pair(i - 1, j), cnt + 1);
				}
			}
		}
		//down
		if (i + 1 < N && map[i + 1][j] == 0 && map[i + 1][j - 1] == 0 && map[i + 1][j + 1] == 0) {
			if (cost[i + 1][j][1] == -1) {
				cost[i + 1][j][1] = cnt + 1;
				find(state, make_pair(i + 1, j), cnt + 1);
			}
			else {
				if (cost[i + 1][j][1] > cnt + 1) {
					cost[i + 1][j][1] = cnt + 1;
					find(state, make_pair(i + 1, j), cnt + 1);
				}
			}
		}
		//left
		if (j - 2 >= 0 && map[i][j - 2] == 0) {
			if (cost[i][j - 1][1] == -1) {
				cost[i][j - 1][1] = cnt + 1;
				find(state, make_pair(i, j - 1), cnt + 1);
			}
			else {
				if (cost[i][j - 1][1] > cnt + 1) {
					cost[i][j - 1][1] = cnt + 1;
					find(state, make_pair(i, j - 1), cnt + 1);
				}
			}
		}
		//right
		if (j + 2 < N && map[i][j + 2] == 0) {
			if (cost[i][j + 1][1] == -1) {
				cost[i][j + 1][1] = cnt + 1;
				find(state, make_pair(i, j + 1), cnt + 1);
			}
			else {
				if (cost[i][j + 1][1] > cnt + 1) {
					cost[i][j + 1][1] = cnt + 1;
					find(state, make_pair(i, j + 1), cnt + 1);
				}
			}
		}
		//rotation
		if (i - 1 >= 0 && map[i - 1][j] == 0 && map[i - 1][j - 1] == 0 && map[i - 1][j + 1] == 0 && i + 1 < N && map[i + 1][j] == 0 && map[i + 1][j - 1] == 0 && map[i + 1][j + 1] == 0) {
			if (cost[i][j][0] == -1) {
				cost[i][j][0] = cnt + 1;
				find('v', make_pair(i, j), cnt + 1);
			}
			else {
				if (cost[i][j][0] > cnt + 1) {
					cost[i][j][0] = cnt + 1;
					find('v', make_pair(i, j), cnt + 1);
				}
			}
		}
	}
}
int main() {
	memset(cost, -1, sizeof(cost));
	cin >> N;
	string str;
	vector<pair<int, int> > finish_set, start_set;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == '1') map[i][j] = 1;
			else {
				map[i][j] = 0;
				if (str[j] == 'B') {
					start_set.push_back(make_pair(i, j));
				}
				if (str[j] == 'E') {
					finish_set.push_back(make_pair(i, j));
				}
			}
		}
	}
	//시작, 도착 지점의 중심
	start_center = start_set[1];
	finish_center = finish_set[1];
	//통나무 상태, v - 세로, h - 가로
	if (start_set[0].first == start_set[1].first) log_state = 'h';
	else log_state = 'v';
	if (finish_set[0].first == finish_set[1].first) finish_state = 'h';
	else finish_state = 'v';
	//최소비용 초기화 및 구하기
	ans = 2000000000;
	if (log_state == 'v') cost[start_center.first][start_center.second][0] = 0;
	else cost[start_center.first][start_center.second][1] = 0;
	find(log_state, start_center, 0);
	if (ans == 2000000000) ans = 0;
	cout << ans << endl;
	return 1;
}