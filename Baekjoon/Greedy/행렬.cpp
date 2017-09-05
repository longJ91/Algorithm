// ¹®Á¦ : https://www.acmicpc.net/problem/1080
// Greedy
#include <iostream>
#include <cstdio>
using namespace std;
int A[50][50];
int B[50][50];
int main() {
	int N, M;

	cin >> N >> M;
	for (int i = 0; i<N; i++) for (int j = 0; j<M; j++) scanf("%1d", &A[i][j]);

	for (int i = 0; i<N; i++) for (int j = 0; j<M; j++) scanf("%1d", &B[i][j]);

	int result = 0;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (A[i][j] != B[i][j]) {
			if (i + 2 < N && j + 2 < M) {
				for (int c = i; c < i + 3; c++) for (int r = j; r < j + 3; r++) {
					A[c][r] == 1 ? A[c][r] = 0 : A[c][r] = 1;
				}
			}
			result++;
		}
	}

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		if (A[i][j] != B[i][j]) {
			result = -1;
			break;
		}
	cout << result;
	return 1;
}