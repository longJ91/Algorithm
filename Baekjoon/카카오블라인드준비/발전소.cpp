// ���� : https://www.acmicpc.net/problem/1102
// dp + bitmask
// ��Ʈ ����ũ�ΰ� ��� �����ϴٰ� �ƴ��� �˾Ҵµ�, ���� ��Ʈ����ũ�� �� �ٷ��� ���ؼ� �׷�������.
// reference - http://js1jj2sk3.tistory.com/42
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#define MAX 200000000;
using namespace std;
int n, p;
int cost[16][16];
int dp[1 << 16];
int min(const int a, const int b) {
	if (a > b) return b;
	return a;
}
int solve(int cnt, int state) {
	if (cnt == p) return 0;

	//int& result = dp[state];

	if (dp[state] != -1) return dp[state];

	int result = MAX;

	for (int from = 0; from < n; from++) {
		//���� on �� ������ �� ���
		if (state & (1 << from)) {
			for (int to = 0; to < n; to++) {
				//�ڱ� �ڽ� ������ �� ���
				if (from == to) continue;
				//���� off �� ������ �� ���
				if ( (state & (1 << to)) == 0) {
					result = min(result, solve(cnt + 1, state | (1 << to)) + cost[from][to]);
				}
			}
		}
	}
	dp[state] = result;
	return result;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	string str;
	cin >> str >> p;
	int init = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str.at(i) == 'Y') {
			init = init | (1 << i);
			cnt++;
		}
	}
	
	if (cnt == 0) {
		if (p == 0) cout << 0;
		else cout << -1;
	}
	else if (p <= cnt) cout << 0;
	else {
		cout << solve(cnt, init);
	}

	return 1;
}