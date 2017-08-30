// ¹®Á¦ : https://www.acmicpc.net/problem/1890
// DP
#include <iostream>
using namespace std;
int map[101][101];
unsigned long dp[101][101] = { 0, };
int main() {

	int N, value;
	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> map[i][j];
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == 0) continue;
			if (i == N && j == N) break;
			//right
			if (j + map[i][j] <= N) dp[i][j + map[i][j]] += dp[i][j];
			//down
			if (i + map[i][j] <= N) dp[i + map[i][j]][j] += dp[i][j];
		}
	}
	
	cout << dp[N][N];

	return 1;
}