// ¹®Á¦ : https://www.acmicpc.net/problem/11053
// Botton Up
#include <iostream>
using namespace std;
int P[1001];
int D[1001];
int main() {
	int N,max;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) if (P[i] > P[j] && D[j] + 1 > D[i]) D[i] = D[j] + 1;
	}
	max = 0;
	for (int i = 1; i <= N; i++) if (max < D[i]) max = D[i];
	cout << max;
	return 0;
}