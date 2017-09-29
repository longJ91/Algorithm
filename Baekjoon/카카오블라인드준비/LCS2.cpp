// ¹®Á¦ : https://www.acmicpc.net/problem/9252
// dp - LCS2
#include <iostream>
#include <string>
using namespace std;
int dp[2][1002];
string str_dp[2][1002];
int max(const int &a, const int &b) {
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
			int index = i % 2;
			if (i == 0 || j == 0) {
				dp[index][j] = 0;
				str_dp[index][j] = "";
			}
			else {
				if (index == 0) {
					if (str1.at(i) == str2.at(j)) {
						dp[0][j] = dp[1][j - 1] + 1;
						str_dp[0][j] = str_dp[1][j - 1] + str1.at(i);
					}
					else {
						dp[0][j] = max(dp[0][j - 1], dp[1][j]);
						if (dp[0][j - 1] > dp[1][j]) {
							str_dp[0][j] = str_dp[0][j - 1];
						}
						else {
							str_dp[0][j] = str_dp[1][j];
						}
					}
				}
				else {
					if (str1.at(i) == str2.at(j)) {
						dp[1][j] = dp[0][j - 1] + 1;
						str_dp[1][j] = str_dp[0][j - 1] + str1.at(i);
					}
					else {
						dp[1][j] = max(dp[1][j - 1], dp[0][j]);
						if (dp[1][j - 1] > dp[0][j]) {
							str_dp[1][j] = str_dp[1][j - 1];
						}
						else {
							str_dp[1][j] = str_dp[0][j];
						}
					}
				}
			}
		}
	} 
	if (len1 % 2 == 1) {
		cout << dp[0][len2 - 1] << "\n" << str_dp[0][len2 - 1] << endl;
	}
	else {
		cout << dp[1][len2 - 1] << "\n" << str_dp[1][len2 - 1] << endl;
	}
	return 1;
}