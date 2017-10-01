// 문제 : https://www.acmicpc.net/problem/2228
// dp
/*
DP

구간을 나눌 때 예를 들어 예제를 살펴보면 6개의 원소 중 2개의 구간을 만들어야 한다.
이때 위의 조건을 만족하면서 합이 최대가 되는 경우는 { -1, 3, 1, 2, 4, -1 } 인 경우이다.

이 문제를 DP로 풀 때
DP[n][m] = n개의 원소들의 집합에서 m개의 구간으로 나누었을 때 합의 최대값

1. i번 째 수를 포함하지 않는 경우
이는 i - 1까지의 원소들의 집합에서 구간 m개를 나눈 합의 최대값과 같다.
-> dp[i][m] =dp[i - 1][m]

2. i번 째 수를 포함하는 경우
i번 째 수를 포함하는 구간이 m번째 구간이 되어야 하며
이전에 m - 1구간을 만들었을 때의 최대값과 합하여야 한다.
이 때, i번째 수를 포함하는 구간의 시작지점이 어디인지를 모른다.
따라서 반복문을 통해 모든 경우를 찾아보고 그 중 최대값을 찾아 합하여 준다.

즉, Max(dp[k - 2][m - 1] + Sum(data[k ~ i])


출처: http://ksj14.tistory.com/entry/BeakJoon2228-구간-나누기 [:: ENJOY ::]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
const int M_MAX = -2000000000;
using namespace std;
int N, M;
int cost[101];
int psum[101];
int cost_dp[101][51];
bool check_dp[101][51];
int go(const int n, const int m) {
	if (m == 0) return 0;
	if (n < 0) return M_MAX;
	int &ret = cost_dp[n][m];
	if (check_dp[n][m]) return ret;
	check_dp[n][m] = true;
	ret = go(n - 1, m);
	for (int i = n; i > 0; i--) {
		int temp = go(i - 2, m - 1) + psum[n] - psum[i - 1];
		ret = max(ret, temp);
	}
	return ret;
}
int main() {
	cin >> N >> M;
	psum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		psum[i] = psum[i - 1] + cost[i];
	}
	cout << go(N, M) << endl;
	return 1;
}