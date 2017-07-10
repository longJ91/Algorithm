// ¹®Á¦ : https://www.acmicpc.net/problem/9658
#include <iostream>
#include <string>
using namespace std;
int dp[1001];//1 SK, -1 CY
int main() {
	int N;
	cin >> N;
	dp[2] = dp[4] = 1;
	dp[1] = dp[3] = -1;
	for (int i = 5; i <= N; i++) {
		int flag = 1;
		if (dp[i - 1] == -1 || dp[i - 3] == -1 || dp[i - 4] == -1) dp[i] = 1;
		else dp[i] = -1;
	}
	string result;
	dp[N] == 1 ? result = "SK" : result = "CY";
	cout << result << endl;
	return 0;
}