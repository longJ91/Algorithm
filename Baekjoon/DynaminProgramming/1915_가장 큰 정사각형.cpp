// ¹®Á¦ : https://www.acmicpc.net/problem/1915
// dp
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int dp[2][1000];
int ans;
int main() {
	cin >> n >> m;
	string str;
	ans = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				if (str[j] == '1') {
					dp[0][j] = 1;
					ans = 1;
				}
			}
			else {
				if (i & 1) {
					if (j == 0) {
						if (str[j] == '1') dp[1][j] = 1;
						else dp[1][j] = 0;
					}
					else {
						if (str[j] == '1') {
							dp[1][j] = 1 + (min(min(dp[1][j - 1], dp[0][j]), dp[0][j - 1]));
						}
						else {
							dp[1][j] = 0;
						}
					}
					ans = max(ans, dp[1][j]);
				}
				else {
					if (j == 0) {
						if (str[j] == '1') dp[0][j] = 1;
						else dp[0][j] = 0;
					}
					else {
						if (str[j] == '1') {
							dp[0][j] = 1 + (min(min(dp[0][j - 1], dp[1][j]), dp[1][j - 1]));
						}
						else {
							dp[0][j] = 0;
						}
					}
					ans = max(ans, dp[0][j]);
				}
			}
		}
	}
	cout << ans*ans << endl;
	return 1;
}