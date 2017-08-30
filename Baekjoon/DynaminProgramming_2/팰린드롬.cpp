// 문제 : https://www.acmicpc.net/problem/10942
// DP (메모리제이션)
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int A[2001];
int DP[2001][2001];
int go(int i, int j) {
	if (i == j) return DP[i][j] = 1;
	if (i + 1 == j) {
		A[i] == A[j] ? DP[i][j] = 1 : DP[i][j] = 0;
		return DP[i][j];
	}
	if (DP[i][j] >= 0) return DP[i][j];
	else if (A[i] != A[j]) return DP[i][j] = 0;
	else {
		DP[i][j] = go(i + 1, j - 1);
		return DP[i][j];
	}
}
int main() {

	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++) scanf("%d",&A[i]);
	cin >> M;
	//전역변수 -1로 초기화
	memset(DP, -1, sizeof(DP));
	int S, E, result;
	for (int i = 1; i <=M; i++) {
		scanf("%d%d", &S,&E);
		result = go(S, E);

		//cout << result << "\n";
		printf("%d\n", result);
	}

	return 1;
}