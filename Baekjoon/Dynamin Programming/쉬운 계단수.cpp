// 문제 : https://www.acmicpc.net/problem/10844
// Botton Up 활용
#include <iostream>
using namespace std;
int R[101][10] = { 0, };
int main() {
	int N;
	long long result = 0;
	cin >> N;
	for (int i = 1; i <= 9; i++)R[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) R[i][j] += R[i - 1][j - 1];
			if (j + 1 <= 9) R[i][j] += R[i - 1][j + 1];
			R[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++) result += R[N][i];
	cout << result%1000000000 << endl;
	return 0;
}