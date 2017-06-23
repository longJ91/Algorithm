// 문제 : https://www.acmicpc.net/problem/11057
// Botton Up 활용
#include <iostream>
using namespace std;
int D[1001][10] = { 0, };
int main() {
	int N;
	long long R = 0;
	cin >> N;
	for (int i = 0; i <= 9; i++) D[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) for (int k = j; k <= 9; k++) D[i][j] = (D[i][j] + D[i - 1][k]) % 10007;
	}
	for (int i = 0; i <= 9; i++) R += D[N][i];
	cout << R % 10007 << endl;
	return 0;
}