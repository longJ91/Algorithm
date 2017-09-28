// ���� : https://www.acmicpc.net/problem/2306
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
	//"at" or "gc" �� ã��, ã�� �ε��� ���ʰ� �ٱ����� �ٽ� �˻��Ѵ�.
	//���⼭ L(left)�� �̵� �ϹǷ� �ٱ��� �˻�� �����ʸ� �߰��� �˻��Ѵ�.
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