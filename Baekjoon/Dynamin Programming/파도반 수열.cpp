// 문제 : https://www.acmicpc.net/problem/9461
// Botton Up, 규칙 찾기
#include <iostream>
using namespace std;
long long P[101];
int main() {
	int T,N;
	cin >> T;
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N < 6) {
			cout << P[N] << "\n";
			continue;
		}
		else {
			for (int j = 1; j <= N; j++) {
				if (P[j] > 0) continue;
				P[j] = P[j - 1] + P[j - 5];
			}
			cout << P[N] << "\n";
		}
	}
	return 0;
}