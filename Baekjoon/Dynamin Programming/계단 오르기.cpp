// ¹®Á¦ : https://www.acmicpc.net/problem/2579
// Botton Up
#include <iostream>
using namespace std;
int S[301];
long long D[301][2];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	D[1][0] = D[1][1] = S[1];
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i][1] = S[i];
		D[i - 2][0] > D[i - 2][1] ? D[i][0] += D[i - 2][0] : D[i][0] += D[i - 2][1];
		D[i][1] += D[i - 1][0];
	}
	D[N][0] > D[N][1] ? cout << D[N][0] : cout << D[N][1];
	return 0;
}