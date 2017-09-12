// ¹®Á¦ : https://www.acmicpc.net/problem/2293
// DP
#include <iostream>
using namespace std;
int coin[100];
int dp[10001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];

	return 1;
}