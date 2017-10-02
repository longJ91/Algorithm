// 문제 : https://www.acmicpc.net/problem/2418
// dp - 2차원 배열을 통해서 해결
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int H, W, L;
string str;
long long ans = 0;
char map[200][200];
int move_x[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int move_y[8] = {0, 0, -1, 1, -1, 1, 1, -1};
long long dp[200][200];
int main() {
	cin >> H >> W >> L;
	vector< pair<int, int> > start;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < H; i++) {
		cin >> str;
		for (int j = 0; j < W; j++) {
			map[i][j] = str[j];
		}
	}
	cin >> str;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == str[0]) dp[i][j] = 1;
		}
	}
	int str_size = str.size();
	for (int k = 1; k < str_size; k++) {
		long long temp_dp[200][200];
		memset(temp_dp, 0, sizeof(temp_dp));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (str[k] == map[i][j]) {
					long long temp = 0;
					for (int m = 0; m < 8; m++) {
						int cx = i + move_x[m];
						int cy = j + move_y[m];
						if (cx >= 0 && cx < H && cy >= 0 && cy < W) {
							temp += dp[cx][cy];
						}
					}
					temp_dp[i][j] = temp;
				}
			}
		}
		memcpy(dp, temp_dp, sizeof(dp));
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
	return 1;
}