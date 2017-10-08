// 문제 : https://www.acmicpc.net/problem/14728
// 삼성 sw 대비
/*
0-1 Knapsack 알고리즘
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, t, k, s, d[10001];
int main() {
	cin >> n >> t;
	while (n--) {
		cin >> k >> s;
		for (int i = t; i >= k; i--)
			d[i] = max(d[i], d[i - k] + s);
	}
	printf("%d\n", d[t]);
	return 0;
}