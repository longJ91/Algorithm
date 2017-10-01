// 문제 : https://www.acmicpc.net/problem/2240
// dp
// 한번에 품!
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, W;
int info[1001];
int dp[1001][31][3];
int go(const int t, const int w, const int tree) {
	if (t == 0) return 0;
	if (w < 0) return 0;
	int &ret = dp[t][w][tree];
	if (ret != -1) return ret;
	if (info[t] == 1) {
		if (tree == 1) ret = max(go(t - 1, w, 1), go(t - 1, w - 1, 2)) + 1;
		else ret = max(go(t - 1, w, 2), go(t - 1, w - 1, 1));
	}
	else {
		if (tree == 1) ret = max(go(t - 1, w, 1), go(t - 1, w - 1, 2));
		else ret = max(go(t - 1, w, 2), go(t - 1, w - 1, 1)) + 1;
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> info[i];
	}
	if (info[1] == 1) {
		dp[1][W][1] = 1;
		dp[1][W - 1][2] = 0;
	}
	else {
		dp[1][W][1] = 0;
		dp[1][W - 1][2] = 1;
	}
	cout << max(go(T, W, 1),go(T, W, 2)) << endl;
	return 1;
}