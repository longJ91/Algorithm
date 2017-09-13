// ¹®Á¦ : https://www.acmicpc.net/problem/2294
// DP
#include <iostream>
using namespace std;
int coin[100];
int dp[10001] = { 0, };
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	
	for (int i = 0; i <= k; i++) dp[i] = -1;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coin[i] >= 0 && dp[j - coin[i]] != -1) {
				if (dp[j] == -1 || dp[j] > dp[j - coin[i]] + 1) {
					dp[j] = dp[j - coin[i]] + 1;
				}
			}
		}
	}
	cout << dp[k];

	return 1;
}