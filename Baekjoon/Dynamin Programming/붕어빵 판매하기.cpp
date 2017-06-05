// ¹®Á¦ : https://www.acmicpc.net/problem/11052
// Use Dynamic Programming(Botton Up)
#include <iostream>
using namespace std;
int D[1001];
int P[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) {
		D[i] = P[i];
		for (int j = 1; j < i; j++) if (D[i] < D[i - j] + P[j]) D[i] = D[i - j] + P[j];
	}
	cout << D[N] << endl;
	return 0;
}