// 문제 : https://www.acmicpc.net/problem/1509
// DP (이해가 잘 안감)
#include <iostream>
#include <string>
using namespace std;
string str;
int DP[2501][2501];
int result[2501];
int main() {
	
	cin >> str;
	str = " " + str;
	int lenOfStr;
	lenOfStr = str.size();
	for (int i = 1; i <= lenOfStr; i++) DP[i][i] = 1;
	for (int i = 1; i <= lenOfStr - 1; i++) str[i] == str[i + 1] ? DP[i][i + 1] = 1 : DP[i][i + 1] = 0;
	//나머지 부분 채우기
	for (int k = 2; k < lenOfStr; k++) {
		for (int i = 1; i <= lenOfStr - k; i++) {
			int j = i + k;
			DP[i][j] = (str[i] == str[j] && DP[i + 1][j - 1]);
		}
	}
	//min 구하기
	result[0] = 0;
	for (int i = 1; i <= lenOfStr; i++) {
		result[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (DP[j][i]) {
				if (result[i] == -1 || result[i] > result[j - 1] + 1) result[i] = result[j - 1] + 1;
			}
		}
	}
	cout << result[lenOfStr - 1];
	
	return 1;
}