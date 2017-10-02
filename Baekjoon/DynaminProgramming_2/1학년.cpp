// 문제 : https://www.acmicpc.net/problem/5557
// dp - 모든 경우는 2^100이라 시간초과가 되지만, 2차원 배열을 활용해 100 * 21 만에 연산 가능
#include <iostream>
#include <cstring>
using namespace std;
int N;
int cost[101];
unsigned long long dp[101][21];
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> cost[i];
	dp[1][cost[1]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i][j] == 0) continue;
			if (j - cost[i + 1] >= 0) dp[i + 1][j - cost[i + 1]] += dp[i][j];
			if (j + cost[i + 1] <= 20) dp[i + 1][j + cost[i + 1]] += dp[i][j];
		}
	}
	cout << dp[N - 1][cost[N]] << endl;
	return 1;
}