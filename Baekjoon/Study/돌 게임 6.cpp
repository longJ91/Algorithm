// 문제 : https://www.acmicpc.net/problem/9660
// 7개를 기준으로 계속 반복됨
#include <iostream>
#include <string>
using namespace std;
int dp[1001];//1 SK, -1 CY
int main() {
	unsigned long long N;
	cin >> N;
	dp[1] = dp[3] = dp[4] = 1;
	dp[2] = -1;
	for (int i = 5; i <= 15; i++) {
		int flag = 1;
		if (dp[i - 1] == -1 || dp[i - 3] == -1 || dp[i - 4] == -1) dp[i] = 1;
		else dp[i] = -1;
	}
	int temp = (N - 2) % 7;
	temp += 2;
	string result;
	dp[temp] == 1 ? result = "SK" : result = "CY";
	cout << result << endl;
	return 0;
}