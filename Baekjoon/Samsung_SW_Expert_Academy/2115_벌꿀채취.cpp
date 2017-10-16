#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int test_case, N, M, C;
int map[10][10];
int cost[10][10];
int max_M, max_C;
int result;
void GetMax(const int i, const int j, const int cnt, const int value) {
	if (cnt == 2) {
		max_C = max(max_C, value);
		return;
	}
	for (int a = i; a < N; a++) {
		if (a == i) {
			for (int b = j; b < N; b++) {
				if (cost[a][b] != -1 && a == i && j + M <= b) GetMax(a, b, cnt + 1, value + cost[a][b]);
			}
		}
		else {
			for (int b = 0; b < N; b++) {
				if (cost[a][b] != -1) GetMax(a, b, cnt + 1, value + cost[a][b]);
			}
		}
	}
}
void GetCost(const int i, const int j, const int l, int value, int sum) {
	for (int k = j; k < l; k++) {
		if (value + map[i][k] > C) max_M = max(max_M, sum);
		if (value + map[i][k] <= C && k + 1 >= l) max_M = max(max_M, sum + (map[i][k] * map[i][k]));
		if (value + map[i][k] <= C && k + 1 < l) GetCost(i, k + 1, l, value + map[i][k], sum + (map[i][k] * map[i][k]));
	}
}
int main() {
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		cin >> N >> M >> C;
		memset(map, -1, sizeof(map));
		result = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		memset(cost, -1, sizeof(cost));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j + M <= N) {
					max_M = -1;
					GetCost(i, j, j + M, 0, 0);
					cost[i][j] = max_M;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_C = -1;
				GetMax(i, j, 1, cost[i][j]);
				result = max(result, max_C);
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}