// ¹®Á¦ : https://www.acmicpc.net/problem/11049
// dp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 2100000000;
int N, r, c;
pair<int, int> matrix[501];
int dp[501][501];
int go(const int i, const int j) {
	int &ret = dp[i][j];
	if (i == j) return 0;
	if (ret != -1) return ret;
	ret = MAX;
	for (int k = i; k < j; k++) {
		ret = min(ret, go(i, k) + go(k + 1, j) +(matrix[i].first * matrix[k].second * matrix[j].second));
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> r >> c;
		matrix[n] = make_pair(r, c);
	}
	cout << go(1, N) << endl;
	return 1;
}