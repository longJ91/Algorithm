// ¹®Á¦ : https://www.acmicpc.net/problem/9465
// Botton Up
#include <iostream>
using namespace std;
int D[100001][3] = { 0, };
int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) cin >> D[j][1];
		for (int j = 1; j <= N; j++) cin >> D[j][2];
		for (int j = 2; j <= N; j++) {
			D[j - 1][2] > D[j - 2][2] ? D[j][1] += D[j - 1][2] : D[j][1] += D[j - 2][2];
			D[j - 1][1] > D[j - 2][1] ? D[j][2] += D[j - 1][1] : D[j][2] += D[j - 2][1];
		}
		D[N][1] > D[N][2] ? cout << D[N][1] << "\n" : cout << D[N][2] << "\n";
	}
	return 0;
}