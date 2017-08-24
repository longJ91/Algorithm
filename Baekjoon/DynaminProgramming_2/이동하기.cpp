// 문제 : https://www.acmicpc.net/problem/11048
// DP

#include<iostream>
using namespace std;
int numberOfCandy[1001][1001];
int getOfMax(const int A, const int B, const int C) {
	int result;
	A > B ? result = A : result = B;
	C > result ? result = C : 0;
	return result;
}
int main() {

	int N, M;
	cin >> N >> M;
	int tempOfCandy;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
		cin >> tempOfCandy;
		numberOfCandy[i][j] = tempOfCandy;
	}
	int upOfCandy, leftOfCandy, diagonalLineOfCandy;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			diagonalLineOfCandy = upOfCandy = leftOfCandy = 0;
			//위
			if (i - 1 >= 1) upOfCandy = numberOfCandy[i - 1][j];
			//왼쪽
			if (j - 1 >= 1) leftOfCandy = numberOfCandy[i][j - 1];
			//대각선
			if (i - 1 >= 1 && j - 1 >= 1) diagonalLineOfCandy = numberOfCandy[i - 1][j - 1];

			numberOfCandy[i][j] += getOfMax(upOfCandy, leftOfCandy, diagonalLineOfCandy);
		}
	}

	cout << numberOfCandy[N][M];
	return 0;
}