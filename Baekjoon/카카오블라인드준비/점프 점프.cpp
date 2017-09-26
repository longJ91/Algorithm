// ¹®Á¦ : https://www.acmicpc.net/problem/11060
// dp
#include <iostream>
#include <vector>
using namespace std;
int jump[1001];
int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) cin >> jump[i];
	for (int i = 1; i <= n; i++) {
		if (dp[i] != -1) {
			for (int j = 1; j <= jump[i]; j++) {
				if (i + j > n) break;
				if (dp[i + j] == -1) dp[i + j] = dp[i] + 1;
				else dp[i + j] > dp[i] + 1 ? dp[i + j] = dp[i] + 1 : 0;
			}
		}
	}
	cout << dp[n] << endl;
	return 1;
}