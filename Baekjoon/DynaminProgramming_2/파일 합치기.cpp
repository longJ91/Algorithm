// ¹®Á¦ : https://www.acmicpc.net/problem/11066
// dp
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 2100000000;
using namespace std;
int test_case, K, result;
int file[501];
int psum[501];
int dp[501][501];
int go(const int i, const int j) {
	int &ret = dp[i][j];
	if (j == i) return 0;
	if (ret != -1) return ret;
	ret = MAX;
	for (int k = i; k <= j; k++) {
		ret = min(ret, go(i, k) + go(k + 1, j) + psum[j] - psum[i - 1]);
	}
	return ret;
}
int main() {
	
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		cin >> K;
		memset(dp, -1, sizeof(dp));
		memset(psum, 0, sizeof(psum));
		for (int i = 1; i <= K; i++) {
			cin >> file[i];
			if (i == 1) psum[1] = file[i];
			else psum[i] = psum[i - 1] + file[i];
		}
		
		cout << go(1, K) << "\n";
	}
	return 1;
}