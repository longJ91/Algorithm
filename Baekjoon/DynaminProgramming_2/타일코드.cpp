// 문제 : https://www.acmicpc.net/problem/1720
// dp
// 전체 경우의 수 중에 좌우 대칭 제외한 경우는 2개씩 존재함.
// (전체 + 좌우대칭 수) / 2 를 해주면 각각 2개씩 존재하던 중복이 제거됨
#include <iostream>
using namespace std;
int N;
unsigned long all[31];
unsigned long dp[31];
int main() {
	cin >> N;
	all[1] = 1;
	all[2] = 3;
	for (int i = 3; i <= N; i++) all[i] = all[i - 1] + (all[i - 2] * 2);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		unsigned long temp;
		if (!(i & 1)) temp = all[i / 2] + (all[(i - 2) / 2] * 2);
		else temp = all[(i - 1) / 2];
		dp[i] = (all[i] + temp) / 2;
	}
	cout << dp[N] << endl;
	return 1;
}