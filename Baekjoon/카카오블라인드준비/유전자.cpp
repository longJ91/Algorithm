// 문제 : https://www.acmicpc.net/problem/2306
// dp
/*
https://github.com/kks227/BOJ/blob/master/2300/2306.cpp
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string str;
int dp[500][501], len;
int go(const int L, const int R) {
	if (L == len) return 0;
	if (L == R) return 0;
	int &result = dp[L][R];
	if (result != -1) return result;

	result = go(L+ 1, R);
	//"at" or "gc" 를 찾고, 찾은 인덱스 안쪽과 바깥쪽을 다시 검사한다.
	//여기서 L(left)만 이동 하므로 바깥쪽 검사시 오른쪽만 추가로 검사한다.
	if (str[L] == 'a') {
		for (int i = L + 1; i<R; i++)
			if (str[i] == 't') result = max(result, go(L + 1, i) + go(i + 1, R) + 2);
	}
	else if (str[L] == 'g') {
		for (int i = L + 1; i<R; i++)
			if (str[i] == 'c') result = max(result, go(L + 1, i) + go(i + 1, R) + 2);
	}
	return result;
}
int main() {
	cin >> str;
	len = str.size();
	memset(dp, -1, sizeof(dp));
	cout << go(0, len) << endl;
	return 1;
}