// 문제 : https://www.acmicpc.net/problem/12026
// dp - N 이 최대가 1000이고, 시간 복잡도 O(n^2) 로 가능
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int N;
int dp[1001];
string str = " ", temp;
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> temp;
	str += temp;
	dp[1] = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] != -1) {
			for (int j = i + 1; j <= N; j++) {
				if (str[i] == 'B') {
					if (str[j] == 'O') {
						if (dp[j] == -1) dp[j] = dp[i] + ((i - j)*(i - j));
						else dp[j] = min(dp[j], dp[i] + ((i - j)*(i - j)));
					}
				}
				else if (str[i] == 'O') {
					if (str[j] == 'J') {
						if (dp[j] == -1) dp[j] = dp[i] + ((i - j)*(i - j));
						else dp[j] = min(dp[j], dp[i] + ((i - j)*(i - j)));
					}
				}
				else if (str[i] == 'J') {
					if (str[j] == 'B') {
						if (dp[j] == -1) dp[j] = dp[i] + ((i - j)*(i - j));
						else dp[j] = min(dp[j], dp[i] + ((i - j)*(i - j)));
					}
				}
			}
		}
	}
	cout << dp[N] << endl;
	return 1;
}