// ¹®Á¦ : https://www.acmicpc.net/problem/1495
// dp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, S, M;
int v[101];
int dp[101][1001];
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> v[i];
	if (S - v[1] >= 0) dp[1][S - v[1]] = 1;
	if (S + v[1] <= M) dp[1][S + v[1]] = 1;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i][j] == -1) continue;
			if (j - v[i + 1] >= 0) dp[i + 1][j - v[i + 1]] = 1;
			if (j + v[i + 1] <= M) dp[i + 1][j + v[i + 1]] = 1;
		}
	}
	int ans = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i] == 1) ans = i;
	}
	cout << ans << endl;
	return 1;
}