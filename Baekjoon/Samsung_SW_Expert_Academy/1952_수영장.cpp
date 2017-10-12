#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int test_case;
int cost[4];
int day[12];
int dp[12][3];
int ans;
int main() {
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		memset(dp, -1, sizeof(dp));
		ans = 987654321;
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> day[i];
		}
		for (int i = 0; i < 12; i++) {
			if (i == 0) {
				dp[0][0] = cost[0] * day[0];
				dp[0][1] = cost[1];
				dp[0][2] = cost[2];
			}
			else if (i == 1) {
				dp[1][0] = min(dp[0][0], dp[0][1]) + (cost[0] * day[1]);
				dp[1][1] = min(dp[0][0], dp[0][1]) + cost[1];
				dp[1][2] = min(dp[0][0], dp[0][1]) + cost[2];
			}
			else if (i == 2) {
				dp[2][0] = min(dp[1][0], dp[1][1]) + (cost[0] * day[2]);
				dp[2][1] = min(dp[1][0], dp[1][1]) + cost[1];
				dp[2][2] = min(dp[1][0], dp[1][1]) + cost[2];
			}
			else {
				dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 3][2]) + (cost[0] * day[i]);
				dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 3][2]) + cost[1];
				dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 3][2]) + cost[2];
			}
		}
		for (int k = 0; k < 3; k++) {
			ans = min(ans, dp[11][k]);
		}
		ans = min(ans, dp[10][2]);
		ans = min(ans, dp[9][2]);
		ans = min(ans, cost[3]);
		cout << "#" << t + 1 << " " << ans << "\n";
	}
	return 1;
}