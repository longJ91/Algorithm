// ¹®Á¦ : https://www.acmicpc.net/problem/2193
// Botton Up
#include <iostream>
using namespace std;
long long D[91][2] = { 0, };
int main() {
	int N;
	cin >> N;
	D[1][0] = 0;
	D[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i][0] += D[i - 1][1] + D[i - 1][0];
		D[i][1] += D[i - 1][0];
	}
	cout << D[N][0] + D[N][1] << endl;
	return 0;
}