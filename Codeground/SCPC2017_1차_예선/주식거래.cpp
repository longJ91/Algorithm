//DP
#include <iostream>

using namespace std;
#define MAX 1000000001
int Answer;
unsigned long dp[200001][2];
unsigned long cost[200001][2];
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	int N;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		int now;
		for (int i = 1; i <= N; i++) {
			cin >> now;
			//초기값
			if (i == 1) {
				dp[i][0] = 0;
				cost[i][0] = MAX;
				dp[i][1] = 1;
				cost[i][1] = now;
				continue;
			}
			//현재 주식 없다
			if (cost[i - 1][1] < now) {
				dp[i][0] = dp[i - 1][1] + 1;
				cost[i][0] = now;
			}
			else {
				dp[i][0] = dp[i - 1][0];
				cost[i][0] = cost[i - 1][0];
			}
			//현재 주식 있다
			if (cost[i - 1][0] > now) {
				dp[i][1] = dp[i - 1][0] + 1;
				cost[i][1] = now;
			}else {
				dp[i][1] = dp[i - 1][1];
				cost[i][1] = cost[i - 1][1];
			}
			
		}
		dp[N][0] > dp[N][1] ? Answer = dp[N][0] : Answer = dp[N][1];
		if (Answer % 2 == 1) Answer--;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		for (int i = 0; i <= N; i++) dp[i][0] = dp[i][1] = cost[i][0] = cost[i][1] = 0;

	}

	return 0;//Your program should return 0 on normal termination.
}