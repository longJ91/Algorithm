// 문제 : https://www.acmicpc.net/problem/9251
// dp - 가장 기본적인 Longest Common Subsequence (LCS) 문제
// 2차원 배열을 통해서 하나의 문자열을 고정 시키고, 나머지 하나의 문자열을 하나씩 보며 고정 시킨 문자열과 비교하며 결과를 도출
#include <iostream>
#include <string>
using namespace std;
int dp[1002][1002];
int max(const int a, const int b) {
	if (a > b) return a;
	return b;
}
int main() {
	string str1, str2;
	str1 = " ";
	str2 = " ";
	string temp;
	cin >> temp;
	str1 += temp;
	cin >> temp;
	str2 += temp;
	int len1 = str1.size(), len2 = str2.size();
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (str1.at(i) == str2.at(j)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i-1][j-1]);
				}
			}
		}
	}
	cout << dp[len1 - 1][len2 - 1] << endl;
	return 1;
}