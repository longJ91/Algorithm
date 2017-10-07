// 문제 : https://www.acmicpc.net/problem/1937
// 삼성 sw 대비
/*
대나무 숲의 크기가 최대 25만개 존재
25만개 위치에서 모든 오름차순 bfs를 하면 답은 출력 가능
하지만 중복되는 부분이 너무 많음
중복을 제거하기 위해서 대나무 양을 특정 배열에 저정하고 내림차순으로 정렬한다
dp 를 통해 중복을 제거하며 결과 구하기
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct bamboo {
	bamboo(int X, int Y, int V) {
		x = X;
		y = Y;
		v = V;
	}
	int x, y, v;
};
bool cmp(const bamboo &a, const bamboo &b) {
	return a.v < b.v;
}
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };
int map[500][500];
int cost[500][500];
int n, ans;
int main() {
	memset(cost, -1, sizeof(cost));
	cin >> n;
	vector<bamboo> bamboo_set;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			bamboo_set.push_back(bamboo(i,j, map[i][j]));
		}
	}
	sort(bamboo_set.begin(), bamboo_set.end(), cmp);
	//대나무 양 많은 위치부터 bfs
	ans = 0;
	int set_size = n*n, cx, cy;
	for (int i = 0; i < set_size; i++) {
		bamboo temp = bamboo_set[i];
		int max = 0;
		for (int m = 0; m < 4; m++) {
			cx = temp.x + move_x[m]; cy = temp.y + move_y[m];
			if (cx >= 0 && cx < n && cy >= 0 && cy < n) {
				if (map[cx][cy] < temp.v && cost[cx][cy] > max) {
					max = cost[cx][cy];
				}
			}
		}
		cost[temp.x][temp.y] = max + 1;
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			ans = max(ans, cost[a][b]);
		}
	}
	cout << ans << endl;
	return 1;
}